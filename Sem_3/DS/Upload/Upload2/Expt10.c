#include <stdio.h>

int linearSearch(int arr[], int size, int key);
int recursiveLinearSearch(int arr[], int size, int key, int index);
int binarySearch(int arr[], int left, int right, int key);
int recursiveBinarySearch(int arr[], int left, int right, int key);

int main() {
  int size;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &size);

  int arr[size];
  printf("Enter %d elements: ", size);
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  int key;
  printf("Enter the element to search for: ");
  scanf("%d", &key);
  int result;
  int choice;
  do {
    printf("\nMenu:\n");
    printf("1. Linear Search\n");
    printf("2. Recursive Linear Search\n");
    printf("3. Binary Search\n");
    printf("4. Recursive Binary Search\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      result = linearSearch(arr, size, key);
      if (result != -1)
        printf("Element found at index %d using linear search\n", result);
      else
        printf("Element not found using linear search\n");
      break;
    case 2:
      result = recursiveLinearSearch(arr, size, key, 0);
      if (result != -1)
        printf("Element found at index %d using recursive linear search\n",
               result);
      else
        printf("Element not found using recursive linear search\n");
      break;
    case 3:
      result = binarySearch(arr, 0, size - 1, key);
      if (result != -1)
        printf("Element found at index %d using binary search\n", result);
      else
        printf("Element not found using binary search\n");
      break;
    case 4:
      result = recursiveBinarySearch(arr, 0, size - 1, key);
      if (result != -1)
        printf("Element found at index %d using recursive binary search\n",
               result);
      else
        printf("Element not found using recursive binary search\n");
      break;
    case 5:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 5);

  return 0;
}

int linearSearch(int arr[], int size, int key) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == key)
      return i;
  }
  return -1;
}

int recursiveLinearSearch(int arr[], int size, int key, int index) {
  if (index >= size)
    return -1;
  if (arr[index] == key)
    return index;
  return recursiveLinearSearch(arr, size, key, index + 1);
}

int binarySearch(int arr[], int left, int right, int key) {
  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == key)
      return mid;
    if (arr[mid] < key)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1;
}

int recursiveBinarySearch(int arr[], int left, int right, int key) {
  if (right >= left) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == key)
      return mid;
    if (arr[mid] > key)
      return recursiveBinarySearch(arr, left, mid - 1, key);
    return recursiveBinarySearch(arr, mid + 1, right, key);
  }
  return -1;
}
