#include <cstdio>
float low_limit = 0.0f, upper_limit = 0.0f, h = 0.0f, result = 0.0f;

float f(float x) { return 1 / (1 + x); }

int main(void) {
  printf("input lower limit : ");
  scanf("%f", &low_limit);
  printf("\ninput upper limit : ");
  scanf("%f", &upper_limit);
  printf("\ninput h : ");
  scanf("%f", &h);

  float x = low_limit;
  for (int i = 1; x <= upper_limit; x += h, i++) {
    if (i == 1 || x == upper_limit) {
      result += f(x);
    } else if (i % 3 == 0) {
      result += 2 * f(x);
    } else if (i % 3 != 0) {
      result += 3 * f(x);
    }
  }
  result *= (3.0 / 8.0) * h;
  printf("\n\nresult = %f", result);
}