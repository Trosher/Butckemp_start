#include <stdio.h>
#define NMAX 10

int input(int *data, int *len);
void output(int *data, int len);
int max(int *data, int len);
int min(int *data, int len);
double mean(int *data, int len);
double variance(int *data, int len);

void output_result(int max_v, int min_v, \
                   double mean_v, double variance_v);

int main() {
    int len, data[NMAX];
    int *p;
    p = data;
    if (input(p, &len) == 1) {
        return 0;
    } else {
        output(p, len);
        output_result(max(p, len), min(p, len), \
                        mean(p, len), variance(data, len));
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
        if (i < len - 1) {
          printf("%d ", *data);
        } else {
          printf("%d", *data);
        }
        data++;
    }
    printf("\n");
}

void output_result(int max_v, int min_v, \
                   double mean_v, double variance_v) {
    printf("%d %d %lf %lf", max_v, min_v, mean_v, variance_v);
}

int max(int *data, int len) {
    int max = *data;
    for (int i = 0; i < len; i++) {
        if (*data > max)
            max = *data;
        data++;
    }
    return max;
}

int min(int *data, int len) {
    int min = *data;
    for (int i = 0; i < len; i++) {
        if (*data < min)
            min = *data;
        data++;
    }
    return min;
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
