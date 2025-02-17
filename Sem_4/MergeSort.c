#include <stdio.h>
#include <time.h> 
void merge(int a[], int low, int mid, int high) {
    int b[high - low + 1];
    int h = low, i = 0, j = mid + 1;

    while (h <= mid && j <= high) {
        if (a[h] <= a[j]) {
            b[i] = a[h];
            h++;
        } else {
            b[i] = a[j];
            j++;
        }
        i++;
    }

    while (h <= mid) {
        b[i] = a[h];
        h++;
        i++;
    }

    while (j <= high) {
        b[i] = a[j];
        j++;
        i++;
    }

    for (int k = low; k <= high; k++) {
        a[k] = b[k - low];
    }

    // Print the array after each merge step
    printf("Array after merging: [");
    for (int k = low; k <= high; k++) {
        printf("%d", a[k]);
        if (k < high) printf(", ");
    }
    printf("]\n");
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        printf("\n--- Merge Sort Step ---\n");
        printf("low: %d, mid: %d, high: %d\n", l, m, r);

        printf("Left array: [");
        for (int i = l; i <= m; i++) {
            printf("%d", arr[i]);
            if (i < m) printf(", ");
        }
        printf("]\n");

        printf("Right array: [");
        for (int i = m + 1; i <= r; i++) {
            printf("%d", arr[i]);
            if (i < r) printf(", ");
        }
        printf("]\n");

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    printf("[");
    for (int i = 1; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n + 1]; 
    printf("Enter the elements: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nGiven array is: ");
    printArray(arr, n + 1);
    clock_t t; 
    t = clock();
    mergeSort(arr, 1, n);
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("\nSorted array is: ");
    printArray(arr, n + 1);
    printf("BinarySearch fun() took %f seconds to execute \n", time_taken);  
    return 0;
}
