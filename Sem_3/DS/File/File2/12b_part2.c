#include <math.h>
#include <stdio.h>
void restoreDown(int arr[], int i, int size) {
  int left = 2 * i + 1, right = left + 1;
  int num = arr[i];
  while (right < size) {
    if (num <= arr[left] && num <= arr[right]) {
      arr[i] = num;
      return;
    } else if (arr[left] < arr[right]) {
      arr[i] = arr[left];
      i = left;
    } else {
      arr[i] = arr[right];
      i = right;
    }
    left = 2 * i + 1;
    right = left + 1;
  }
  if (left < size && num > arr[left]) {
    arr[i] = arr[left];
    i = left;
  }
  arr[i] = num;
}
void treePrint(int arr[], int size, int levels) {
  int n = 0;
  for (int level = 0; level <= levels; level++) {
    int nodes = pow(2, level);
    int spaces = pow(2, levels - level + 1) - 1;
    int inispace = pow(2, levels - level) - 1;
    for (int i = 0; i < inispace; i++)
      printf(" ");
    for (int i = 0; i < nodes && n < size; i++) {
      if (arr[n] != -1) {
        printf("%d", arr[n]);
        if (i < nodes - 1) {
          for (int j = 0; j < spaces; j++)
            printf(" ");
        }
      } else {
        printf(" ");
        if (i < nodes - 1) {
          for (int j = 0; j < spaces; j++)
            printf(" ");
        }
      }
      n++;
    }
    printf("\n");
  }
}
int del_root(int arr[], int *size) {
  int min = arr[0];
  arr[0] = arr[*size - 1];
  (*size)--;
  restoreDown(arr, 0, *size);
  return min;
}

void buildHeap(int arr[], int size) {
  for (int i = size / 2 - 1; i >= 0; i--)
    restoreDown(arr, i, size);
}

void display(int arr[], int size) {
  printf("\n|");
  for (int i = 0; i < size; i++)
    printf("%d |", arr[i]);
  printf("\n");
}

int calculateLevels(int size) { 
  return log2(size); 
}
void printlines(){
   //printf("\n");
 for(int i=0; i<16; i++)
 printf("----");
 //printf("\n");
}
void heap_sort(int arr[], int size) {
  int ori=size, min, a = 1;
  buildHeap(arr, size);
  printf("PHASE 2:\n");
  treePrint(arr, size, calculateLevels(size));
  while (size > 0 && a < 16) {
    min = del_root(arr, &size);
    arr[size] = min;
    printf("\nPASS %d: \n", a++);
    treePrint(arr, size, calculateLevels(size));
    printlines();
    display(arr, ori);
    printlines();
  }
}
int partition(int arr[], int low, int up) {
    int i, j, pivot, temp;
    pivot = arr[low];
    i = low + 1;
    j = up;
    while (i <= j) {
        while (arr[i] > pivot && i <= up)
            i++;
        while (arr[j] < pivot && j >= low)
            j--;
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

void quickSort(int arr[], int low, int up) {
    int pivloc;
    if (low >= up)
        return;
    pivloc = partition(arr, low, up);
    printf("      ");
    printlines();
    printf("\nPass: |");
    for (int i = 0; i < 16; i++) {
        printf("%2d |", arr[i]);
    }
    printf("\n      ");
    printlines();
    printf("\n");
    quickSort(arr, low, pivloc - 1);
    quickSort(arr, pivloc + 1, up);
}


int main() {
  int arr[] = {55, 12, 62, 58, 53, 44, 64, 70, 71, 85, 56, 65, 94, 15, 17, 16};
  int n = 16;
  printf("Heap Sort\n");
  printf("Phase 1:\n");
  treePrint(arr, n, calculateLevels(n));
  heap_sort(arr, n);
  printf("\nSorted Array Using Heap Sort :\n");
  printlines();
  display(arr, n);
  printlines();  int arr2[] = {55, 12, 62, 58, 53, 44, 64, 70, 71, 85, 56, 65, 94, 15, 17, 16};
  for (int i = 0; i < n; i++) {
    arr[i] = arr2[i];
  }
  printf("\nQuick Sort\n");
  printlines();
  display(arr, n);
  printlines();printf("\n");
  quickSort(arr, 0, n - 1);
  printf("\nSorted Array Using Quick Sort :\n");
  printlines();
  display(arr, n);
  printlines();
}