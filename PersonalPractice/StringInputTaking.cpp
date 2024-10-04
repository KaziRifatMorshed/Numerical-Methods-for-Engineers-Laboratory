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

void remove_all_spaces(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      for (int j = i; str[j] != '\0'; j++) {
        str[j] = str[j + 1];
      }
    }
  }
}

void take_three_input() {

  for (int eq_no = 0; eq_no < 3; eq_no++) { // take three equation input

    char input_eq[40] = {0};

    int abcd = 0; // co-efficient tracker within row of 2D array
    scanf("%[^\n]", input_eq);
    remove_all_spaces(input_eq);
    printf("%s\n", input_eq);

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
} //

void print_three_equations() {
  // printf("Printing all eq : \n");
  for (int i = 0; i < n; i++) {
    printf("%.2f\t%.2f\t%.2f\t= %.2f\n", M[i][a], M[i][b], M[i][c], M[i][d]);
  }
  // printf("Printing all eq COMPLETED \n");
} // working

int main(void) {

  printf("input three equations (in x1+x2-2x3=-5 style, as a string) :\n");
  take_three_input(); // limitation: spaces will not work

  print_three_equations();

  printf("\n\nProgram Completed");
} // DONE
