#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAX_LEN 100

void bubbleSort(char arr[][MAX_LEN], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (strcmp(arr[j], arr[j + 1]) > 0) {
        char temp[MAX_LEN];
        strcpy(temp, arr[j]);
        strcpy(arr[j], arr[j + 1]);
        strcpy(arr[j + 1], temp);
      }
    }
  }
}

void insertionSort(char arr[][MAX_LEN], int n) {
  for (int i = 1; i < n; i++) {
    char key[MAX_LEN];
    strcpy(key, arr[i]);
    int j = i - 1;
    while (j >= 0 && strcmp(arr[j], key) > 0) {
      strcpy(arr[j + 1], arr[j]);
      j--;
    }
    strcpy(arr[j + 1], key);
  }
}

void selectionSort(char arr[][MAX_LEN], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (strcmp(arr[j], arr[min_idx]) < 0) {
        min_idx = j;
      }
    }
    char temp[MAX_LEN];
    strcpy(temp, arr[min_idx]);
    strcpy(arr[min_idx], arr[i]);
    strcpy(arr[i], temp);
  }
}

void shellSort(char arr[][MAX_LEN], int n) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      char temp[MAX_LEN];
      strcpy(temp, arr[i]);
      int j;
      for (j = i; j >= gap && strcmp(arr[j - gap], temp) > 0; j -= gap) {
        strcpy(arr[j], arr[j - gap]);
      }
      strcpy(arr[j], temp);
    }
  }
}
void merge(char arr[][MAX_LEN], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  char L[n1][MAX_LEN], R[n2][MAX_LEN];

  for (int i = 0; i < n1; i++)
    strcpy(L[i], arr[l + i]);
  for (int j = 0; j < n2; j++)
    strcpy(R[j], arr[m + 1 + j]);

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (strcmp(L[i], R[j]) <= 0) {
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
void mergeSort(char arr[][MAX_LEN], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void heapify(char arr[][MAX_LEN], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && strcmp(arr[left], arr[largest]) > 0)
    largest = left;

  if (right < n && strcmp(arr[right], arr[largest]) > 0)
    largest = right;

  if (largest != i) {
    char temp[MAX_LEN];
    strcpy(temp, arr[i]);
    strcpy(arr[i], arr[largest]);
    strcpy(arr[largest], temp);

    heapify(arr, n, largest);
  }
}

void heapSort(char arr[][MAX_LEN], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i > 0; i--) {
    char temp[MAX_LEN];
    strcpy(temp, arr[0]);
    strcpy(arr[0], arr[i]);
    strcpy(arr[i], temp);

    heapify(arr, i, 0);
  }
}

int partition(char arr[][MAX_LEN], int low, int high) {
  char pivot[MAX_LEN];
  strcpy(pivot, arr[high]);
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (strcmp(arr[j], pivot) < 0) {
      i++;
      char temp[MAX_LEN];
      strcpy(temp, arr[i]);
      strcpy(arr[i], arr[j]);
      strcpy(arr[j], temp);
    }
  }
  char temp[MAX_LEN];
  strcpy(temp, arr[i + 1]);
  strcpy(arr[i + 1], arr[high]);
  strcpy(arr[high], temp);
  return (i + 1);
}
void quickSort(char arr[][MAX_LEN], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printArray(char arr[][MAX_LEN], int n) {
  for (int i = 0; i < n; i++) {
    printf("%s\n", arr[i]);
  }
}

int main() {
  char arr[MAX][MAX_LEN];
  int n, choice;

  printf("Enter number of strings: ");
  scanf("%d", &n);
  printf("Enter strings:\n");
  for (int i = 0; i < n; i++) {
    scanf("%s", arr[i]);
  }

  printf("Choose sorting algorithm:\n");
  printf("1. Bubble Sort\n");
  printf("2. Insertion Sort\n");
  printf("3. Selection Sort\n");
  printf("4. Shell Sort\n");
  printf("5. Merge Sort\n");
  printf("6. Heap Sort\n");
  printf("7. Quick Sort\n");
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
  default:
    printf("Invalid choice\n");
    return 1;
  }

  printf("Sorted strings:\n");
  printArray(arr, n);

  return 0;
}