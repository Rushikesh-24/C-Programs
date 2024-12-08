#include <stdio.h>
#include <string.h>

#define MAX 100

void bubbleSort(char arr[][MAX], int n);
void insertionSort(char arr[][MAX], int n);
void selectionSort(char arr[][MAX], int n);
void shellSort(char arr[][MAX], int n);
void mergeSort(char arr[][MAX], int l, int r);
void merge(char arr[][MAX], int l, int m, int r);
void heapSort(char arr[][MAX], int n);
void heapify(char arr[][MAX], int n, int i);
void quickSort(char arr[][MAX], int low, int high);
int partition(char arr[][MAX], int low, int high);

void printArray(char arr[][MAX], int n);

int main() {
  char arr[][MAX] = {"apple", "orange", "banana", "grape", "cherry"};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array:\n");
  printArray(arr, n);

  int choice;
  do {
    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Shell Sort\n");
    printf("5. Merge Sort\n");
    printf("6. Heap Sort\n");
    printf("7. Quick Sort\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      bubbleSort(arr, n);
      break;
    case 2:
      insertionSort(arr, n);
      break;
    case 3:
      selectionSort(arr, n);
      break;
    case 4:
      shellSort(arr, n);
      break;
    case 5:
      mergeSort(arr, 0, n - 1);
      break;
    case 6:
      heapSort(arr, n);
      break;
    case 7:
      quickSort(arr, 0, n - 1);
      break;
    case 8:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
    }

    if (choice >= 1 && choice <= 7) {
      printf("\nSorted array in descending order:\n");
      printArray(arr, n);
    }

  } while (choice != 8);

  printf("\nSorted array in descending order:\n");
  printArray(arr, n);

  return 0;
}

void bubbleSort(char arr[][MAX], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (strcmp(arr[j], arr[j + 1]) < 0) {
        char temp[MAX];
        strcpy(temp, arr[j]);
        strcpy(arr[j], arr[j + 1]);
        strcpy(arr[j + 1], temp);
      }
    }
  }
}

void insertionSort(char arr[][MAX], int n) {
  for (int i = 1; i < n; i++) {
    char key[MAX];
    strcpy(key, arr[i]);
    int j = i - 1;
    while (j >= 0 && strcmp(arr[j], key) < 0) {
      strcpy(arr[j + 1], arr[j]);
      j = j - 1;
    }
    strcpy(arr[j + 1], key);
  }
}

void selectionSort(char arr[][MAX], int n) {
  for (int i = 0; i < n - 1; i++) {
    int max_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (strcmp(arr[j], arr[max_idx]) > 0) {
        max_idx = j;
      }
    }
    char temp[MAX];
    strcpy(temp, arr[max_idx]);
    strcpy(arr[max_idx], arr[i]);
    strcpy(arr[i], temp);
  }
}

void shellSort(char arr[][MAX], int n) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      char temp[MAX];
      strcpy(temp, arr[i]);
      int j;
      for (j = i; j >= gap && strcmp(arr[j - gap], temp) < 0; j -= gap) {
        strcpy(arr[j], arr[j - gap]);
      }
      strcpy(arr[j], temp);
    }
  }
}

void merge(char arr[][MAX], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  char L[n1][MAX], R[n2][MAX];

  for (int i = 0; i < n1; i++)
    strcpy(L[i], arr[l + i]);
  for (int j = 0; j < n2; j++)
    strcpy(R[j], arr[m + 1 + j]);

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (strcmp(L[i], R[j]) >= 0) {
      strcpy(arr[k], L[i]);
      i++;
    } else {
      strcpy(arr[k], R[j]);
      j++;
    }
    k++;
  }

  while (i < n1) {
    strcpy(arr[k], L[i]);
    i++;
    k++;
  }

  while (j < n2) {
    strcpy(arr[k], R[j]);
    j++;
    k++;
  }
}

void mergeSort(char arr[][MAX], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

void heapify(char arr[][MAX], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && strcmp(arr[left], arr[largest]) > 0)
    largest = left;

  if (right < n && strcmp(arr[right], arr[largest]) > 0)
    largest = right;

  if (largest != i) {
    char temp[MAX];
    strcpy(temp, arr[i]);
    strcpy(arr[i], arr[largest]);
    strcpy(arr[largest], temp);

    heapify(arr, n, largest);
  }
}

void heapSort(char arr[][MAX], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) {
    char temp[MAX];
    strcpy(temp, arr[0]);
    strcpy(arr[0], arr[i]);
    strcpy(arr[i], temp);

    heapify(arr, i, 0);
  }
}

int partition(char arr[][MAX], int low, int high) {
  char pivot[MAX];
  strcpy(pivot, arr[high]);
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (strcmp(arr[j], pivot) > 0) {
      i++;
      char temp[MAX];
      strcpy(temp, arr[i]);
      strcpy(arr[i], arr[j]);
      strcpy(arr[j], temp);
    }
  }
  char temp[MAX];
  strcpy(temp, arr[i + 1]);
  strcpy(arr[i + 1], arr[high]);
  strcpy(arr[high], temp);
  return (i + 1);
}

void quickSort(char arr[][MAX], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printArray(char arr[][MAX], int n) {
  for (int i = 0; i < n; i++) {
    printf("%s\n", arr[i]);
  }
}