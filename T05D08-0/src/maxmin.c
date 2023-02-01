#include <stdio.h>

void maxmin(int prob1, int prob2, int prob3, int *max, int *min);

int main() {
  int x, y, z;
  float x_test, y_test, z_test;
  if (scanf("%f%f%f", &x_test, &y_test, &z_test) == 3) {
    x = x_test;
    y = y_test;
    z = z_test;
    if (z_test == z && y_test == y && x_test == x) {
      int max, min;
      maxmin(x, y, z, &max, &min);
      printf("%d %d", max, min);
    } else {
      printf("n/a");
    }
  } else {
    printf("n/a");
  }
  return 0;
}

void maxmin(int prob1, int prob2, int prob3, int *max, int *min) {
  *max = *min = prob1;
  if (prob2 > *max)
    *max = prob2;
  if (prob2 < *min)
    *min = prob2;
  if (prob3 > *max)
    *max = prob3;
  if (prob3 < *min)
    *min = prob3;
}
