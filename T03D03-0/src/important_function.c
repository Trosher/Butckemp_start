#include <stdio.h>
#include <math.h>

int main() {
  float x;
  if (scanf("%f", &x) == 1 && x != 0) {
    x = 7e-3 * pow(x, 4) + ((22.8 * pow(x, 1/3) - 1e3) * x + 3)\
          /(x * x / 2) - x * pow((10 + x), (2/x)) - 1.01;
    printf("%.1lf\n", x);
  } else {
    printf("n/a\n");
    return 0;
  }
  return 0;
}
