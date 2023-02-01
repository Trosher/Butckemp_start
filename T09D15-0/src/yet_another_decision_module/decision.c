#include "decision.h"

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
