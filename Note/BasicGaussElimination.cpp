#include "../header/NumericalMethodsHeaderKaziRifat.h"
#include <cstdio>

/* EXAMPLE
Basic Gauss Example
3x1+6x2+x3=16
2x1+4x2+3x3=13
x1+3x2+2x3=9

Gauss Jordan Example
2x1+4x2-6x3=-8
x1+3x2+x3=10
2x1-4x2-2x3=-12
// ISSUE: same eq ulta kore input deoay kaj korse na
*/

float M[3][4]; /*coEfficientMatrix[num_equations][num_coEfficients]*/
int n = 3;     // num of equations
float x1 = 0.0f, x2 = 0.0f, x3 = 0.0f;

void basic_gauss_operation() {
  for (int i = 0; i < (n - 1); i++) {

    float pivot_value = M[i][i];

    for (int j = 0; j < n; j++) {

      // printf("i = %d , j = %d\n", i, j);
      float corres = M[j][i]; /*correspondent_position_to_pivot*/
      if (i >= j || corres == 0.0f) {
        continue;
      }
      float factor = pivot_value / corres;

      /*now, loop for subtracting one eq from another*/
      for (int k = a; k <= d; k++) {
        M[j][k] = M[i][k] - (factor * M[j][k]);
      }
      // print_three_equations(M); /*for debugging purpose*/
      // printf("\n");
    }
  }

} // DONE

void backtracking_basic_gauss_elimination() {
  x3 = eq3[d] / eq3[c];
  x2 = (eq2[d] - (x3 * eq2[c])) / eq2[b];
  x1 = (eq1[d] - (x3 * eq1[c]) - (x2 * eq1[b])) / eq1[a];

  printf("# RESULT : x1 = %.2f, x2 = %.2f, x3 = %.2f\n", x1, x2, x3);
}

int main(void) {

  printf("input three equations :\n");
  take_three_input(M); // limitation: spaces will not work

  /*Basic Gauss Elimination Method*/

  basic_gauss_operation();

  // print_three_equations(M);

  backtracking_basic_gauss_elimination();

  printf("\n\nProgram Completed");
} // DONE
