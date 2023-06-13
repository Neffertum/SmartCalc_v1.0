#include "polish.h"

double polish(const char *a, double x) {
  char result[strlen(a) * 3];
  int j = 0;
  for (int i = 0; a[i]; i++) {
    if (a[i] == '.' || is_digit(a[i]) == 1) {
      result[j] = a[i];
    } else {
      result[j] = ' ';
      j++;
      if (a[i] == 'a') {
        if (a[i + 1] == 'c') {
          result[j] = 'C';
          i = i + 3;
        } else if (a[i + 1] == 's') {
          result[j] = 'S';
          i = i + 3;
        } else if (a[i + 1] == 't') {
          result[j] = 'T';
          i = i + 3;
        }
      } else if (i == 0 || a[i - 1] != 'a') {
        if (a[i] == 'c' && a[i + 1] == 'o') {
          result[j] = 'c';
          i = i + 2;
        } else if (a[i] == 's' && a[i + 1] == 'i') {
          result[j] = 's';
          i = i + 2;
        } else if (a[i] == 't' && a[i + 1] == 'a') {
          result[j] = 't';
          i = i + 2;
        } else if (a[i] == 's' && a[i + 1] == 'q') {
          result[j] = 'q';
          i = i + 3;
        } else if (a[i] == 'l' && a[i + 1] == 'n') {
          result[j] = 'n';
          i = i + 1;
        } else if (a[i] == 'l' && a[i + 1] == 'o') {
          result[j] = 'l';
          i = i + 2;
        } else if (a[i] == 'm' && a[i + 1] == 'o') {
          result[j] = '%';
          i = i + 2;
        } else if (a[i] == '+' && (a[i - 1] == '(' || i == 0)) {
          result[j] = '#';
        } else if (a[i] == '-' && (a[i - 1] == '(' || i == 0)) {
          result[j] = '~';
        } else {
          result[j] = a[i];
        }
      }
      j++;
      result[j] = ' ';
    }
    j++;
  }
  result[j] = ' ';
  result[j + 1] = '\0';
  // printf("\n\nmy: %sSTOP\n\n", result);
  double value = magic_of_polish(result, x);
  if (isnan(value)) {
    value = NAN;
  }
  return value;
}

int find_priority(char a) {
  int flag = 0;
  if (a == '+' || a == '-') {
    flag = 1;
  } else if (a == '*' || a == '/' || a == '%') {
    flag = 2;
  } else if (a == '^') {
    flag = 3;
  } else if (a == '~' || a == '#') {
    flag = 4;
  } else if (a == 'c' || a == 'C' || a == 's' || a == 'S' || a == 't' ||
             a == 'T' || a == 'l' || a == 'n' || a == 'q') {
    flag = 5;
  }
  return flag;
}

int is_digit(char a) {
  int flag = 0;
  if (a >= '0' && a <= '9') {
    flag = 1;
  }
  return flag;
}

double my_math(double a, double b, char c) {
  double result = 0.0;
  if (c == '+') {
    result = a + b;
  } else if (c == '-') {
    result = a - b;
  } else if (c == '*') {
    result = a * b;
  } else if (c == '/') {
    result = a / b;
  } else if (c == '%') {
    result = fmod(a, b);
  } else if (c == '^') {
    result = pow(a, b);
  } else if (c == '~') {
    result = b * (-1);
  } else if (c == '#') {
    result = b * 1;
  } else if (c == 'c') {
    result = cos(b);
  } else if (c == 'C') {
    result = acos(b);
  } else if (c == 's') {
    result = sin(b);
  } else if (c == 'S') {
    result = asin(b);
  } else if (c == 't') {
    result = tan(b);
  } else if (c == 'T') {
    result = atan(b);
  } else if (c == 'l') {
    result = log10(b);
  } else if (c == 'n') {
    result = log(b);
  } else if (c == 'q') {
    result = sqrt(b);
  }
  return result;
}
