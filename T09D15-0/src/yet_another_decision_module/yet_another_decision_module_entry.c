#include "decision.h"

int main() {
    double data[500];
    int x;
    if (input(data, &x)) {
        if (make_decision(data, x)) { printf("YES");
        } else { printf("NO"); }
    } else { printf("NO"); }
    return 0;
}
