#ifndef SRC_STACK_H_
#define SRC_STACK_H_
#include "door_struct.h"

struct stack_str {
    struct door *value;
    struct stack_str *next;
    struct stack_str *back;
};

struct stack_str *init(struct door* door);
struct stack_str *push(struct stack_str *stack, struct door* door);
struct stack_str *pop(struct stack_str *stack);
void destroy(struct stack_str *stack);

#endif  // SRC_STACK_H_
