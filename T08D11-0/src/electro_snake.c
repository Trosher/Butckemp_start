#include <stdio.h>
#include <stdlib.h>

void sort_vertical(int **data, int y, int x);
int matrix_one_buffer(int y, int x);
void sort_horizontal(int **data, int y, int x);
int input_matrix(int **data, int x, int y);
void output(int **data, int x, int y);
int input_x_y(int *y, int *x);


int main() {
    int y, x;
    if (input_x_y(&y, &x) == 1) { return 0; }
    if (matrix_one_buffer(y, x) == 1) { return 0; }

    return 0;
}

int input_x_y(int *y, int *x) {
    char c;
    if (!(scanf("%d%c", y, &c) == 2 && \
       (c == ' ' || c == '\n' || c == '\0') && \
       *x > 0)) { printf("n/a");
        return 1;
    }
    if (!(scanf("%d%c", x, &c) == 2 && \
       (c == ' ' || c == '\n' || c == '\0') && \
       *y > 0)) { printf("n/a");
        return 1;
    }
    return 0;
}

int input_matrix(int **data, int x, int y) {
    char c;
    for (int j = 0; j < y; j++) {
        for (int i = 0; i < x; i++) {
            if (scanf("%d%c", &data[j][i], &c) == 2 && \
               (c == ' ' || c == '\n' || c == '\0')) {
               if (c == '\n' || c == '\0') { break; }
            } else { printf("n/a");
              return 1;
            }
        }
    }
    return 0;
}

void output(int **data, int x, int y) {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            printf("%d", data[i][j]);
            if (j < x - 1) { printf(" "); }
        }
        if (i < y - 1) { printf("\n"); }
    }
}

void sort_vertical(int **data, int y, int x) {
    int buf, j, target_i;
    buf = j = target_i = 0;
    for (int i = 1; i > -1 && i < y && j != x; (target_i == 0) ? i++ : i--) {
        if (i > 0 && target_i == 0 && data[i - 1][j] > data[i][j]) { buf = data[i - 1][j];
            data[i - 1][j] = data[i][j];
            data[i][j] = buf;
            target_i = i = j = 0;
        } else if (i < y - 1 && target_i == 1 && data[i][j] < data[i + 1][j]) { buf = data[i + 1][j];
            data[i + 1][j] = data[i][j];
            data[i][j] = buf;
            target_i = i = j = 0;
        } else if (target_i == 0 && i == y - 1 && j != x - 1) {
            if (data[i][j + 1] < data[i][j]) { buf = data[i][j];
                data[i][j] = data[i][j + 1];
                data[i][j + 1] = buf;
                target_i = i = j = 0;
            } else { target_i = 1;
                j++;
            }
        } else if (target_i == 1 && i == 0 && j != x - 1) {
            if (data[i][j + 1] < data[i][j]) { buf = data[i][j];
                data[i][j] = data[i][j + 1];
                data[i][j + 1] = buf;
                target_i = i = j = 0;
            } else { target_i = 0;
                j++;
            }
          }
    }
}

void sort_horizontal(int **data, int y, int x) {
    int buf, i, target_i;
    buf = i = target_i = 0;
    for (int j = 1; j > -1 && j < x && i != y; (target_i == 0) ? j++ : j--) {
        if (j > 0 && target_i == 0 && data[i][j - 1] > data[i][j]) { buf = data[i][j - 1];
            data[i][j - 1] = data[i][j];
            data[i][j] = buf;
            target_i = i = j = 0;
        } else if (j < x - 1 && target_i == 1 && data[i][j] < data[i][j + 1]) { buf = data[i][j + 1];
            data[i][j + 1] = data[i][j];
            data[i][j] = buf;
            target_i = i = j = 0;
        } else if (target_i == 0 && j == x - 1 && i != y - 1) {
            if (data[i + 1][j] < data[i][j]) { buf = data[i][j];
                data[i][j] = data[i + 1][j];
                data[i + 1][j] = buf;
                target_i = i = j = 0;
            } else { target_i = 1;
                i++;
            }
        } else if (target_i == 1 && j == 0 && i != y - 1) {
            if (data[i + 1][j] < data[i][j]) { buf = data[i][j];
                data[i][j] = data[i + 1][j];
                data[i + 1][j] = buf;
                target_i = i = j = 0;
            } else { target_i = 0;
                i++;
            }
          }
    }
}

int matrix_one_buffer(int y, int x) {
    int **data = malloc(y * x * sizeof(int) + y * sizeof(int*));
    int *ptr = (int*) (data + y);
    if (data == NULL) { printf("n/a");
        return 1;
    }
    for (int i = 0; i < y; i++)
        data[i] = ptr + x * i;
    if (input_matrix(data, x, y) == 1) { free(data);
        return 1;
    }
    sort_vertical(data, y, x);
    output(data, x, y);
    printf("\n\n");
    sort_horizontal(data, y, x);
    output(data, x, y);
    free(data);
    return 0;
}
