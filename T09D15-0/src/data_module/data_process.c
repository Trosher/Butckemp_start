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
