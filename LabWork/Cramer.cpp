#include "../header/NumericalMethodsHeaderKaziRifat.h"
#include <cstdio>

// 4 x1 + 10 x2 + 30 x3 = 62
// 10 x1 + 30 x2 + 100 x3 = 190
// 30 x1 + 100 x2 + 354 x3 = 644

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
  printf("input 3 equations: \n");
  take_three_input(M);
  Cramer();
  printf("\nResult x1 = %0.2f , x2 = %0.2f, x3 = %0.2f", x1, x2, x3);
} // done