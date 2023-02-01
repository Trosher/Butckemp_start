#include "data_process.h"

int main() {
    double data[500];
    int x;

    if (input(data, &x)) {
        if (normalization(data, x)) {
            output(data, x);
        } else { printf("ERROR"); }
    } else { printf("ERROR"); }
    return 0;
}
