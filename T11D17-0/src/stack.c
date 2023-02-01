#include "stack.h"

void destroy(struct stack_str *stack) {
    while (stack != NULL) {
        struct stack_str *p = stack;
        stack = stack -> back;
        free(p);
    }
}

struct stack_str *init(struct door* door) {
    struct stack_str *tmp = (struct stack_str*)malloc \
    (sizeof(struct stack_str));
    if (tmp != NULL) {
        tmp -> value = door;
        tmp -> next = NULL;
        tmp -> back = NULL;
    }
    return tmp;
}

struct stack_str *push(struct stack_str *stack, struct door* doors) {
    struct stack_str *tmp = (struct stack_str*)malloc(sizeof(struct stack_str));
    if (tmp != NULL) {
        tmp -> value = doors;
        tmp -> next = NULL;
        tmp -> back = stack;
        stack -> next = tmp;
    } else {
        destroy(stack);
        return NULL;
    }
    return tmp;
}

struct stack_str *pop(struct stack_str *stack) {
    if (stack -> back == NULL) {
        destroy(stack);
        return NULL;
    } else {
        if (stack -> back != NULL) {
            struct stack_str *p = stack;
            stack = stack -> back;
            free(p);
        }
    }
    return stack;
}
