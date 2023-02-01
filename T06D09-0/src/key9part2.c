#include <stdio.h>

#define LEN 100
/*
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);


    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод: 
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод: 
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int input(int *data1, int *len1, int *data2, int *len2);
void sum(int *data1, int len1, int *data2, int len2, \
         int *data_res, int *len_res);
void sub(int *data1, int len1, int *data2, int len2, \
         int *data_res, int *len_res);
void output(int *data, int len_target);
int sub_check(int *data1, int len1, int *data2, int len2);

int main() {
    int data1[LEN];
    int data2[LEN];
    int data_res[LEN + 1];
    int len1 = 0;
    int len2 = 0;
    int len_res = 0;
    int *p1, *p2, *p_res;
    p1 = data1;
    p2 = data2;
    p_res = data_res;
    if (input(p1, &len1, p2, &len2) == 1)
        return 0;
    sum(p1, len1, p2, len2, p_res, &len_res);
    output(p_res, len_res);
    len_res = 0;
    if (sub_check(p1, len1, p2, len2) != 1) {
        sub(p1, len1, p2, len2, \
            p_res, &len_res);
        output(p_res, len_res);
    }
    return 0;
}

int sub_check(int *data1, int len1, int *data2, int len2) {
    printf("\n");
    if (len1 < len2) { printf("n/a");
        return 1;
    }
    if (len1 == len2) {
        for (int i = 0; i <= len1; i++) {
            if (data1[i] > data2[i]) { return 0;
            } else  if (data1[i] < data2[i]){ printf("n/a");
                return 1;
            }
        }
    }
    return 0;
}

void sub(int *data1, int len1, int *data2, int len2, \
         int *data_res, int *len_res) {
    int v_ume = 0;
    int i = len1;
    int j = len2;
    int x = LEN + 1;
    while (1) {
        if (i >= 0 && j >= 0) { data_res[x] = data1[i] - data2[j] + v_ume;
        } else if (i >= 0 && j < 0) { data_res[x] = data1[i] + v_ume;
        } else if (i < 0 && j >= 0) { data_res[x] = data2[j] + v_ume;
        } else if (v_ume == 1) { data_res[x] += v_ume;
        } else { break;
        }
        if (data_res[x] < 0) { data_res[x] = data_res[x] * -1;
            v_ume = -1;
        } else { v_ume = 0;
        }
        *len_res += 1;
        i--;
        j--;
        x--;
    }
}

void sum(int *data1, int len1, int *data2, int len2, \
         int *data_res, int *len_res) {
    int v_ume = 0;
    int i = len1;
    int j = len2;
    int x = LEN + 1;
    while (1) {
        if (i >= 0 && j >= 0) { data_res[x] = data1[i] + data2[j] + v_ume;
        } else if (i >= 0 && j < 0) { data_res[x] = data1[i] + v_ume;
        } else if (i < 0 && j >= 0) { data_res[x] = data2[j] + v_ume;
        } else if (v_ume == 1) { data_res[x] += v_ume;
        } else { break;
        }
        if (data_res[x] > 9) { data_res[x] = data_res[x] % 10;
            v_ume = 1;
        } else { v_ume = 0;
        }
        *len_res += 1;
        i--;
        j--;
        x--;
    }
}

void output(int *data, int len_target) {
    int caunter = LEN + 2 - len_target;
    int zero_chek = 0;
    for (int i = LEN + 2 - len_target; i <= LEN + 1; i++) {
        if (data[i] == 0 && caunter == i) {
            caunter++;
        } else if (i < LEN + 1) { printf("%d ", data[i]);
        } else { printf("%d", data[i]); }
        if (data[i] != 0) { zero_chek = 1; }
    }
    if (zero_chek == 0) { printf("0"); }
}

int input(int *data1, int *len1, int *data2, int *len2) {
    *data1 = 1;
    char c;
    for (int i = 0; i < LEN; i++) {
        if (scanf("%d%c", &data1[i], &c) == 2 && (c == ' ' || c == '\n') \
            && (data1[i] <= 9 && data1[i] >= 0)) {
            if (c == '\n') {
                break;
            }
            *len1 += 1;
        } else { printf("n/a");
          return 1;
        }
    }
    for (int i = 0; i < LEN; i++) {
        if (scanf("%d%c", &data2[i], &c) == 2 && (c == ' ' || c == '\n') \
            && (data2[i] <= 9 && data2[i] >= 0)) {
            if (c == '\n') {
                break;
            }
            *len2 += 1;
        } else { printf("n/a");
          return 1;
        }
    }
    return 0;
}
