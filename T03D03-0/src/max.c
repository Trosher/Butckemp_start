#include<stdio.h>

void max(int a, int b);

int main() {
  int a;
  int b;
  float a_test;
  float b_test;
  if (scanf("%f%f", &a_test, &b_test) == 2) {
    a = a_test;
    b = b_test;
    if (a != a_test || b != b_test) {
      printf("n/a\n");
      return 0;
    }
    max(a, b);
  } else {
    printf("n/a\n");
    return 0;
  }
}

void max(int a, int b) {
  if (a > b) {
    printf("%d\n", a);
  } else if (b > a) {
    printf("%d\n", b);
  } else {
    printf("%d = %d\n", a, b);
  }
}
