#include<stdio.h>

void sum(int a, int b);
void sub(int a, int b);
void umn(int a, int b);
void del(int a, int b);

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
    sum(a, b);
    sub(a, b);
    umn(a, b);
    del(a, b);
  } else {
    printf("n/a\n");
    return 0;
  }
}

void sum(int a, int b) {
  printf("%d ", a+b);
}

void sub(int a, int b) {
  printf("%d ", a-b);
}

void umn(int a, int b) {
  printf("%d ", a*b);
}

void del(int a, int b) {
  if (a !=0 && b != 0) {
    printf("%d\n", a/b);
  } else {
    printf("n/a\n");
  }
}
