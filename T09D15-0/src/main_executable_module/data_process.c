#include "data_process.h"

int normalization(void *data, int x) {
    double(*data_p) = data;
    int result = 1;
    double max_value = max(data_p, x);
    double min_value = min(data_p, x);
    double size = max_value - min_value;

    if (fabs(size) > EPS) {
        for (int j = 0; j < x; j++) {
            data_p[j] = data_p[j] / size - min_value / size;
        }
    } else {
        result = 0;
    }
    return result;
}

void sort(void *data, int len) {
    double(*data_p) = data;
    double num = 0.0;
    for (int i = 0; i < len; i++) {
        if (i < len - 1) {
            if (data_p[i] > data_p[i + 1]) {
                num = data_p[i + 1];
                data_p[i + 1] = data_p[i];
                data_p[i] = num;
                i = 0;
            }
        }
        if (i > 0) {
            if (data_p[i - 1] > data_p[i]) {
                num = data_p[i - 1];
                data_p[i - 1] = data_p[i];
                data_p[i] = num;
                i = 0;
            }
        }
    }
}

int make_decision(double *data, int x) {
    double(*data_p) = data;
    int decision = 1;

    double m = mean(data_p, x);
    double sigma = sqrt(variance(data_p, x));
    double max_value = max(data_p, x);
    double min_value = min(data_p, x);

    decision &= (max_value <= m + 3*sigma) &&
                (min_value >= m - 3*sigma) &&
                (m >= GOLDEN_RATIO);

    return decision;
}
