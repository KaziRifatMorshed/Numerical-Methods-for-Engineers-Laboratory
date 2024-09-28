#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <strings.h>
using namespace std;

#define a 0
#define b 1
#define c 2
#define d 3

#define eq1 M[0]
#define eq2 M[1]
#define eq3 M[2]

// example
// a1 = 2.0f, b1 = 1.0f, c1 = 1.0f, d1 = 5.0f;
// a2 = 3.0f, b2 = 5.0f, c2 = 2.0f, d2 = 15.0f;
// a3 = 2.0f, b3 = 1.0f, c3 = 4.0f, d3 = 8.0f;

// coEfficientMatrix[num_equations][num_coEfficients]
int M[3][4]; // coEfficientMatrix

float x1 = 0.0f, x2 = 0.0f, x3 = 0.0f;
float x1_prev = 0.0f, x2_prev = 0.0f, x3_prev = 0.0f;
int n = 0;
const float E = 0.00005f;

void take_three_input() {
  // test case -3x1+55x2-2x3=-5
  for (int eq_no = 0; eq_no < 3; eq_no++) { // take three equation input

    char input_eq[40] = {0};
    int abcd = 0; // co-efficient tracker within row of 2D array
    scanf("%[^\n]", input_eq);

    int prev_idx = 0, str_len = strlen(input_eq);
    /* prev_idx points starting of a substring holding co-efficient*/

    for (int i = 0; i < str_len; i++) { // catch all coefficients

      if (input_eq[i] == 'x' || input_eq[i] == '=') {

        char co_eff[10] = "1";

        if (input_eq[i] == '=') { /* edge case */
          prev_idx++;  /*starting of substring will be position after = sign*/
          i = str_len; /*ending of substring will be last of the string*/
        }

        int co_eff_len = (i - prev_idx);

        /* case like x1+x2+x3=5*/
        if (co_eff_len == 1 && input_eq[prev_idx] == '+') {
          strncpy(co_eff, "1", 1);

          /* case like -x1-x2-x3=-5*/
        } else if (co_eff_len == 1 && input_eq[prev_idx] == '-') {
          strncpy(co_eff, "-1", 2);

        } else {
          strncpy(co_eff, &input_eq[prev_idx], co_eff_len);
        }

        M[eq_no][abcd] = (float)atoi(co_eff);

        abcd++;
        prev_idx = i + 2;
        i++; /*to skip variable name (x1, x2, x3)*/
      }
    }

    getchar(); // dummy
  }
} // working

int main(void) {

  printf("input three equations (in x1+x2-2x3=-5 style, as a string) :\n");
  take_three_input(); // limitation: spaces,float/double will not work

  printf("input iteration limit : ");
  scanf("%d", &n);

  /*Jacobi Iteration Method*/

  for (int i = 1; i <= n; i++) {

    x1 = (eq1[d] - (eq1[b] * x2_prev) - (eq1[c] * x3_prev)) / eq1[a];
    x2 = (eq2[d] - (eq2[c] * x3_prev) - (eq2[a] * x1_prev)) / eq2[b];
    x3 = (eq3[d] - (eq3[a] * x1_prev) - (eq3[b] * x2_prev)) / eq3[c];

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
