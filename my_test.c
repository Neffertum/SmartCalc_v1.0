#include <stdio.h>

#include "polish.h"

int main() {
  char *my_string = "cos(12365)-896541/89";
  double x = 0.65;
  // double new_result = mod(0.65);
  // char *my_string = "7*asin(234.1135537*cos(3125))";
  // char *my_string = "-1+cos(21234.54654)*(-2-sin(-3)+(-1))/0.123";
  // double new_result = -1+atan(21234.13)*(-2-sin(-3)+(-1))/0.1234;
  // char *my_string = "- ( 100 )";
  // char *my_string = "sin ( 3 ) - ln ( 256 )";
  // char *my_string = "ln ( 256 ) * sqrt ( 2 ) ";
  // char *my_string = "sqrt ( 2 ) =";
  // char *my_string = "ln ( 256 ) =";

  // char *my_string = "# 1";
  // char *my_string = "1 + 23 * ( 2 - 3 + 1\0";
  // char *my_string = "1.2 + 2 - 1.2\0";
  // char *my_string = "1 + sin ( + 3 ) =";
  double result = polish(my_string, x);
  printf("\n\nthat: %s\n\n", my_string);

  printf("%f\n\n", result);
  // printf("%f\n\n", new_result);

  return 0;
}
