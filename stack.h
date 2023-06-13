#ifndef STACK_H_
#define STACK_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

typedef struct stackSign {
  char sign;
  struct stackSign *next;
} stack_sign;

typedef struct stackValue {
  double value;
  struct stackValue *next;
} stack_value;

stack_sign *init_sign(char a);
stack_sign *push_sign(stack_sign *head, char a);
stack_sign *pop_sign(stack_sign *head);
char value_sign(stack_sign *head);
stack_value *init_value(double a);
stack_value *push_value(stack_value *head, double a);
stack_value *pop_value(stack_value *head);
double value_value(stack_value *head);

#ifdef __cplusplus
}
#endif

#endif  //  STACK_H_
