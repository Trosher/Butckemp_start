#ifndef SRC_INPUT_AND_TRANSFORM_H_
#define SRC_INPUT_AND_TRANSFORM_H_

#include "structs.h"


Queue *input_queue(char *input, int *fl);
int parseList(char *input, int i, int *is_unary, Queue *q, Stack *stack);
int get_priority(int op);
int is_binary_op(int op);
void close_bracket(Stack *stack, Queue *exit);
void restack_binary_op(int op, Stack *stack, Queue *exit);
int one_char_op_to_int(char op);
int check_multichar_ops(char *input);
int lenOp(int op);
int skip_number(char *input);


#endif  // SRC_INPUT_AND_TRANSFORM_H_
