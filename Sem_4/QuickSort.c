#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#define MAX 100
int n, flag, flag2;
void print(int arr[], int low, int up);
void interchange(int arr[], int i, int j) {
  int p = arr[i];
  arr[i] = arr[j];
  arr[j] = p;
}
int partition(int arr[], int low, int up) {
  int pivot = arr[low], i, j;
  i = low + 1;
  j = up;
  while (i <= j) {
    while (arr[i] <= pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i < j) {
      interchange(arr, i, j);
      print(arr, low, up);
    }
  }
  arr[low] = arr[j];
  arr[j] = pivot;
  print(arr, low, up);
  printf(" j= %d\n", j);
  return j;
}
int partition2(int arr[], int low, int up) {
  int pivot = arr[low], i, j;
  i = low + 1;
  j = up;
  while (i <= j) {
    while (arr[i] >= pivot)
      i++;
    while (arr[j] < pivot)
      j--;
    if (i < j) {
      interchange(arr, i, j);
      print(arr, low, up);
    }
  }
  arr[low] = arr[j];
  arr[j] = pivot;
  print(arr, low, up);
  printf(" j= %d\n", j);
  return j;
}
void quick_sort(int arr[], int low, int up) {
  int j;
  if (low > up) {
    flag = 1;
  }
  if (low < up) {
    print(arr, low, up);
    j = partition(arr, low, up);
    quick_sort(arr, low, j - 1);
    quick_sort(arr, j + 1, up);
  }
}
void quick_sort2(int arr[], int low, int up) {
  int j;
  if (low > up) {
    flag = 1;
  }
  if (low < up) {
    print(arr, low, up);
    j = partition2(arr, low, up);
    quick_sort2(arr, low, j - 1);
    quick_sort2(arr, j + 1, up);
  }
}
void print(int arr[], int low, int up) {
  printf("\n");
  for (int i = 1; i <= n; i++) {
    if (flag == 1 && i == low - 1) {
      printf("[]");
      flag = 0;
    }
    if (i == low)
      printf("[");
    printf("%d ", arr[i]);
    if (i != up)
      printf("");
    if (i == up)
      printf("] ");
  }
}
int main() {
  printf("Enter the number of elements (max %d): ", MAX - 1);
  scanf("%d", &n);
  if (n >= MAX || n <= 0) {
    printf("Invalid array size!\n");
    return 1;
  }
  int arr[MAX], arr2[MAX];
  printf("Enter %d elements: ", n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &arr[i]);
  for (int i = 1; i <= n; i++)
    arr2[i] = arr[i];
  printf("Ascending order:");
  clock_t start;
  start = clock();
  quick_sort(arr, 1, n);
  clock_t end;
  end = clock();
  double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
  for (int i = 1; i <= n; i++)
    printf("%d ", arr[i]);
  printf("\n\nDescending order:");
  quick_sort2(arr2, 1, n);
  printf("\n");
  for (int i = 1; i <= n; i++)
    printf("%d ", arr2[i]);
  printf("\nExecution time of quick sort function was %f seconds \n",
         time_taken);
  return 0;
}