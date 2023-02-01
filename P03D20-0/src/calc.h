#ifndef SRC_CALC_H_
#define SRC_CALC_H_

#include "structs.h"


double calculate(double x, Queue *expression, int *fl);
double get_unary_op(int op, double a);
double get_binary_op(int op, double a, double b);
int binary_op(int op);
int unary_op(int op);
int consume_calc(Stack *stack, int op, double value, int i, double x);


#endif  // SRC_CALC_H_
