#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void displayArray(int arr[], int n) {
    printf("\n ");
    for (int k = 0; k < n; k++) {
        printf("_____");
    }
    printf("\n|");
    for (int k = 0; k < n; k++) {
        printf("%03d |", arr[k]);
    }
    printf("\n ");
    for (int k = 0; k < n; k++) {
        printf("⎺⎺⎺⎺⎺");
    }
    printf("\n");
    for (int k = 0; k < n; k++) {
        printf(" [%d] ", k);
    }
    printf("\n");
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
    printf("Sorted list is: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
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
    printf("Sorted list is: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
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
    for (i = 0; i < n; i++) arr[i] = originalArr[i];
    printf("Bubble Sort:\n");
    bubbleSort(arr, n);
    printf("\n");

    // Insertion Sort
    for (i = 0; i < n; i++) arr[i] = originalArr[i];
    printf("Insertion Sort:\n");
    insertionSort(arr, n);
    printf("\n");

    // Merge Sort
    for (i = 0; i < n; i++) arr[i] = originalArr[i];
    printf("Merge Sort:\n");
    mergeSort(arr, 0, n - 1);
    printf("\n");

    // Selection Sort
    for (i = 0; i < n; i++) arr[i] = originalArr[i];
    printf("Selection Sort:\n");
    selectionSort(arr, n);
    printf("\n");

    // Shell Sort
    for (i = 0; i < n; i++) arr[i] = originalArr[i];
    printf("Shell Sort:\n");
    shellSort(arr, n);
    printf("\n");

    // Radix Sort
    for (i = 0; i < n; i++) arr[i] = originalArr[i];
    printf("Radix Sort:\n");
    radixSort(arr, n);
    printf("\n");

    return 0;
}