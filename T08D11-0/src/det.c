#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double det(double **matrix, int n, int m);
int input(double **matrix, int w, int h);
void output(double det);
int input_size(int *w, int *h);
void malloc1(double **array, int w, int h);
int main() {
  double **matrix;
  int w, h;
  int test = 1;
  if (input_size(&w, &h)) {
    matrix = malloc(w * h * sizeof(double) + w * sizeof(double*));
    malloc1(matrix, w, h);
    if (input(matrix, w, h)) {
      double determ = det(matrix, w, h);
      if (determ == -10000)
        test = 0;
      else
        output(determ);
    } else {
      test = 0;
    }
    free(matrix);
  } else {
    test = 0;
  }
  if (test == 0) {
    printf("n/a");
  }
  return 0;
}
void output(double det) {
  printf("%.6lf", det);
}
void malloc1(double **array, int w, int h) {
  double *ptr = (double*)(array + w);
  for (int i = 0; i < w; i++)
    array[i] = ptr + h * i;
}
int input_size(int *w, int *h) {
  int test;
  char c1, c2;
  test = scanf("%d%c%d%c", w, &c1, h, &c2);
  if (test == 4 && c2 == '\n' && c1 == ' ' && *w > 0 && *h > 0)
    return 1;
  else
    return 0;
}
int input(double **matrix, int w, int h) {
  int run = 0;
  char c;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      int test = scanf("%lf%c", &matrix[i][j], &c);
      if (test == 1) {
        continue;
      } else if (test == 2 && j == h-1 && c == '\n') {
        continue;
      } else if (test == 2 && j < h-1 && c == ' ') {
        continue;
      } else if (test == 2 && i < w-1 && c != '\n') {
        run++;
        break;
      } else if (test == 2 && j == h-1 && c != '\n') {
        run++;
        break;
      } else {
        run++;
        break;
      }
    }
  }
  if (run > 0)
    return 0;
  else
    return 1;
}
double det(double **matrix, int n, int m) {
  double determ;
  if (n == m) {
    if (n == 1) {
      determ = matrix[0][0];
    } else if (n == 2) {
      determ = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
      determ = 0;
      for (int k = 0; k < n; k++) {
        double **result = malloc((n - 1) * (n - 1) * sizeof(double*) + (n - 1) * sizeof(double*));
        malloc1(result, n-1, m-1);
        for (int i = 1; i < n; i++) {
          int t = 0;
          for (int j = 0; j < n; j++) {
            if (j == k)
              continue;
            result[i-1][t] = matrix[i][j];
            t++;
          }
        }
        determ += pow(-1, k + 2) * matrix[0][k] * det(result, n-1, m-1);
        free(result);
      }
      return determ;
    }
  } else {
    determ = -10000;
  }
  return determ;
}
