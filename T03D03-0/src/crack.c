#include <stdio.h>
#include <math.h>

int main() {
  double x, y;
    if (scanf("%lf%lf", &x, &y) == 2) {
      if (pow(x, 2) + pow(y, 2) <=  25) {
        printf("GOTCHA\n");
       } else {
        printf("MISS\n");
       }
    } else {
      printf("n/a\n");
    }
  return 0;
}
