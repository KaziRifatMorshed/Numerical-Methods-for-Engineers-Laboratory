#include "../header/NumericalMethodsHeaderKaziRifat.h"

/* EXAMPLE
Basic Gauss Example
3x1+6x2+x3=16
2x1+4x2+3x3=13
x1+3x2+2x3=9

Gauss Jordan Example
2x1+4x2-6x3=-8
x1+3x2+x3=10
2x1-4x2-2x3=-12

4x + 10y + 30z = 62
10x + 30y + 100z = 190
30x + 100y + 354z = 644
3, 2, 1
*/

float M[3][4]; /*coEfficientMatrix[num_equations][num_coEfficients]*/
int n = 3;     // num of equations

void gauss_jordan_operation() {
  for (int i = 0; i < n; i++) {

    float pivot_value = M[i][i];

    for (int j = 0; j < n; j++) {

      float corres = M[j][i]; /*correspondent_position_to_pivot*/
      if (i == j || corres == 0.0f) {
        continue;
      }
      float factor = pivot_value / corres;

      /*now, loop for subtracting one eq from another*/
      for (int k = a; k <= d; k++) {
        M[j][k] = M[i][k] - (factor * M[j][k]);
      }
    }
    // print_three_equations(); /*for debugging purpose*/
  }

  for (int p = 0; p < n; p++) {
    M[p][d] /= M[p][p]; /*ultimately, d1, d2, d3*/
    M[p][p] /= M[p][p]; /*ultimately, x1. x2, x3*/
  }
} // working

int main(void) {

  printf("input three equations :\n");
  take_three_input(M); // limitation: spaces will not work

  /*Gauss Jordan Method*/

  gauss_jordan_operation();

  // print_three_equations(M);

  printf("# RESULT : x1 = %.2f, x2 = %.2f, x3 = %.2f\n", eq1[d], eq2[d],
         eq3[d]);

  printf("\n\nProgram Completed");
} // DONE
