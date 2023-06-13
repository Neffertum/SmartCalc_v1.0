#include "stack.h"

stack_sign *init_sign(char a) {
  stack_sign *temp = (stack_sign *)malloc(sizeof(stack_sign));
  temp->sign = a;
  temp->next = NULL;
  return temp;
}

stack_sign *push_sign(stack_sign *head, char a) {
  stack_sign *temp = init_sign(a);
  temp->next = head;
  return temp;
}

stack_sign *pop_sign(stack_sign *head) {
  stack_sign *temp = NULL;
  if (head != NULL) {
    temp = head->next;
    free(head);
  }
  return temp;
}

char value_sign(stack_sign *head) { return head->sign; }

stack_value *init_value(double a) {
  stack_value *temp = (stack_value *)malloc(sizeof(stack_value));
  temp->value = a;
  temp->next = NULL;
  return temp;
}

stack_value *push_value(stack_value *head, double a) {
  stack_value *temp = init_value(a);
  temp->next = head;
  return temp;
}

stack_value *pop_value(stack_value *head) {
  stack_value *temp = NULL;
  if (head != NULL) {
    temp = head->next;
    free(head);
  }
  return temp;
}

double value_value(stack_value *head) { return head->value; }