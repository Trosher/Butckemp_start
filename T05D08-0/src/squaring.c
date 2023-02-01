#include <stdio.h>
#define NMAX 10

int input(int *data, int *len);
void output(int *data, int len);
void squaring(int *data, int len);

int main() {
    int len, data[NMAX];
    int *p = data;
    if (input(p, &len) == 1) {
        return 0;
    } else {
        squaring(p, len);
        output(data, len);
    }
    return 0;
}

int input(int *data, int *len) {
    float test_len;
    float test_data;
    if (scanf("%f", &test_len) == 1) {
        *len = test_len;
        if (*len == test_len && (*len < 11 && *len > 0)) {
            for (int i = 0; i < *len; i++) {
                if (scanf("%f", &test_data) == 1) {
                    *data = test_data;
                    if (!(*data == test_data)) {
                        printf("n/a");
                        return 1;
                    }
                    data++;
                } else {
                    printf("n/a");
                    return 1;
                }
            }
        } else {
            printf("n/a");
            return 1;
        }
    } else {
        printf("n/a");
        return 1;
    }
    return 0;
}

void output(int *data, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d", data[i]);
        if (i < len - 1)
            printf(" ");
    }
}

void squaring(int *data, int len) {
    for (int i = 0; i < len; i++) {
    *data = *data * *data;
    data++;
    }
}


