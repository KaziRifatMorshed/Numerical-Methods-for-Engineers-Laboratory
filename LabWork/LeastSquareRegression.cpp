#include <cmath>
#include <cstdio>
// double x[100], y[100];
double sum_x = 0, sum_y = 0, sum_x_sq = 0, sum_x_y = 0;
int n = 0; /*quantity of data*/

int main(void) {
  //   printf("Input quantity of data : ");
  scanf("%d", &n);

  //   printf("\nInput  x and y (with spaces) : ");

  for (int i = 1; i <= n; i++) { /*takin inputs*/
    // printf("\ninput no %d : ", i);
    double x = 0, y = 0;
    scanf("%lf %lf", &x, &y);

    sum_x += x;
    sum_y += y;
    sum_x_sq += std::pow(x, 2);
    sum_x_y += (x * y);
  }

  double b = (n * sum_x_y - sum_x * sum_y) / (n * sum_x_sq - pow(sum_x, 2));
  double a = ((sum_y / n) - (b * sum_x) / n);

  printf("Equation is : y = %2.2lf + %2.2lfx", a, b);
}