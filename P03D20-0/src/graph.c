#include <stdio.h>
#include <stdlib.h>

#include "defines.h"
#include "structs.h"
#include "calc.h"
#include "Input_and_transform.h"

char *safe_gets();
void print_graf(Queue *q);

int main() {
    int fl_error = 1;
    char *input_str = safe_gets();
    if (input_str) {
        Queue *q = input_queue(input_str, &fl_error);
        if (fl_error) {
            print_graf(q);
        }
        free(input_str);
        destroy_queue(q);
    }
}

char *safe_gets() {
    char *string = calloc(1, sizeof(char));
    int c = getchar();
    int i = 0;
    while (c != EOF && c != '\n') {
        if (realloc(string, sizeof(char) * (i + 2)) == NULL) {
            free(string);
            printf("Ошибка выделения памяти");
            break;
        } else {
            string[i] = c;
            c = getchar();
            i++;
        }
    }
    return string;
}

void print_graf(Queue *q) {
    double x = 0;
    double y = -1;
    int fl_error = 1;
    double step_x = 4 * M_PI / (SRC_W - 1);
    double step_y = (double)2 / (SRC_H - 1);
    for (int i = 0; i < SRC_H && fl_error; i++) {
        x = 0;
        for (int j = 0; j < SRC_W && fl_error; j++) {
            if (round(calculate(x, clone_queue(q), &fl_error) * 12) / 12 == round(y * 12) / 12 && fl_error) {
                printf("*");
            } else if (fl_error) {
                printf(".");
            }
            x += step_x;
        }
        y += step_y;
        if (fl_error)
            printf("\n");
    }
}

