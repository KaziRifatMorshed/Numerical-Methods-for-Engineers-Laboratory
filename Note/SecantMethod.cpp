#include <cstdio>
#include <cstdlib>

float a = 1.0f, b = -4.0f, c = -10.0f;
float x1 = 4.0f, x2 = 2.0f, x3 = 0.0f;
const float E = 0.0005f;

float f(float num) { return ((a * num * num) + (b * num) + c); }

int main(void) {

  //   printf("Evaluating the root of f(x) = ax^2 + bx + c in Secant "
  //          "Method\nPlease input a, b, c (with spaces) : ");
  //   scanf("%f %f %f", &a, &b, &c);

  //   printf("input x1 and x2 (with spaces) : ");
  //   scanf("%f %f", &x1, &x2);

  for (int i = 1;; i++) {

    x3 = (x1 - ((f(x1) * (x2 - x1)) / (f(x2) - f(x1))));
    printf("\nIteration no %d: \n\tx3 = %f", i, x3);

    if (std::abs((x3 - x2) / x3) < E) {
      printf("\n# root found\n# root is %f", x3);
      break;
    } else {
      x1 = x2;
      x2 = x3;
    }
  }

  printf("\nProgram Completed");
} // DONE