#include <stdio.h>

int ft_fibonacci(int index) {
    if (index >= 0 && index <= 47) {
        if (index == 1 || index == 2) {
            return 1;
        } else  if (index == 0) {
            return 0;
        }
        return ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
    } else if (index > 47) {
        return 0;
    }
    return -1;
}

int main(void) {
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
        printf("n/a");
        return 0;
    }
    a = ft_fibonacci(a);
    if (a > 0) {
    printf("%d", a);
    } else {
    printf("n/a");
    }
  } else {
    printf("n/a");
    return 0;
  }
  return 0;
}
