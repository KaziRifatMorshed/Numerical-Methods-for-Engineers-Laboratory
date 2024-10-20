/*
Personal Header file of Kazi Rifat Morshed (CSEKU230220)
Author: Kazi Rifat Morshed
Date: 05 October 2024


I made this header after গুতাগুতি of about 4 days,
for personal purpose, specially for Numerical Methods for Engineers Laboratory
Course where we were given task to take equations input as strings.

Features:
- take three string input and will separate coefficients to respective
variable(2D Array) internally
- division by zero handled carefully
- Spaces within equations are allowed
- negative number and floating numbers are allowed
- instead of x1, x2, x3; x, y, z are allowed

Limitations:
- Limited to 3 Linear equations of three variables.
- You have to input x1, then x2 and then x3 (in order) or,
x, then y, and then z (in order) [you cannot break this order]
*/

// #include "../header/NumericalMethodsHeaderKaziRifat.h"

#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define a 0
#define b 1
#define c 2
#define d 3

#define eq1 M[0]
#define eq2 M[1]
#define eq3 M[2]
/*Benefit: eq1[a] means first coefficient of first linear equation*/

inline void remove_all_spaces(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      for (int j = i; str[j] != '\0'; j++) {
        str[j] = str[j + 1];
      }
    }
  }
} // DEFINITELY WORK

inline void take_three_input(float M[][4]) {

  for (int eq_no = 0; eq_no < 3; eq_no++) { // take three equation input

    char input_eq[40] = {0};

    int abcd = 0; // co-efficient tracker within row of 2D array
    scanf("%[^\n]", input_eq);
    remove_all_spaces(input_eq);
    printf("%s\n", input_eq);

    int prev_idx = 0, str_len = strlen(input_eq);
    /* prev_idx points starting of a substring holding co-efficient*/

    for (int i = 0; i < str_len; i++) { // catch all coefficients

      if (input_eq[i] == 'x' || input_eq[i] == 'y' || input_eq[i] == 'z' ||
          input_eq[i] == '=') {

        char co_eff[10] = "1";
        /* substring of coefficients, default is 1 for taking benefit
         * from atof() function in case like x1-x2+x3=10*/

        if (input_eq[i] == '=') { /* edge case */
          prev_idx = i + 1; /*start of substring will be position after = sign*/
          i = str_len;      /*ending of substring will be last of the string*/
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
        if (input_eq[i] == 'x' && isalnum(input_eq[i + 1])) {
          i++; /*to skip variable name (x1, x2, x3)*/
        }
      } /*end of "if" block*/
    }

    getchar(); // dummy
  }
} // WORKING

inline void print_three_equations(float M[][4]) {
  // printf("Printing all eq : \n");
  for (int i = 0; i < 3; i++) {
    printf("%.2f\t%.2f\t%.2f\t= %.2f\n", M[i][a], M[i][b], M[i][c], M[i][d]);
  }
  // printf("Printing all eq COMPLETED \n");
} // DONE

inline void polynomial_input() {
  // planned
} // incomplete
