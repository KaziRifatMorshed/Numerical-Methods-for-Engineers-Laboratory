#include <cmath>
#include <cstdio>
#include <cstdlib>

float a = 0.0f, b = 0.0f, c = 0.0f, x_n_prev = 0.0f, x_n = 0.0f;
int n = 0;

float f(float num) { return ((a * num * num) + (b * num) + c); }

float f_(float num) { return ((a * 2 * num) + (b)); }

int main(void) {
  printf("Evaluating the root of f(x) = ax^2 + bx + c in Newton-Raphson "
         "Method\nPlease input a, b, c (with spaces) : ");
  scanf("%f %f %f", &a, &b, &c);

  for (int i = 1;; i++, x_n_prev = x_n) {

    x_n = (float)(x_n_prev - (float)(f(x_n_prev) / f_(x_n_prev)));

    printf("x_%d = %f\n", i, x_n);

    if (fabs(x_n - x_n_prev) < 0.00005f) { // DO NOT USE `abs()`, use `fabs()`
      printf("Root Found.\nRoot is %f", x_n);
      break;
    }
  }
  printf("\nProgram Completed");
} // DONE