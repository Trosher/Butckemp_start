#include "data_process.h"

int main() {
    double data[500];
    int x;

    printf("LOAD DATA...\n");
    input(data, &x);

    printf("RAW DATA:\n\t");
    output(data, x);

    printf("\nNORMALIZED DATA:\n\t");
    normalization(data, x);
    output(data, x);

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, x);
    output(data, x);

    printf("\nFINAL DECISION:\n\t");
    make_decision(data, x);
    output(data, x);
}
