#include "polish.h"

#include "stack.h"

double magic_of_polish(char *str, double x) {
  double res = 0.0;
  stack_sign *s_stack = NULL;
  stack_value *v_stack = NULL;
  double temp_one = 0.0;
  double temp_two = 0.0;
  int prev_sign = 0;
  int new_sign = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '(') {
      char buffer[100];
      int t = 1;
      int flag = 0;
      for (; flag != 1; t++) {
        if (str[i + t] == '(') {
          flag--;
        } else if (str[i + t] == ')') {
          flag++;
        }
        if (flag != 1) {
          buffer[t - 1] = str[i + t];
        }
      }
      buffer[t - 2] = '\0';
      v_stack = push_value(v_stack, magic_of_polish(buffer, x));
      i = i + strlen(buffer) + 1;
    } else if (is_digit(str[i]) == 1) {
      if (i == 0 || str[i - 1] == ' ') {
        char new_digit[50];
        int j = 0;
        for (; str[i + j] != ' '; j++) {
          new_digit[j] = str[i + j];
        }
        new_digit[j] = '\0';
        v_stack = push_value(v_stack, atof(new_digit));
      }
    } else if (str[i] == 'x') {
      v_stack = push_value(v_stack, x);
    } else if (find_priority(str[i]) > 0) {
      new_sign = find_priority(str[i]);
      while (new_sign <= prev_sign && s_stack != NULL) {
        temp_two = value_value(v_stack);
        v_stack = pop_value(v_stack);
        if (find_priority(value_sign(s_stack)) == 4 ||
            find_priority(value_sign(s_stack)) == 5) {
          temp_one = 0.0;
        } else {
          temp_one = value_value(v_stack);
          v_stack = pop_value(v_stack);
        }
        v_stack = push_value(v_stack,
                             my_math(temp_one, temp_two, value_sign(s_stack)));
        s_stack = pop_sign(s_stack);
        if (s_stack != NULL) {
          prev_sign = find_priority(value_sign(s_stack));
        }
      }
      if (new_sign > prev_sign || s_stack == NULL) {
        s_stack = push_sign(s_stack, str[i]);
        prev_sign = find_priority(str[i]);
      }
    }
  }
  while (s_stack != NULL) {
    temp_two = value_value(v_stack);
    v_stack = pop_value(v_stack);
    if (find_priority(value_sign(s_stack)) == 4 ||
        find_priority(value_sign(s_stack)) == 5) {
      temp_one = 0.0;
    } else {
      temp_one = value_value(v_stack);
      v_stack = pop_value(v_stack);
    }
    v_stack =
        push_value(v_stack, my_math(temp_one, temp_two, value_sign(s_stack)));
    s_stack = pop_sign(s_stack);
  }
  res = value_value(v_stack);
  v_stack = pop_value(v_stack);
  free(s_stack);
  free(v_stack);
  return res;
}
