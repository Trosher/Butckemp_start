#include <stdio.h>

int del(int res_step, int num);
int prost(int num);
int ft_1948(int num);

int main() {
  int a;
  double a_test;
  if (scanf("%lf", &a_test) == 1) {
    a = a_test;
    if (a != a_test) {
      printf("n/a");
      return 0;
    }
    if (a == 0) {
        printf("n/a");
        return 0;
    }
    if (a < 0) {
        a *= -1;
    }
    if (a == 1) {
        printf("1");
    }
    printf("%d", ft_1948(a));
  } else {
    printf("n/a");
    return 0;
  }
  return 0;
}

int ft_1948(int num) {
    int res = 0;
    int res_step = 2;
    while (res_step <= num) {
        if (prost(res_step) == 1) {
            if (del(res_step, num) == 1) {
               res = res_step;
            }
        }
      ++res_step;
    }
    return res;
}

int del(int res_step, int num) {
    while (num > 0) {
        num = num - res_step;
    }
    if (num == 0) {
        return 1;
    }
    return 0;
}

int prost(int num) {
    int step = 2;
    int step_copy = num;
    while (step <= num) {
        while (step_copy > 0) {
            step_copy = step_copy - step;
        }
        if (step_copy == 0 && step != num) {
            return 0;
        }
        step_copy = num;
        ++step;
    }
    return 1;
}
