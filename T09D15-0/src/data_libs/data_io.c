#include "data_io.h"

void output(double *data, int x) {
    double(*data_p) = data;
    for (int j = 0; j < x; j++) {
        if (j < x - 1) {
          printf("%.2lf ", data_p[j]);
        } else {
           printf("%.2lf", data_p[j]);
        }
    }
}

int input(double *data, int *x) {
    double(*data_p) = data;
    char c;
    int error_target = 1;
    int test;
    test = scanf("%d%c", x, &c);
    if ((test == 1 || (test == 2 && (c == '\n' || c == EOF))) && *x > 0) {
        for (int i = 0; i < *x; i++) {
            test = scanf("%lf%c", &data_p[i], &c);
            if (test == 1) { continue;
            } else if (test == 2 && (c == ' ' || c == '\n')) {
                if (i == *x - 1 && c != '\n') { error_target = 0; }
                continue;
            } else { error_target = 0; }
        }
    } else { error_target = 0; }
    return error_target;
}
