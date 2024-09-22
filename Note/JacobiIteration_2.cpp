#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
using namespace std;

#define a 0
#define b 1
#define c 2
#define d 3

// example
// a1 = 2.0f, b1 = 1.0f, c1 = 1.0f, d1 = 5.0f;
// a2 = 3.0f, b2 = 5.0f, c2 = 2.0f, d2 = 15.0f;
// a3 = 2.0f, b3 = 1.0f, c3 = 4.0f, d3 = 8.0f;

// coEfficientMatrix[num_equations][num_coEfficients]
int coEfficientMatrix[3][4];
#define M coEfficientMatrix

float x1 = 0.0f, x2 = 0.0f, x3 = 0.0f;
float x1_prev = 0.0f, x2_prev = 0.0f, x3_prev = 0.0f;
int n = 0;
const float E = 0.00005f;

void take_three_input() {
  // test case -3x1+55x2-2x3=-5
  for (int eq_no = 0; eq_no < 3; eq_no++) { // take three equation input

    char input_eq[20];
    int left_idx = -1, str_len = strlen(input_eq);
    int abcd = 0; // co-efficient tracker
    scanf("%[^\n]", input_eq);

    for (int i = 0; input_eq[i] != '\0'; i++) { // catch all coefficients

      if ((input_eq[i] == 'x' && input_eq[i + 1] == ('1' + i))) {

        M[eq_no][abcd] = atoi(strncpy(input_eq, &input_eq[sign_idx], str_len));

        printf("..%d..", M[eq_no][abcd]);
        abcd++;
        left_idx = i;
        i += 2;
      }
    }

    getchar(); // dummy
  }
}

int main(void) {

  printf("input three equations (in 3x1+5x2-2x3=-5 style, as a string) :\n");
  take_three_input(); // limitation: spaces,float/double will not work

  printf("input iteration limit : ");
  scanf("%d", &n);

  /*Jacobi Iteration Method*/

  for (int i = 1; i <= n; i++) {

    x1 = (M[0][d] - (M[0][b] * x2_prev) - (M[0][c] * x3_prev)) / M[0][a];
    x2 = (M[1][d] - (M[1][c] * x3_prev) - (M[1][a] * x1_prev)) / M[1][b];
    x3 = (M[2][d] - (M[2][a] * x1_prev) - (M[2][b] * x2_prev)) / M[2][c];

    printf("\nIteration no %d:\tx1 = %f, x2 = %f, x3 = %f\n", i, x1, x2, x3);

    if (abs(x1 - x1_prev) < E && abs(x2 - x2_prev) < E &&
        abs(x3 - x3_prev) < E) {

      printf("\n# ANSWER x1 = %f, x2 = %f, x3 = %f", x1, x2, x3);
      break;

    } else {
      x1_prev = x1;
      x2_prev = x2;
      x3_prev = x3;
    }
  }
  printf("\n\nProgram Completed");
} // INCOMPLETE

// ======================================================================

/*
ADVANCED

void take_three_input() {
  // test case -3x1+5x2-2x3=-5
  for (int eq_no = 0; eq_no < 3; eq_no++) { // take three equation input

    char input_eq[20];
    bool isNegative = false;
    int sign_idx = -1, prev_idx = -1;
    int abcd = 0; // co-efficient tracker
    scanf("%[^\n]", input_eq);

    for (int i = 0; input_eq[i] != '\0'; i++) { // catch all coefficients

      if (input_eq[i] == '-') {
        sign_idx = i;
        isNegative = true;
      }

      if (input_eq[i] == 'x' && input_eq[i + 1] == ('1' + i)) {

        M[eq_no][abcd] =
            atoi(strncpy(input_eq, &input_eq[sign_idx + 1], strlen(input_eq)));

        if (isNegative) {
          M[eq_no][abcd] *= -1;
          isNegative = false;
        }
        printf("..%d..", M[eq_no][abcd]);
        abcd++;
        prev_idx = i;
      }
      if (input_eq[i] == '=') {
        sign_idx = i;
        M[eq_no][abcd] =
            atoi(strncpy(input_eq, &input_eq[sign_idx + 1], strlen(input_eq)));
        printf("..%d..", M[eq_no][abcd]);
      }
    }

    getchar(); // dummy
  }
}
*/