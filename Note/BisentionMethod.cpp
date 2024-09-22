#include <cstdio>
#include <cstdlib>

float a = 0.0f, b = 0.0f, c = 0.0f, x1 = 0.0f, x2 = 0.0f, x0 = 0.0f;
int n = 0;

float f(float num) { return ((a * num * num) + (b * num) + c); }

int main(void) {
  printf("Evaluating the root of f(x) = ax^2 + bx + c in Bisection "
         "Method\nPlease input a, b, c (with spaces) : ");
  scanf("%f %f %f", &a, &b, &c);

  printf("input x1 and x2 (with spaces) : "), scanf("%f %f", &x1, &x2);

  printf("Specify iteration number (input 0 (zero) if you do not want to "
         "specify iteration) : "),
      scanf("%d", &n);

  for (int i = 1; i <= n || n == 0; i++) {
    x0 = ((x1 + x2) / 2);
    printf("\nIteration no %d: \n\tx0 = %f", i, x0);
    if (std::abs(f(x0)) < 0.005f) {
      printf("\nroot found\nroot is %f", x0);
      break;
    } else if ((f(x0) * f(x1)) < 0) {
      x2 = x0;
    } else {
      x1 = x0;
    }
  }
  printf("\nProgram Completed");
} // DONE