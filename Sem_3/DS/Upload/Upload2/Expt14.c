#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
      }
    }
  }
}

void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] < key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int max_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] > arr[max_idx]) {
        max_idx = j;
      }
    }
    swap(&arr[max_idx], &arr[i]);
  }
}

void shellSort(int arr[], int n) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
}

void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    if (L[i] >= R[j]) {
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
  }
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) {
    if (arr[j] > pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }
  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }
  for (int i = n - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);
  }
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Original array: \n");
  printArray(arr, n);
  int choice;
  do {
    printf("\nChoose sorting algorithm:\n");
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
      printf("Sorted array in descending order: \n");
      printArray(arr, n);
    }
  } while (choice != 8);

  printf("Sorted array in descending order: \n");
  printArray(arr, n);

  return 0;
}