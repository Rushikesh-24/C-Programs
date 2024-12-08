#include <stdio.h>
#include <stdlib.h>
// Bubble Sort
void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

// Selection Sort
void selectionSort(int arr[], int n) {
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}

// Shell Sort
void shellSort(int arr[], int n) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
        arr[j] = arr[j - gap];
      arr[j] = temp;
    }
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
// Merge Sort
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] > arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    largest = right;
  if (largest != i) {
    int swap = arr[i];
    arr[i] = arr[largest];
    arr[largest] = swap;
    heapify(arr, n, largest);
  }
}
// Heap Sort
void heapSort(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);
  for (int i = n - 1; i > 0; i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heapify(arr, i, 0);
  }
}

void countSort(int arr[], int n, int exp) {
  int output[n];
  int i, count[10] = {0};
  for (i = 0; i < n; i++)
    count[(arr[i] / exp) % 10]++;
  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];
  for (i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }
  for (i = 0; i < n; i++)
    arr[i] = output[i];
}

int getMax(int arr[], int n) {
  int mx = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > mx)
      mx = arr[i];
  return mx;
}

// Radix Sort
void radixSort(int arr[], int n) {
  int m = getMax(arr, n);
  for (int exp = 1; m / exp > 0; exp *= 10)
    countSort(arr, n, exp);
}
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;
  return (i + 1);
}
// Quick Sort
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// Function to print an array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
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
    printf("7. Radix Sort\n");
    printf("8. Quick Sort\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            printf("Sorted array with Bubble Sort: \n");
            printArray(arr, n);
            break;
        case 2:
            insertionSort(arr, n);
            printf("Sorted array with Insertion Sort: \n");
            printArray(arr, n);
            break;
        case 3:
            selectionSort(arr, n);
            printf("Sorted array with Selection Sort: \n");
            printArray(arr, n);
            break;
        case 4:
            shellSort(arr, n);
            printf("Sorted array with Shell Sort: \n");
            printArray(arr, n);
            break;
        case 5:
            mergeSort(arr, 0, n - 1);
            printf("Sorted array with Merge Sort: \n");
            printArray(arr, n);
            break;
        case 6:
            heapSort(arr, n);
            printf("Sorted array with Heap Sort: \n");
            printArray(arr, n);
            break;
        case 7:
            radixSort(arr, n);
            printf("Sorted array with Radix Sort: \n");
            printArray(arr, n);
            break;
        case 8:
            quickSort(arr, 0, n - 1);
            printf("Sorted array with Quick Sort: \n");
            printArray(arr, n);
            break;
        case 9:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
} while (choice != 9);

  return 0;
}