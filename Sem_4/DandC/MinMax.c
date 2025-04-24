#include <stdio.h>
#include <time.h>
#define MAX 100
int a[MAX];

void minMax(int i, int j, int *min, int *max) {
  if (i == j) {
    *min = *max = a[i];
  } else if (i == j - 1) {
    if (a[i] < a[j]) {
      *min = a[i];
      *max = a[j];
    } else {
      *min = a[j];
      *max = a[i];
    }
  } else {
    int mid = (i + j) / 2;
    int min1, max1;
    min1 = *min;
    max1 = *max;
    minMax(i, mid, &min1, &max1);
    minMax(mid + 1, j, min, max);
    if (*min > min1) {
      *min = min1;
    }
    if (*max < max1) {
      *max = max1;
    }
  }
  printf("|%4d |%4d |%5d |%5d |\n", i, j, *min, *max);
}

int main() {
  int n = 0;
  printf("Enter the number of inputs in the array : ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &a[i]);
  }
  int min, max;
  min = max = a[0];
  printf("|  i  |  j  | min  | max  |\n");
  printf("|-----|-----|------|------|\n");
  clock_t start = clock();
  minMax(0, n - 1, &min, &max);
  clock_t end = clock();
  double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Minimum element in the array is : %d\n", min);
  printf("Maximum element in the array is : %d\n", max);
  printf("Execution time of minmax function was %f seconds\n", time_taken);
  return 0;
}