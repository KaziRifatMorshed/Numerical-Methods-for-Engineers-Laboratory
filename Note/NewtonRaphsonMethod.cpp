#include <cmath>
#include <cstdio>
#include <cstdlib>

float a = 0.0f, b = 0.0f, c = 0.0f, d = 0.0f, x_n_prev = 0.0f, x_n = 0.0f;
int n = 0;
const float E = 0.00005f;

float f(float num) {
  return ((a * num * num * num) + (b * num * num) + (c * num) + d);
}

float f_(float num) { return ((3 * a * num * num) + (2 * b * num) + c); }

int main(void) {
  printf("Evaluating the root of f(x) = ax^3 + bx^2 + cx + d in Newton-Raphson "
         "Method\nPlease input a, b, c, d (with spaces) : ");
  scanf("%f %f %f %f", &a, &b, &c, &d);

  for (int i = 1;; i++, x_n_prev = x_n) {

    x_n = (float)(x_n_prev - (float)(f(x_n_prev) / f_(x_n_prev)));

    printf("x_%d = %f\n", i, x_n);

    if (fabs(x_n - x_n_prev) < E) {
      printf("\nRoot Found.\nRoot is %f", x_n);
      break;
    }
  }
  printf("\nProgram Completed");
} // DONE