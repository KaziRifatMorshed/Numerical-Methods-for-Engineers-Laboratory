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

void take_three_input() {

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

        M[eq_no][abcd] = atof(co_eff);

        abcd++;
        prev_idx = i + 2;
        i++; /*to skip variable name (x1, x2, x3)*/
      } /*end of "if" block*/
    }

    getchar(); // dummy
  }
} // working

int main(void) {

  printf("input three equations (in x1+x2-2x3=-5 style, as a string) :\n");
  take_three_input(); // limitation: spaces will not work

  printf("input iteration limit : ");
  scanf("%d", &n);

  /*Gauss Saidel Method*/

  for (int i = 1; i <= n; i++) {

    /*updated equations*/
    x1 = (eq1[d] - (eq1[b] * x2) - (eq1[c] * x3)) / eq1[a];
    x2 = (eq2[d] - (eq2[c] * x3) - (eq2[a] * x1)) / eq2[b];
    x3 = (eq3[d] - (eq3[a] * x1) - (eq3[b] * x2)) / eq3[c];

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
  printf("\n\nProgram Completed");
} // COMPLETE

// /*
// #include <cstdio>
// #include <cstdlib>
// #include <stdio.h>

// // float a1 = 2.0f, b1 = 1.0f, c1 = 1.0f, d1 = 5.0f;
// // float a2 = 3.0f, b2 = 5.0f, c2 = 2.0f, d2 = 15.0f;
// // float a3 = 2.0f, b3 = 1.0f, c3 = 4.0f, d3 = 8.0f;

// float a1 = 0.0f, b1 = 0.0f, c1 = 0.0f, d1 = 0.0f;
// float a2 = 0.0f, b2 = 0.0f, c2 = 0.0f, d2 = 0.0f;
// float a3 = 0.0f, b3 = 0.0f, c3 = 0.0f, d3 = 0.0f;

// float x1 = 0.0f, x2 = 0.0f, x3 = 0.0f;
// float x1_prev = 0.0f, x2_prev = 0.0f, x3_prev = 0.0f;
// int n = 0;
// const float E = 0.0005f;

// int main(void) {

//   /*Gauss Saidel Method*/

//   printf("input linear equation in a1x1 + b1x2 + c1x3 = d1 format (spaces "
//          "between four numbers): ");
//   scanf("%f %f %f %f", &a1, &b1, &c1, &d1);
//   printf("input linear equation in a2x1 + b2x2 + c2x3 = d2 format "
//          "(spaces between four numbers): ");
//   scanf("%f %f %f %f", &a2, &b2, &c2, &d2);
//   printf("input linear equation in a3x1 + b3x2 + c3x3 = d3 format "
//          "(spaces between four numbers): ");
//   scanf("%f %f %f %f", &a3, &b3, &c3, &d3);

//   printf("input iteration limit : ");
//   scanf("%d", &n);

//   for (int i = 1; i <= n; i++) {

//     x1 = (d1 - (b1 * x2) - (c1 * x3)) / a1;
//     x2 = (d2 - (c2 * x3) - (a2 * x1)) / b2;
//     x3 = (d3 - (a3 * x1) - (b3 * x2)) / c3;

//     printf("\nIteration no %d:\tx1 = %f, x2 = %f, x3 = %f\n", i, x1, x2, x3);

//     if (std::abs(x1 - x1_prev) < E && std::abs(x2 - x2_prev) < E &&
//         std::abs(x3 - x3_prev) < E) {

//       printf("\n# ANSWER x1 = %f, x2 = %f, x3 = %f", x1, x2, x3);
//       break;
//     } else {
//       x1_prev = x1;
//       x2_prev = x2;
//       x3_prev = x3;
//     }
//   }
//   printf("\n\nProgram Completed");
// } // DONE
//*/