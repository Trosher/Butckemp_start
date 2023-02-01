#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

void in_sort(int *data, int len);
int input(int *data, int *len);
void output(int *data, int len);

int main() {
    int *data = (int*) malloc(NMAX * sizeof(int));
    if (data == NULL) { printf("n/a");
        return 0; }
    int len;
    if (input(data, &len) == 1) {
        return 0;
    } else {
        in_sort(data, len);
        output(data, len);
    }
    free(data);
    return 0;
}

void output(int *data, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d", data[i]);
        if (i < len - 1)
            printf(" ");
    }
}

void in_sort(int *data, int len) {
    int element, index;
    for (int i = 1; i < len; i++) {
        element = data[i];
        index = i - 1;
        while (index >= 0 && data[index] > element) {
            data[index + 1] = data[index];
            index--;
        }
        data[index + 1] = element;
    }
}

int input(int *data, int *len) {
    char c;
    if (!(scanf("%d%c", len, &c) == 2 && \
          (c == '\n' || c == ' '))) { printf("n/a");
        return 1;
    }
    for (int i = 0; i < *len; i++) {
        if (scanf("%d%c", data, &c) == 2 && \
            (c == '\n' || c ==  ' ')) {
            data++;
        } else {
            printf("n/a");
            return 1;
        }
    }
    return 0;
}
