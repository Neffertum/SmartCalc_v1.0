#ifndef SRC_POLISH_H_
#define SRC_POLISH_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double polish(const char *str, double x);
double magic_of_polish(char *calc_str, double x);
int find_priority(char a);
int is_digit(char a);
double my_math(double a, double b, char c);

#ifdef __cplusplus
}
#endif

#endif  //  SRC_POLISH_H_
