#include <cstdio>
#include <cstdlib>
#include <stdio.h>

// float a1 = 2.0f, b1 = 1.0f, c1 = 1.0f, d1 = 5.0f;
// float a2 = 3.0f, b2 = 5.0f, c2 = 2.0f, d2 = 15.0f;
// float a3 = 2.0f, b3 = 1.0f, c3 = 4.0f, d3 = 8.0f;

float a1 = 0.0f, b1 = 0.0f, c1 = 0.0f, d1 = 0.0f;
float a2 = 0.0f, b2 = 0.0f, c2 = 0.0f, d2 = 0.0f;
float a3 = 0.0f, b3 = 0.0f, c3 = 0.0f, d3 = 0.0f;

float x1 = 0.0f, x2 = 0.0f, x3 = 0.0f;
float x1_prev = 0.0f, x2_prev = 0.0f, x3_prev = 0.0f;
int n = 0;
const float E = 0.00005f;

int main(void) {

  /*Gauss Seid Method*/

  printf("input linear equation in a1x1 + b1x2 + c1x3 = d1 format (spaces "
         "between four numbers): ");
  scanf("%f %f %f %f", &a1, &b1, &c1, &d1);
  printf("input linear equation in a2x1 + b2x2 + c2x3 = d2 format "
         "(spaces between four numbers): ");
  scanf("%f %f %f %f", &a2, &b2, &c2, &d2);
  printf("input linear equation in a3x1 + b3x2 + c3x3 = d3 format "
         "(spaces between four numbers): ");
  scanf("%f %f %f %f", &a3, &b3, &c3, &d3);

  printf("input iteration limit : ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {

    x1 = (d1 - (b1 * x2_prev) - (c1 * x3_prev)) / a1;
    x2 = (d2 - (c2 * x3_prev) - (a2 * x1_prev)) / b2;
    x3 = (d3 - (a3 * x1_prev) - (b3 * x2_prev)) / c3;

    printf("\nIteration no %d:\tx1 = %f, x2 = %f, x3 = %f\n", i, x1, x2, x3);

    if (std::abs(x1 - x1_prev) < E && std::abs(x2 - x2_prev) < E &&
        std::abs(x3 - x3_prev) < E) {

      printf("\n# ANSWER x1 = %f, x2 = %f, x3 = %f", x1, x2, x3);
      break;
    }
  }
  printf("\n\nProgram Completed");
} // DONE