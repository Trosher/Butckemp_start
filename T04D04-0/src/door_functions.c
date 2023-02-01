#include <stdio.h>
#include <math.h>

void an(double x);
void bern(double x);
void gip(double x);

int main(void) {
  double pi;
  double zam;
  double pi_negativ;
  pi = M_PI;
  zam = pi / 21;
  for (pi_negativ = -pi; pi_negativ <= pi; pi_negativ +=  zam) {
    printf("%.7lf | ", pi_negativ);
    an(pi_negativ);
    bern(pi_negativ);
    gip(pi_negativ);
  }
  return 0;
}

void an(double x) {
  double y;
  y = 1.0 / (1.0 + x);
  if (y != 0) {
    printf("%.7lf | ", x);
  } else {
    printf("- | ");
  }
}

void bern(double x) {
  double y;
  y = pow(pow(pow(1.0, 4) + 4.0 * pow(x, 2) * pow(1.0, 2), 0.5) - pow(x, 2) - pow(1.0, 2), 0.5);
  if (y != 0) {
    printf("%.7lf | ", x);
  } else {
    printf("- | ");
  }
}

void gip(double x) {
  double y;
  y = 1.0 / pow(x, 2);
  if (y != 0) {
    printf("%.7lf\n", x);
  } else {
    printf("-\n");
  }
}
