#include <cmath>
#include <cstdio>
float coefficients[4];
#define co coefficients

#define a 0
#define b 1
#define c 2
#define d 3

float h = 0.0f, y_first = 0.0f, y_prev = 0.0f, end = 0.0f;

float f(float x) {
  return co[a] * std::pow(x, 3) + co[b] * pow(x, 2) + co[c] * x + co[d];
}

void take_coefficient_input() {
  for (int i = 0; i < 4; i++) {
    scanf("%f", &co[i]);
  }
}

void euler() {
  for (float i = 1; i <= end; i += h) {

    if (i == 1) {
      y_prev = y_first;
      printf("y(%0.2f) = %0.4f\n", i, y_prev);
      continue;
    }

    y_prev += h * f(i - h); // -------------------------- CAREFUL
    printf("y(%0.2f) = %0.4f\n", i, y_prev);
  }
}

int main(void) {
  printf("input coefficients of dy/dx = ax^3+bx^2+cx+d : \n");
  take_coefficient_input();

  printf("\n input h : ");
  scanf("%f", &h);

  printf("\n input y(1) = ? \n");
  scanf("%f", &y_first);

  printf("\n input y(end) : end = ? \n");
  scanf("%f", &end);

  euler();
  // end
}