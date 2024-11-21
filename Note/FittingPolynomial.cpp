/*Fitting Polynomial Equations*/
#include "../header/NumericalMethodsHeaderKaziRifat.h"
#include <cmath>
#include <cstdio>

float sum_x = 0, sum_y = 0, sum_x_2 = 0, sum_x_3 = 0, sum_x_4 = 0;
float sum_y_x = 0, sum_y_x_2 = 0, sum_y_x_3 = 0;
int n = 0; /*quantity of data*/
float M[3][4];
float D = 0.0f, D_x = 0.0f, D_y = 0.0f, D_z = 0.0f;
float x1 = 0.0f, x2 = 0.0f, x3 = 0.0f;

float Det(int col1, int col2, int col3) {
  // column index might be 0,1,2,3
  float result = eq1[col1] * (eq2[col2] * eq3[col3] - eq3[col2] * eq2[col3]);
  result -= eq1[col2] * (eq2[col1] * eq3[col3] - eq3[col1] * eq2[col3]);
  result += eq1[col3] * (eq2[col1] * eq3[col2] - eq3[col1] * eq2[col2]);
  return result;
}

void Cramer() {
  D = Det(0, 1, 2);
  D_x = Det(3, 1, 2);
  D_y = Det(0, 3, 2);
  D_z = Det(0, 1, 3);

  x1 = D_x / D;
  x2 = D_y / D;
  x3 = D_z / D;
}

int main(void) {
  printf("Input quantity of data : ");
  scanf("%d", &n);
  printf("Input  x and y (with spaces) : \n");

  for (int i = 1; i <= n; i++) { /*taking inputs*/
    printf("input no %d : ", i);
    double x = 0, y = 0;
    scanf("%lf %lf", &x, &y);

    sum_x += x;
    sum_y += y;
    sum_x_2 += std::pow(x, 2);
    sum_x_3 += std::pow(x, 3);
    sum_x_4 += std::pow(x, 4);
    sum_y_x += (x * y);
    sum_y_x_2 += (std::pow(x, 2) * y);
  }

  /* Assign values to matrix for performing Cramer Rule */
  eq1[a] = n, eq1[b] = sum_x, eq1[c] = sum_x_2, eq1[d] = sum_y;
  eq2[a] = sum_x, eq2[b] = sum_x_2, eq2[c] = sum_x_3, eq2[d] = sum_y_x;
  eq3[a] = sum_x_2, eq3[b] = sum_x_3, eq3[c] = sum_x_4, eq3[d] = sum_y_x_2;
  Cramer();

  printf("\n Eq: y = %4.4f + %4.4f x + %4.4f x^2", x1, x2, x3);
}