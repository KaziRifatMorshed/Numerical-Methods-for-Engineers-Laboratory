#include <bits/stdc++.h>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <vector>

/*array for storing coefficients of polynomials*/
/* these are for numerator only */
float poly_x[100] = {0}, height_degree_x = 0;
float poly_xy[100] = {0}, degree_xy = 0;
float poly_y[100] = {0}, height_degree_y = 0;
float num_const = 0.0f;
float denom_const = 0.0f;

float x_prev = 0.0f, y_prev = 0.0f;
char str[200] = {0};

int get_division_sign_index(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '/') {
      return i;
    }
  }
  return -1;
}

float numerator(float x, float y) {
  float num = 0.0f;
  // std::stack<char> sign;
  // remove all first brackets
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '(' || str[i] == ')') {
      for (int j = i; str[j] != '\0'; j++) {
        str[j] = str[j + 1];
      }
    }
  }

  /*fill coefficients of x*/
  for (int i = 0; str[i] != '\0'; i++) {
    if (i < strlen(str) - 1 && str[i] == 'x' && str[i + 1] == '^') {
      std::vector<char> power_vector;
      for (int k = i + 2; isdigit(str[k]); k++) {
        power_vector.push_back(str[k]);
      }
      std::string temp(power_vector.begin(), power_vector.end());
      int power_of_x = atoi(temp.c_str());

      std::vector<char> coeff_vector;
      float current_coefficient = 1.0f;
      for (int k = i - 1; i <= 0; k--) {
        if ((str[k] = '+' || str[k] == '-' || isdigit(str[k]))) {
          coeff_vector.push_back(str[k]);
        }

        if ((str[k] = '+' || str[k] == '-')) {
          coeff_vector.reserve(coeff_vector.size());
          std::string temp(coeff_vector.begin(), coeff_vector.end());
          current_coefficient *= atof(temp.c_str());
        }
      }
    }
  }

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
