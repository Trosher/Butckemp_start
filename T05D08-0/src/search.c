#include <stdio.h>
#include <math.h>
#define NMAX 30

double variance(int *data, int len);
double mean(int *data, int len);
double sigm_3();
int input(int *data, int *len);
int even(int num);
int search(int *data, int len);

int main() {
    int len, data[NMAX];
    int *p = data;
    if (input(p, &len) == 1) {
        return 0;
    } else {
        printf("%d", search(data, len));
    }
    return 0;
}

int search(int *data, int len) {
    double mean_num = mean(data, len);
    double sigm_3_num = sigm_3(data, len);
    for (int i = 0; i < len; i++) {
        if (data[i] != 0 && even(data[i]) == 1 \
            && data[i] >= mean_num && data[i] <= sigm_3_num)
            return data[i];
    }
    return 0;
}

double sigm_3(int *data, int len) {
    double res;
    res = mean(data, len) + 3 * sqrt(variance(data, len));
    return res;
}

int even(int num) {
    int res = 0;
    if (num < 0) {
        num *= -1;
    }
    res = num % 2;
    if (res == 0)
        return 1;
    return 0;
}

int input(int *data, int *len) {
    float test_len;
    float test_data;
    if (scanf("%f", &test_len) == 1) {
        *len = test_len;
        if (*len == test_len && (*len < 31 && *len > 0)) {
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

double mean(int *data, int len) {
    double mean = 0.0;
    for (int i = 0; i < len; i++) {
        mean += *data;
        data++;
    }
    mean = mean / (double)len;
    return mean;
}

double variance(int *data, int len) {
    double res = 0.0;
    double m;
    m = mean(data, len);
    for (int i = 0; i < len; i++) {
      res += (data[i] - m) * (data[i] - m);
    }
    return res / len;
}
