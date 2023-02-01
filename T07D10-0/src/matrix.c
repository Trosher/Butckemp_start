#include <stdio.h>
#include <stdlib.h>

int input_x_y(int *y, int *x);
int input_r(int *target);
int input_x_line(int *data, int x);
void output_x_line(int *data, int x);
int static_matrix(int y, int x);
int matrix_one_buffer(int y, int x);
int matrix_to_arrays(int y, int x);
int matrix_second_array(int y, int x);

int main() {
    int target;
    int y;
    int x;
    if (input_r(&target) == 1) { return 0; }
    if (input_x_y(&y, &x) == 1) { return 0; }
    if (target == 1) {
        if (x < 101 && y < 101) {
            if (static_matrix(y, x) == 1) { return 0; }
        } else {
            printf("n/a");
            return 0;
        }
    } else if (target == 2) {
        if (matrix_one_buffer(y, x)  == 1) { return 0; }
    } else if (target == 3) {
        if (matrix_to_arrays(y, x)  == 1) { return 0; }
    } else {
        if (matrix_second_array(y, x) == 1) { return 0; }
    }
    return 0;
}

int input_r(int *target) {
    char c;
    if (!(scanf("%d%c", target, &c) == 2 && \
       (c == ' ' || c == '\n' || c == '\0') && \
       (*target > 0 && *target < 5))) { printf("n/a");
        return 1;
    }
    return 0;
}

int input_x_y(int *y, int *x) {
    char c;
    if (!(scanf("%d%c", x, &c) == 2 && \
       (c == ' ' || c == '\n' || c == '\0') && \
       *x > 0)) { printf("n/a");
        return 1;
    }
    if (!(scanf("%d%c", y, &c) == 2 && \
       (c == ' ' || c == '\n' || c == '\0') && \
       *y > 0)) { printf("n/a");
        return 1;
    }
    return 0;
}

int input_x_line(int *data, int x) {
    char c;
    for (int i = 0; i < x; i++) {
        if (scanf("%d%c", &data[i], &c) == 2 && \
            (c == ' ' || c == '\n' || c == '\0')) {
            if (c == '\n' || c == '\0') { break; }
        } else { printf("n/a");
          return 1;
        }
    }
    return 0;
}

void output_x_line(int *data, int x) {
    for (int i = 0; i < x; i++) {
        if (i < x - 1) { printf("%d ", data[i]);
        } else { printf("%d", data[i]); }
    }
}

int static_matrix(int y, int x) {
    int data[y][x];
    int *p;
    for (int i = 0; i < y; i++) {
        p = data[i];
        if (input_x_line(p, x) == 1) { return 1; }
    }
    for (int i = 0; i < y; i++) { p = data[i];
        output_x_line(p, x);
        if (i < y - 1) { printf("\n"); }
    }
    return 0;
}

int matrix_one_buffer(int y, int x) {
    int **data = malloc(y * x * sizeof(int) + y * sizeof(int*));
    int *ptr = (int*) (data + y);
    int *p;
    if (data == NULL) { printf("n/a");
        return 1;
    }
    for (int i = 0; i < y; i++)
        data[i] = ptr + x * i;
    for (int i = 0; i < y; i++) { p = data[i];
        if (input_x_line(p, x) == 1) { free(data);
            return 1; }
    }
    for (int i = 0; i < y; i++) { p = data[i];
        output_x_line(p, x);
        if (i < y - 1) { printf("\n"); }
    }
    free(data);
    return 0;
}

int matrix_to_arrays(int y, int x) {
    int **data = malloc(y * sizeof(int*));
    int *p;
    if (data == NULL) { printf("n/a");
        return 1;
    }
    for (int i = 0; i < y; i++)
        data[i] = malloc (x * sizeof(int));
    for (int i = 0; i < y; i++) { p = data[i];
        if (input_x_line(p, x) == 1) {
            for (int i = 0; i < y; i++)
                free(data[i]);
            free(data);
            return 1;
        }
    }
    for (int i = 0; i < y; i++) { p = data[i];
        output_x_line(p, x);
        if (i < y - 1) { printf("\n"); }
    }
    for (int i = 0; i < y; i++)
        free(data[i]);
    free(data);
    return 0;
}

int matrix_second_array(int y, int x) {
    int **data_p = malloc(y * sizeof(int*));
    int *data_v = malloc(y * x * sizeof(int));
    int *p;
    if (data_p == NULL) { printf("n/a");
        return 1;
    }
    if (data_v == NULL) { printf("n/a");
        return 1;
    }
    for (int i = 0; i < y; i++)
        data_p[i] = data_v + x * i;
    for (int i = 0; i < y; i++) { p = data_p[i];
        if (input_x_line(p, x) == 1) { free(data_p);
            free(data_v);
            return 1; }
    }
    for (int i = 0; i < y; i++) { p = data_p[i];
        output_x_line(p, x);
        if (i < y - 1) { printf("\n"); }
    }
    free(data_p);
    free(data_v);
    return 0;
}
