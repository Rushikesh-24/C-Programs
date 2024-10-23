#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void displayArray(int arr[], int n) {
  printf("\n ");
  for (int k = 0; k < n; k++) {
    printf("______");
  }
  printf("\n|");
  for (int k = 0; k < n; k++) {
    printf("     |");
  }

  printf("\n|");
  for (int k = 0; k < n; k++) {
    printf(" %03d |", arr[k]);
  }
  printf("\n|");
  for (int k = 0; k < n; k++) {
    printf("     |");
  }
  printf("\n ");
  for (int k = 0; k < n; k++) {
    printf("⎺⎺⎺⎺⎺⎺");
  }
  printf("\n");
  for (int k = 0; k < n; k++) {
    printf("  [%d] ", k);
  }
  printf("\n\n");
}

void bubbleSort(int arr[], int n) {
  int i, j, temp, xchanges;
  for (i = 0; i < n - 1; i++) {
    xchanges = 0;
    printf("Pass %d: \n", i + 1);
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        xchanges++;
      }
    }
    displayArray(arr, n);
    if (xchanges == 0)
      break;
  }
  printf("\n");
}

void insertionSort(int arr[], int n) {
  int i, j, k;
  for (i = 1; i < n; i++) {
    k = arr[i];
    for (j = i - 1; j >= 0 && k < arr[j]; j--) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = k;
    printf("After inserting element %d: \n", i);
    displayArray(arr, n);
  }
}

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
    printf("After merging from %d to %d: \n", l, r);
    displayArray(arr, r + 1);
  }
}

void selectionSort(int arr[], int n) {
  int i, j, minIndex, temp;
  for (i = 0; i < n - 1; i++) {
    minIndex = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex])
        minIndex = j;
    }
    if (i != minIndex) {
      temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
    printf("After selecting element %d: \n", i);
    displayArray(arr, n);
  }
  printf("\n");
}

void shellSort(int arr[], int n) {
  int incr;
  printf("\nEnter maximum increment (odd value) : ");
  scanf("%d", &incr);

  while (incr >= 1) {
    for (int i = incr; i < n; i++) {
      int temp = arr[i];
      int j;
      for (j = i - incr; j >= 0 && arr[j] > temp; j -= incr) {
        arr[j + incr] = arr[j];
      }
      arr[j + incr] = temp;
    }
    printf("After increment %d: \n", incr);
    displayArray(arr, n);
    incr -= 2;
  }
}

int getMax(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > max)
      max = arr[i];
  return max;
}

void countSort(int arr[], int n, int exp) {
  int output[n];
  int count[10] = {0};

  for (int i = 0; i < n; i++)
    count[(arr[i] / exp) % 10]++;

  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (int i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  for (int i = 0; i < n; i++)
    arr[i] = output[i];
}

void radixSort(int arr[], int n) {
  int m = getMax(arr, n);

  for (int exp = 1; m / exp > 0; exp *= 10) {
    countSort(arr, n, exp);
    printf("After sorting with exp %d: \n", exp);
    displayArray(arr, n);
  }
}

void restoreDown(int arr[], int i, int size) {
  int left = 2 * i + 1, right = left + 1;
  int num = arr[i];
  while (right < size) {

    if (num >= arr[left] && num >= arr[right]) {

      arr[i] = num;
      return;

    } else if (arr[left] > arr[right]) {
      arr[i] = arr[left];
      i = left;

    } else {

      arr[i] = arr[right];
      i = right;
    }
    left = 2 * i + 1;
    right = left + 1;
  }
  if (left == size - 1 && num < arr[left]) {

    arr[i] = arr[left];
    i = left;
  }
  arr[i] = num;
}

int del_root(int arr[], int *size) {
  int max = arr[0];
  arr[0] = arr[*size - 1];
  (*size)--;
  restoreDown(arr, 0, *size);
  return max;
}

void buildHeap(int arr[], int size) {

  int i;
  for (i = size / 2 - 1; i >= 0; i--)

    restoreDown(arr, i, size);
}

void heap_sort(int arr[], int size) {
  int max;
  buildHeap(arr, size);
  printf("After building heap: \n");
  displayArray(arr, size);
  int n = size;
  while (size > 0) {
    max = del_root(arr, &size);
    arr[size] = max;
    printf("After removing root and placing at position %d: \n", size);
    displayArray(arr, n);
    printf("\n");
  }
}

void countSortChars(char arr[], int n, int exp) {
  char output[n];
  int count[256] = {0};

  for (int i = 0; i < n; i++)
    count[(arr[i] / exp) % 256]++;

  for (int i = 1; i < 256; i++)
    count[i] += count[i - 1];

  for (int i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 256] - 1] = arr[i];
    count[(arr[i] / exp) % 256]--;
  }

  for (int i = 0; i < n; i++)
    arr[i] = output[i];
}

void radixSortChars(char arr[], int n) {
  int m = 255;

  for (int exp = 1; m / exp > 0; exp *= 256) {
    countSortChars(arr, n, exp);
    printf("After sorting with exp %d: \n", exp);
    for (int i = 0; i < n; i++) {
      printf("%c ", arr[i]);
    }
    printf("\n");
  }
}

void copyArray(int dest[], int src[], int n) {
  for (int i = 0; i < n; i++) {
    dest[i] = src[i];
  }
}

void printSeparator() {
  for (int i = 0; i < 100; i++) {
    printf("_");
  }
  printf("\n");
}

int main() {
  int n, i;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  int arr[n];
  int originalArr[n];

  srand(time(0));
  for (i = 0; i < n; i++) {
    originalArr[i] = rand() % 100;
  }

  printf("Unsorted array: ");
  displayArray(originalArr, n);
  printf("\n");

  // Bubble Sort
  printSeparator();
  copyArray(arr, originalArr, n);
  printf("\nBubble Sort:\n");
  bubbleSort(arr, n);
  printf("\n");

  // Insertion Sort
  printSeparator();
  copyArray(arr, originalArr, n);
  printf("\nInsertion Sort:\n");
  insertionSort(arr, n);
  printf("\n");

  // Merge Sort
  printSeparator();
  copyArray(arr, originalArr, n);
  printf("\nMerge Sort:\n");
  mergeSort(arr, 0, n - 1);
  printf("\n");

  // Selection Sort
  printSeparator();
  copyArray(arr, originalArr, n);
  printf("\nSelection Sort:\n");
  selectionSort(arr, n);
  printf("\n");

  // Shell Sort
  printSeparator();
  copyArray(arr, originalArr, n);
  printf("\nShell Sort:\n");
  shellSort(arr, n);
  printf("\n");

  // Radix Sort
  printSeparator();
  copyArray(arr, originalArr, n);
  printf("\nRadix Sort:\n");
  radixSort(arr, n);
  printf("\n");

  // Heap Sort
  for (int i = 0; i < 100; i++)
    printf("_");
  for (i = 0; i < n; i++)
    arr[i] = originalArr[i];
  printf("\nHeap Sort:\n");
  heap_sort(arr, n);
  printf("\n");
  return 0;
}