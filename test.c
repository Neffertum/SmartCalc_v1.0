#include <check.h>
#include <math.h>

#include "polish.h"
#include "stack.h"

void startTest(void);

int main(void) {
  startTest();
  return 0;
}

START_TEST(myTest_1) {
  double x = 0;
  char *my_str = "-45.2114+14.0";
  double res = -45.2114 + 14.0;
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_2) {
  double x = 235.134;
  char *my_str = "cos(x)";
  double res = cos(x);
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_3) {
  double x = 0;
  char *my_str = "atan(12)";
  double res = atan(12);
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_4) {
  double x = -235.012;
  char *my_str = "cos(x)+(-124mod124.46)";
  double res = cos(x) + fmod(-124, 124.46);
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_5) {
  double x = -235.012;
  char *my_str = "36/0.1244";
  double res = 36 / 0.1244;
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_6) {
  double x = 124124.03105;
  char *my_str = "sin(x)-ln(x)";
  double res = sin(x) - log(x);
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_7) {
  double x = 124;
  char *my_str = "5235.1*sin(5-(124^15.15155))";
  double res = 5235.1 * sin(5 - pow(124, 15.15155));
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_8) {
  double x = 0.21455;
  char *my_str = "-tan(x)-(-0+log(x))";
  double res = -tan(x) - (-0 + log10(x));
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_9) {
  double x = 0.21455;
  char *my_str = "+(-14)";
  double res = +(-14);
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_10) {
  double x = -13515667.12515;
  char *my_str = "acos(x)/x";
  double res = acos(x) / x;
  double my_res = polish(my_str, x);
  int res_flag = 0;
  int myres_flag = 0;
  if (res == NAN) {
    res_flag = 1;
  }
  if (my_res == NAN) {
    myres_flag = 1;
  }
  ck_assert_int_eq(res_flag, myres_flag);
}
END_TEST

START_TEST(myTest_11) {
  double x = 0.21455;
  char *my_str = "-46-(+266714.241*asin(-0.15))";
  double res = -46 - (+266714.241 * asin(-0.15));
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_12) {
  double x = 257781425.12;
  char *my_str = "xmodatan(0.12356)";
  double res = fmod(x, atan(0.12356));
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_13) {
  double x = 257781425.12;
  char *my_str = "(x+(136236*x^0.124/(1551-(12356-0.1637458))))";
  double res = (x + (136236 * pow(x, 0.124) / (1551 - (12356 - 0.1637458))));
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_14) {
  double x = 257781425.12;
  char *my_str = "sin(x)-cos(x)*tan(x)";
  double res = sin(x) - cos(x) * tan(x);
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_15) {
  double x = 0.12516247;
  char *my_str = "-ln(x)-(-log(x))";
  double res = -log(x) - (-log10(x));
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_16) {
  double x = 0.12516247;
  char *my_str = "1513-236263+23626*213592.23264/0.12516";
  double res = 1513 - 236263 + 23626 * 213592.23264 / 0.12516;
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_17) {
  double x = -125;
  char *my_str = "sqrt(x)+(+9+155123.2366)";
  double res = sqrt(x) + (+9 + 155123.2366);
  double my_res = polish(my_str, x);
  int res_flag = 0;
  int myres_flag = 0;
  if (res == NAN) {
    res_flag = 1;
  }
  if (my_res == NAN) {
    myres_flag = 1;
  }
  ck_assert_int_eq(res_flag, myres_flag);
}
END_TEST

START_TEST(myTest_18) {
  double x = 125;
  char *my_str = "sqrt(x)+(+9+155123.2366)";
  double res = sqrt(x) + (+9 + 155123.2366);
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_19) {
  double x = 125;
  char *my_str = "-(-(-(-(-2346))))";
  double res = -(-(-(-(-2346))));
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_20) {
  double x = 125;
  char *my_str = "+(+(+(+x)))";
  double res = +(+(+(+x)));
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

START_TEST(myTest_21) {
  double x = 125;
  char *my_str = "sqrt(sin(x-31))";
  double res = sqrt(sin(x - 31));
  double my_res = polish(my_str, x);
  int res_flag = 0;
  int myres_flag = 0;
  if (res == NAN) {
    res_flag = 1;
  }
  if (my_res == NAN) {
    myres_flag = 1;
  }
  ck_assert_int_eq(res_flag, myres_flag);
}
END_TEST

START_TEST(myTest_22) {
  double x = 125;
  char *my_str = "sin(1)-cos(0)+ln(235)/log(0.124)";
  double res = sin(1) - cos(0) + log(235) / log10(0.124);
  double my_res = polish(my_str, x);
  ck_assert_double_eq_tol(res, my_res, 1e-7);
}
END_TEST

Suite *suiteCalc(void) {
  Suite *s = suite_create("qtCalc");
  TCase *tc = tcase_create("qtCalc");

  tcase_add_test(tc, myTest_1);
  tcase_add_test(tc, myTest_2);
  tcase_add_test(tc, myTest_3);
  tcase_add_test(tc, myTest_4);
  tcase_add_test(tc, myTest_5);
  tcase_add_test(tc, myTest_6);
  tcase_add_test(tc, myTest_7);
  tcase_add_test(tc, myTest_8);
  tcase_add_test(tc, myTest_9);
  tcase_add_test(tc, myTest_10);
  tcase_add_test(tc, myTest_11);
  tcase_add_test(tc, myTest_12);
  tcase_add_test(tc, myTest_13);
  tcase_add_test(tc, myTest_14);
  tcase_add_test(tc, myTest_15);
  tcase_add_test(tc, myTest_16);
  tcase_add_test(tc, myTest_17);
  tcase_add_test(tc, myTest_18);
  tcase_add_test(tc, myTest_19);
  tcase_add_test(tc, myTest_20);
  tcase_add_test(tc, myTest_21);
  tcase_add_test(tc, myTest_22);

  suite_add_tcase(s, tc);
  return s;
}

void startTestCase(Suite *testCase) {
  static int valueTest = 1;
  if (valueTest > 1) valueTest++;
  SRunner *sr = srunner_create(testCase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void startTest(void) {
  Suite *listCase[] = {suiteCalc(), NULL};

  for (Suite **thisCase = listCase; *thisCase != NULL; thisCase++) {
    startTestCase(*thisCase);
  }
}
