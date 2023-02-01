#include "calc.h"
#include "structs.h"
#include "Input_and_transform.h"
#include "defines.h"
#include <stdio.h>

double calculate(double x, Queue *list_calc, int *fl) {
    Stack *stack = init_stack();
    int op;
    double value;
    int i = 0;
    while (!pop_queue(list_calc, &op, &value)) {
        if (consume_calc(stack, op, value, i, x) == -1) {
            *fl = 0;
            break;
        }
    }
    pop_stack(stack, &op, &value);
    destroy_stack(stack);
    destroy_queue(list_calc);
    return value;
}

double get_unary_op(int op, double a) {
    double result = 0;
    if (op == _UNARY_MINUS) {
        result = a * -1;
    } else if (op == _COS) {
        result = cos(a);
    } else if (op == _SIN) {
        result = sin(a);
    } else if (op == _TAN) {
        result = tan(a);
    } else if (op == _CTAN) {
        result = 1 / tan(a);
    } else if (op == _SQRT) {
        result = sqrt(a);
    } else if (op == _LN) {
        result = log(a);
    }
    return result;
}


double get_binary_op(int op, double a, double b) {
    double result = 0;
    if (op == _SUM) {
        result = a + b;
    } else if (op == _SUB) {
        result = a - b;
    } else if (op == _MUL) {
        result = a * b;
    } else if (op == _DIV) {
        result = a / b;
    } else if (op == _POW) {
        result = pow(a, b);
    }
    return result;
}
int unary_op(int op) {
    return op == _UNARY_MINUS || op == _COS || op == _SIN || op == _TAN \
    || op == _CTAN || op == _SQRT || op == _LN;
}

int binary_op(int op) {
    return op == _SUM || op == _SUB || op == _MUL || op == _DIV || op == _POW;
}

int consume_calc(Stack *stack, int op, double value, int i, double x) {
    int opTemp = op;
    if (op == _NUM) {
        push_stack(stack, _NUM, value);
    } else if (op == _X) {
        push_stack(stack, _NUM, x);
    } else if (unary_op(op)) {
        pop_stack(stack, &op, &value);
        value = get_unary_op(opTemp, value);
        push_stack(stack, op, value);
    } else if (binary_op(op)) {
        double value1, value2;
        pop_stack(stack, &op, &value1);
        pop_stack(stack, &op, &value2);
        value1 = get_binary_op(opTemp, value1, value2);
        push_stack(stack, op, value1);
    } else {
        i = -1;
        printf("Ошибка в структуре введёного уравнения");
    }
    return i;
}
