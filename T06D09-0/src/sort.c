#include <stdio.h>
#define NMAX 10

void sort(int *data, int len);
int input(int *data, int len);
void output(int *data, int len);

int main() {
    int data[NMAX];
    int len = 10;
    int *p = data;
    if (input(p, len) == 1) {
        return 0;
    } else {
        sort(p, len);
        output(p, len);
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

void sort(int *data, int len) {
    int num = 0;
    for (int i = 0; i < len; i++) {
        if (i < len - 1) {
            if (data[i] > data[i + 1]) {
                num = data[i + 1];
                data[i + 1] = data[i];
                data[i] = num;
                i = 0;
            }
        }
        if (i > 0) {
            if (data[i - 1] > data[i]) {
                num = data[i - 1];
                data[i - 1] = data[i];
                data[i] = num;
                i = 0;
            }
        }
    }
}

int input(int *data, int len) {
    float test_data;
    char c;
    for (int i = 0; i < len; i++) {
        if (scanf("%f%c", &test_data, &c) == 2 && \
            (c == '\n' || c ==  ' ')) {
            *data = test_data;
            if (!(*data == test_data) && !(test_data)) {
                printf("n/a");
                return 1;
            }
            data++;
        } else {
            printf("n/a");
            return 1;
        }
    }
    return 0;
}
