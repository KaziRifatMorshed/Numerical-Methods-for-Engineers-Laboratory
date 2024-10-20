#include <cstdio>
#include <stack>
/*array for storing coefficients of polynomials*/
float poly_x[100] = {0}, height_degree_x = 0;
float poly_xy[100] = {0}, degree_xy = 0;
float poly_y[100] = {0}, height_degree_y = 0;
float num_const = 0.0f;
float denom_const = 0.0f;

float x_prev = 0.0f, y_prev = 0.0f;
char str[200] = {0};

int get_division_sign_index(char *str) {
  std::stack<char> sign;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '/') {
      return i;
    }
  }
  return -1;
}

float numerator(float x, float y) {
  float num = 0.0f;

  return num;
}

float denominator() { // skipped for next
  float denom = 1.0f;
  return denom;
}

float f(float x, float y) {

  float num = numerator(x, y);
  float denomi = 0.0f;
  if (get_division_sign_index(str) == -1) { /*no denominator*/
    denomi = 1;
  } else {
    denomi = denominator();
  }
  return num / denomi;
}

void remove_all_spaces(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      for (int j = i; str[j] != '\0'; j++) {
        str[j] = str[j + 1];
      }
    }
  }
}

void take_eq_input() {
  scanf("%[^\n]s", str);
  remove_all_spaces(str);
}

int main(void) { take_eq_input(); }
