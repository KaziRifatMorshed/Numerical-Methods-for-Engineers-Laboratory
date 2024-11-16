#include "../header/NumericalMethodsHeaderKaziRifat.h"

float M[3][4]; /*coEfficientMatrix[num_equations][num_coEfficients]*/
int n = 3;     // num of equations

void gauss_jordan_operation() {
  for (int i = 0; i < n; i++) {
    float pivot = M[i][i];
    for (int j = 0; j < n; j++) {
      float corres = M[j][i];
      if (i == j || corres == 0.0f) {
        continue;
      }
      float factor = pivot / corres;
      for (int k = a; k <= d; k++) {
        M[j][k] = M[i][k] - (factor * M[j][k]);
      }
    }
  }
  for (int p = 0; p < n; p++) {
    M[p][d] /= M[p][p];
    M[p][p] /= M[p][p];
  }

  print_three_equations(M); /*for debugging purpose*/
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
