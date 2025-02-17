#include <stdio.h>
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
  printf(" i   j  min  max\n");
  printf("[ %d | %d | %d | %d ]\n\n", i + 1, j + 1, *min, *max);
}



int main() {
  // int n=0;
  // printf("Enter the number of inputs in the array : ");
  // scanf("%d",&n);
  // for(int i = 0;i<n;i++){
  //     printf("Enter element %d: ", i + 1);
  //     scanf("%d",&a[i]);
  // }
  int n = 11;
  int temp[] = {24, 76, -4, 58, 23, 86, -14, 25, 89, 23, 43};
  int min, max;
  min = max = a[0];
  for (int i = 0; i < n; i++) {
    a[i] = temp[i];
  }
  minMax(0, n - 1, &min, &max);
  printf("Minimum element in the array is : %d\n", min);
  printf("Maximum element in the array is : %d\n", max);
  return 0;
}