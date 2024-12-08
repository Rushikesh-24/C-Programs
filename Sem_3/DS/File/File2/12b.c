#include <stdio.h>
#define MAX 100

void heap_sort(int arr[], int n);
void buildHeap(int arr[], int n);
void restoreDown(int arr[], int i, int size);
void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);
void display_array(int arr[], int size);

int delete_root(int arr[], int *size) {
    int max = arr[0];
    arr[0] = arr[*size - 1];
    (*size)--;
    restoreDown(arr, 0, *size);
    return max;
}

void heap_sort(int arr[], int size) {
    int max;
    buildHeap(arr, size);
    printf("Heap is : ");
    display_array(arr, size);
    while (size > 0) {
        max = delete_root(arr, &size);
        arr[size] = max;
    }
}

void buildHeap(int arr[], int size) {
    int i;
    for (i = size / 2 - 1; i >= 0; i--) {
        restoreDown(arr, i, size);
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
    if (left < size && num < arr[left]) {
        arr[i] = arr[left];
        i = left;
    }
    arr[i] = num;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        printf("Array after partitioning around pivot %d:\n", arr[pi]);
        display_array(arr, high + 1);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX] = {55, 12, 62, 58, 53, 44, 64, 70,
                    71, 85, 56, 65, 94, 15, 17, 16};
    int n = 16;

    printf("Initial array for Heap Sort:\n");
    display_array(arr, n);
    heap_sort(arr, n);
    printf("\nSorted array using Heap Sort in descending order:\n");
    display_array(arr, n);

    int arr2[MAX] = {55, 12, 62, 58, 53, 44, 64, 70,
                     71, 85, 56, 65, 94, 15, 17, 16};
    printf("\nInitial array for Quick Sort:\n");
    display_array(arr2, n);
    quick_sort(arr2, 0, n - 1);
    printf("\nSorted array using Quick Sort in descending order:\n");
    display_array(arr2, n);

    return 0;
}
