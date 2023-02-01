/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

int input(int *data, int *len);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int* buffer, int length, int number, int* numbers);
void end_work();
void output_sum(int sum);

int main() {
    int data[10];
    int numbers[10];
    int len;
    int *pn;
    pn = numbers;
    int *p;
    p = data;
    int res_sum;
    if (input(p, &len) == 1) {
        return 0;
    } else {
        res_sum = sum_numbers(p, len);
        if (res_sum == 0) {
            end_work();
            return 0;
        }
        output_sum(res_sum);
        len = find_numbers(p, len, res_sum, pn);
        if (len > 0)
          output(pn, len);
    }
    return 0;
}

void end_work() {
    printf("n/a");
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        if (i < length - 1) {
          printf("%d ", *buffer);
          buffer++;
        } else {
            printf("%d", *buffer);
        }
    }
}

void output_sum(int sum) {
    printf("%d\n", sum);
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
      if (buffer[i] % 2 == 0) {
          sum = sum + buffer[i];
      }
    }
    return sum;
}

int find_numbers(int *data, int len, int sum, int *numbers) {
    int len_numbers = 0;
    for (int i = 0; i < len; i++) {
        if (!(data[i] == 0)) {
          if (sum % data[i] == 0) {
              numbers[len_numbers] = data[i];
              len_numbers++;
          }
        }
    }
    return len_numbers;
}

int input(int *data, int *len) {
    float test_data, len_test;
    char c;
    if (!(scanf("%f%c", &len_test, &c) == 2 && \
        (c == '\n' || c == ' '))) { end_work();
        return 1;
    } else { *len = len_test;
        if (!(*len == len_test && (*len > 0 && *len < 11))) { end_work();
            return 1;
        }
    }
    for (int i = 0; i < *len; i++) {
        if (scanf("%f%c", &test_data, &c) == 2 && \
            (c == '\n' || c ==  ' ')) { *data = test_data;
            if (!(*data == test_data) && !(test_data)) { end_work();
                return 1;
            }
            data++;
        } else { end_work();
            return 1;
        }
    }
    return 0;
}
