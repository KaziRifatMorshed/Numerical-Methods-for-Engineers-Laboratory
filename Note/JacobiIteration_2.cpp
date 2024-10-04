#include "../header/NumericalMethodsHeaderKaziRifat.h"

/* EXAMPLE
2x1+x2+x3=5
3x1+5x2+2x3=15
2x1+x2+4x3=8
200
*/

float M[3][4]; /*coEfficientMatrix[num_equations][num_coEfficients]*/

float x1 = 0.0f, x2 = 0.0f, x3 = 0.0f;
float x1_prev = 0.0f, x2_prev = 0.0f, x3_prev = 0.0f;
int n = 0; /*iteration limit*/
const float E = 0.00005f;

void JacobiIterationOperation() {
  for (int i = 1; i <= n; i++) {

    x1 = (eq1[d] - (eq1[b] * x2_prev) - (eq1[c] * x3_prev)) / eq1[a];
    x2 = (eq2[d] - (eq2[c] * x3_prev) - (eq2[a] * x1_prev)) / eq2[b];
    x3 = (eq3[d] - (eq3[a] * x1_prev) - (eq3[b] * x2_prev)) / eq3[c];

    printf("\nIteration no %d:\tx1 = %f, x2 = %f, x3 = %f\n", i, x1, x2, x3);

    if (abs(x1 - x1_prev) < E && abs(x2 - x2_prev) < E &&
        abs(x3 - x3_prev) < E) {
      /*checking absolute error within specified range*/

      printf("\n# ANSWER x1 = %f, x2 = %f, x3 = %f", x1, x2, x3);
      break;

    } else {
      x1_prev = x1;
      x2_prev = x2;
      x3_prev = x3;
    }
  }
}

int main(void) {

  printf("input three equations :\n");
  take_three_input(M);

  printf("input iteration limit : ");
  scanf("%d", &n);

  /*Jacobi Iteration Method*/
  JacobiIterationOperation();

  printf("\n\nProgram Completed");
} // COMPLETE
