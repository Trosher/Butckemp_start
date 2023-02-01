int input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, 
    int n_second, int m_second, int **matrix_result, int *n_result, int *m_result);
int transpose(int **matrix, int n, int m);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, 
    int n_second, int m_second, int **matrix_result, int *n_result, int *m_result);
int input_x_y(int *y, int *x);
int input_r(int *target);


int main() {
    
    int target;
    int y;
    int x;
    
}

int input_r(int *target) {
    char c;
    if (!(scanf("%d%c", target, &c) == 2 && \
       (c == ' ' || c == '\n' || c == '\0') && \
       (*target > 0 && *target < 4))) { printf("n/a");
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
