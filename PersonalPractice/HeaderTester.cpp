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
*/

float M[3][4]; /*coEfficientMatrix[num_equations][num_coEfficients]*/
int n = 3;     // num of equations

int main(void) {

  printf("input three equations (in x1+x2-2x3=-5 style, as a string) :\n");
  take_three_input(M);

  print_three_equations(M);

  printf("\n\nProgram Completed");
} //
