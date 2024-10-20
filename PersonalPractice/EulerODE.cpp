
#include <cstdio>
#include <cstdlib>
#include <cstring>

float eq_coefficients[100] = {0};
int eq_coefficients_tracker = 0;
float x0 = 0.0f, y0 = 0.0f, x = 0.0f, y = 0.0f, h = 0.0f, order = 0.0f;
int n = 0;

// dy / dx
// 3x^2 + 1

float f(float x, float y) { return 0; }

void remove_all_spaces(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      for (int j = i; str[j] != '\0'; j++) {
        str[j] = str[j + 1];
      }
    }
  }
} // DEFINITELY WORK

void take_eq_input() {
  char str[] = {0};
  scanf("%[^\n]s", str);

  /*remove spaces*/
  remove_all_spaces(str);

  /*get order*/
  for (int i = 0; str[i - 2] != '\0'; i++) {
    if (str[i] == 'x' && str[i + 1] == '^') {
      if (str[i + 2] - '0' > order) {
        order = str[i + 2] - '0';
      }
    }
  }

  int prev_idx = 0;
  char coefficient[] = {0};
  for (int j = 0; str[j - 2] != '\0'; j++) {
    for (int i = 0; str[i - 2] != '\0'; i++) {

      /*track sign of the coefficient*/
      float current_co_eff_value = 0.0f;
      if (str[i] == '+' || str[i] == '-') {
        prev_idx = i;
        continue;
      }
      if (str[i] == 'x') {
        strncpy(coefficient, &str[prev_idx], i - 1);
        printf("%s", coefficient); // debugging
        eq_coefficients[eq_coefficients_tracker] = atof(coefficient);
        eq_coefficients_tracker++;
      }

      if (str[i] == 'x' && str[i + 1] == '^') {
      }
    }
  }
}

int main(void) {
  printf("input h : ");
  scanf("%f", &h);
  printf("input x0 and y0 : ");
  scanf("%f %f", &x0, &y0);
}