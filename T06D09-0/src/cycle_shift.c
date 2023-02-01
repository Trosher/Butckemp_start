#include <stdio.h>

int input(int *data, int *len);
int input_push(int *push);
void output(int *data, int len);
void shift_puzitiv(int *data, int len, int push);
void shift_negativ(int *data, int len, int push);
int shift_left_rith(int push);

int main() {
    int data[10];
    int len;
    int push;
    int *p;
    p = data;
    if (input(p, &len) == 1 || input_push(&push) == 1) {
        return 0;
    } else {
        if (shift_left_rith(push) == 2) {
            shift_negativ(p, len, push * -1);
        } else if (shift_left_rith(push) == 1) {
            shift_puzitiv(p, len, push);
        } else {
            output(p, len);
        }
    }
    return 0;
}

int input(int *data, int *len) {
    float test;
    char c;
    if (!(scanf("%f%c", &test, &c) == 2 && \
        (c == '\n' || c == ' '))) { printf("n/a");
        return 1;
    } else { *len = test;
        if (!(*len == test && (*len > 0 && *len < 11))) { printf("n/a");
            return 1;
        }
    }
    for (int i = 0; i < *len; i++) {
        if (scanf("%f%c", &test, &c) == 2 && \
            (c == '\n' || c ==  ' ')) { *data = test;
            if (!(*data == test) && !(test)) { printf("n/a");
                return 1;
            }
            data++;
        } else { printf("n/a");
            return 1;
        }
    }
    return 0;
}

int input_push(int *push) {
  float test;
  char c;
  if (!(scanf("%f%c", &test, &c) == 2 && \
      (c == '\n' || c == ' '))) { printf("n/a");
      return 1;
  } else { *push = test;
      if (!(*push == test)) { printf("n/a");
          return 1;
      }
  }
  return 0;
}

void output(int *data, int len) {
    for (int i = 0; i < len; i++) {
        if (i < len - 1) {
           printf("%d ", data[i]);
        } else {
            printf("%d", data[i]);
        }
    }
}

int shift_left_rith(int push) {
    if (push < 0) {
        return 2;
    } else if (push > 0) {
        return 1;
    }
    return 0;
}

void shift_negativ(int *data, int len, int push) {
    if (push > len)
        push = push % len;
    for (int i = len - push; i < len; i++) {
        if (i < len - 1) {
            printf("%d ", data[i]);
        } else {
            printf("%d", data[i]);
        }
    }
    for (int i = 0; i < len - push; i ++) {
        if (i < (len - push - 1)) {
            printf("%d ", data[i]);
        } else {
            printf("%d", data[i]);
        }
    }
}

void shift_puzitiv(int *data, int len, int push) {
    if (push > len)
        push = push % len;
    for (int i = push; i < len; i++) {
        printf("%d ", data[i]);
    }
    for (int i = 0; i < push; i ++) {
        if (i < push - 1) {
            printf("%d ", data[i]);
        } else {
            printf("%d", data[i]);
        }
    }
}
