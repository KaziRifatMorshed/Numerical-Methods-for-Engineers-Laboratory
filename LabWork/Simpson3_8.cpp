#include <cstdio>
float low_limit = 0.0f, upper_limit = 0.0f, h = 0.0f, result = 0.0f;

float f(float x) { return 1 / (1 + x); }

int main(void) {
  printf("input lower limit : ");
  scanf("%f", &low_limit);
  printf("input upper limit : ");
  scanf("%f", &upper_limit);
  printf("input h : ");
  scanf("%f", &h);

  float x = low_limit;
  for (int i = 0; x <= upper_limit; x += h, i++) {
    float f_x = f(x);
    printf("\n x =  %4.4f & f(x) = %4.4f", x, f_x);
    if (i == 0 || x == upper_limit) {
      result += f_x;
    } else if (i % 3 == 0) {
      result += 2 * f_x;
    } else {
      // } else if (i % 3 != 0) {
      result += 3 * f_x;
    }
  }
  result *= (3.0 / 8.0) * h;
  printf("\n\nresult = %f", result);
}