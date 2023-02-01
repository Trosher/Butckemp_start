#include "data_stat.h"

double max(double *data, int x) {
    double max = data[0];
    for (int j = 0; j < x; j++) {
        if (max < data[j]) {
            max = data[j];
        }
    }
    return max;
}

double min(double *data, int x) {
    double min = data[0];
    for (int j = 0; j < x; j++) {
        if (min > data[j]) {
            min = data[j];
        }
    }
    return min;
}

double mean(double *data, int x) {
    double mean = 0.0;
    double caunter = 0.0;
    for (int j = 0; j < x; j++) {
        caunter++;
        mean += data[j];
    }
    return mean / caunter;
}

double variance(double *data, int x) {
    double res = 0.0;
    double m;
    m = mean(data, x);
    for (int i = 0; i < x; i++) {
      res += (data[i] - m) * (data[i] - m);
    }
    return res / x;
}
