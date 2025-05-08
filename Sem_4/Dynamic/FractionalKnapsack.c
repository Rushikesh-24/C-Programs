#include <limits.h>
#include <stdio.h>
void knapsack(int m, int n) {
  float x[n], wixi = 0.0, pixi = 0.0, u;
  float w[11], p[11], op[11];
  float f[11] = {0.0, 0.5, 0.5, 0.34, 0.34, 0.25, 0.2, 0.16, 0.14, 0.125, 0.11};
  int max, min, index, i, j;
  printf("Enter weights: ");
  for (i = 1; i <= n; i++)
    scanf("%f", &w[i]);
  printf("Enter profit: ");
  for (i = 1; i <= n; i++)
    scanf("%f", &p[i]);
  for (i = 1; i <= n; i++) {
    wixi += (f[i] * w[i]);
    pixi += (f[i] * p[i]);
  }
  printf("%15s", " ");
  printf("x1   x2   x3   x4   x5   x6   x7   x8   x9   x10   wixi   pixi\n");
  printf("%15s", " ");
  printf("1/2  1/2  1/3  1/3  1/4  1/5  1/6  1/7  1/8  1/9   %.2f  %.2f\n", wixi, pixi);
  for (i = 1; i <= n; i++)
    x[i] = 0.0;
  u = m;
  for (i = 1; i <= n; i++) {
    max = INT_MIN;
    for (j = 1; j <= n; j++) {
      if (p[j] > max && x[j] != 1) {
        max = p[j];
        index = j;
      }
    }
    if (w[index] > u)
      break;
    x[index] = 1.0;
    u -= w[index];
  }
  if (i <= n)
    x[index] = u / w[index];
  printf("%-15s", "Max Profit");
  for (i = 1; i <= n; i++)
    printf("%.1f  ", x[i]);
  wixi = 0;
  pixi = 0;
  for (i = 1; i <= n; i++) {
    wixi += (x[i] * w[i]);
    pixi += (x[i] * p[i]);
  }
  printf(" %.2f %.2f\n", wixi, pixi);
  for (i = 1; i <= n; i++)
    x[i] = 0.0;
  u = m;
  for (i = 1; i <= n; i++) {
    min = INT_MAX;
    for (j = 1; j <= n; j++) {
      if (w[j] < min && x[j] != 1) {
        min = w[j];
        index = j;
      }
    }
    if (w[index] > u)
      break;
    x[index] = 1.0;
    u -= w[index];
  }
  if (i <= n)
    x[index] = u / w[index];
  printf("%-15s", "Least Weight");
  for (i = 1; i <= n; i++)
    printf("%.1f  ", x[i]);
  wixi = 0;
  pixi = 0;
  for (i = 1; i <= n; i++) {
    wixi += (x[i] * w[i]);
    pixi += (x[i] * p[i]);
  }
  printf(" %.2f %.2f\n", wixi, pixi);
  for (i = 1; i <= n; i++) {
    op[i] = p[i] / w[i];
    x[i] = 0.0;
  }
  u = m;
  for (i = 1; i <= n; i++) {
    max = INT_MIN;
    for (j = 1; j <= n; j++) {
      if (op[j] > max && x[j] != 1) {
        max = op[j];
        index = j;
      }
    }
    if (w[index] > u)
      break;
    x[index] = 1.0;
    u -= w[index];
  }
  if (i <= n)
    x[index] = u / w[index];
  printf("%-15s", "pi/wi");
  for (i = 1; i <= n; i++)
    printf("%.1f  ", x[i]);
  wixi = 0;
  pixi = 0;
  for (i = 1; i <= n; i++) {
    wixi += (x[i] * w[i]);
    pixi += (x[i] * p[i]);
  }
  printf(" %.2f %.2f\n", wixi, pixi);
}
int main() {
  int m, n;
  printf("Enter the knapsack capacity: ");
  scanf("%d", &m);
  printf("Enter number of elements in knapsack: ");
  scanf("%d", &n);
  knapsack(m, n);
  return 0;
}
