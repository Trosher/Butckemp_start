#include "Input_and_transform.h"
#include "structs.h"
#include "defines.h"
#include <string.h>
#include <stdio.h>

Queue *input_queue(char *input, int *fl) {
    Stack *stack = init_stack();
    Queue *tokens = init_queue();
    int is_unary = 1;
    for (int i = 0; input[i] != 0; i++) {
        i = parseList(input, i, &is_unary, tokens, stack);
        if (i == -1) {
            *fl = 0;
            break;
        }
    }
    int op;
    double value;
    while (!pop_stack(stack, &op, &value) && *fl) {
        push_queue(tokens, op, value);
    }
    destroy_stack(stack);
    return tokens;
}

int parseList(char *input, int i, int *is_unary, Queue *q, Stack *stack) {
    if (input[i] >= '0' && input[i] <= '9') {
        double value = 0;
        sscanf(input + i, "%lf", &value);
        i = i + skip_number(input + i) - 1;
        push_queue(q, _NUM, value);
        *is_unary = 0;
    } else if (input[i] == 'x') {
        push_queue(q, _X, 0);
    } else if (input[i] == '-' && (*is_unary)) {
        push_stack(stack, _UNARY_MINUS, 0);
    } else if (one_char_op_to_int(input[i]) != -1) {
        int op = one_char_op_to_int(input[i]);
        if (op == _CLOSE_BRACKET) {
            close_bracket(stack, q);
        } else if (is_binary_op(op)) {
            restack_binary_op(op, stack, q);
            push_stack(stack, op, 0);
        } else {
            push_stack(stack, op, 0);
        }
        *is_unary = 1;
    } else if (check_multichar_ops(input + i) != -1) {
        int op = check_multichar_ops(input + i);
        push_stack(stack, op, 0);
        push_stack(stack, _OPEN_BRACKET, 0);
        i += lenOp(op);
        *is_unary = 1;
    } else if (input[i] != ' ') {
        i = -1;
        printf("Ошибка ввода");
    }
    return i;
}


int is_binary_op(int op) {
    return op == _MUL || op == _DIV || op == _SUB || op == _SUM || op == _POW;
}

void close_bracket(Stack *stack, Queue *exit) {
    int op;
    double value;
    while (!pop_stack(stack, &op, &value) && op != _OPEN_BRACKET) {
        push_queue(exit, op, value);
    }
    if (op != _OPEN_BRACKET) {
        printf("Ошибка ввода");
    }
}

int get_priority(int op) {
    int ret_v = -1;
    if (op == _SUM || op == _SUB) {
        ret_v = 1;
    } else if (op == _MUL || op == _DIV) {
        ret_v = 2;
    } else if (op == _POW) {
        ret_v = 3;
    }
    return ret_v;
}

void restack_binary_op(int op, Stack *stack, Queue *exit) {
    while (stack->last && get_priority(stack->last->op) >= get_priority(op)) {
        int s_op;
        double s_value;
        pop_stack(stack, &s_op, &s_value);
        push_queue(exit, s_op, s_value);
    }
}

int one_char_op_to_int(char op) {
    int ret_v = -1;
    if (op == '+') {
        ret_v = _SUM;
    } else if (op == '-') {
        ret_v = _SUB;
    } else if (op == '/') {
        ret_v = _DIV;
    } else if (op == '*') {
        ret_v = _MUL;
    } else if (op == '^') {
        ret_v = _POW;
    } else if (op == '(') {
        ret_v = _OPEN_BRACKET;
    } else if (op == ')') {
        ret_v = _CLOSE_BRACKET;
    }
    return ret_v;
}

int check_multichar_ops(char *input) {
    int ret_v = -1;
    if (!strncmp(input, "sin(", 4)) {
        ret_v = _SIN;
    } else if (!strncmp(input, "cos(", 4)) {
        ret_v = _COS;
    } else if (!strncmp(input, "tan(", 4)) {
        ret_v = _TAN;
    } else if (!strncmp(input, "ctg(", 4)) {
        ret_v = _CTAN;
    } else if (!strncmp(input, "sqrt(", 5)) {
        ret_v = _SQRT;
    } else if (!strncmp(input, "ln(", 3)) {
        ret_v = _LN;
    }
    return ret_v;
}

int lenOp(int op) {
    int ret_v = 0;
    if (op == _LN) {
        ret_v = 2;
    } else if (op == _TAN || op == _SIN || op == _COS || op == _CTAN) {
        ret_v = 3;
    } else if (op == _SQRT) {
        ret_v = 4;
    }
    return ret_v;
}

int skip_number(char *input) {
    int dot_readed = 0;
    int i = 0;
    while ((input[i] >= '0' && input[i] <= '9') || (input[i] == '.' && !dot_readed)) {
        if (input[i] == '.') dot_readed = 1;
        i++;
    }
    return i;
}
