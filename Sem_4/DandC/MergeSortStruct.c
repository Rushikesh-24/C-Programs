#include <stdio.h>
#include <string.h>
#include <time.h>

struct Employee {
    char id[10];
    char name[50];
    float salary;
};

int numEmployees;

void printBrackets(struct Employee arr[], int start, int end, int split) {
    for (int i = start; i <= end; i++) {
        if (i == start)
            printf("[ ");
        printf("%s(%s, %.2f) ", arr[i].id, arr[i].name, arr[i].salary);
        if (split != -1 && i == split)
            printf("] [ ");
    }
    printf("]\n");
}

void merge_asc(struct Employee a[], int low, int mid, int high) {
    struct Employee b[high - low + 1];
    int h = low, i = 0, j = mid + 1;
    while (h <= mid && j <= high) {
        if (a[h].salary <= a[j].salary) {
            b[i] = a[h];
            h++;
        } else {
            b[i] = a[j];
            j++;
        }
        i++;
    }
    while (h <= mid) {
        b[i++] = a[h++];
    }
    while (j <= high) {
        b[i++] = a[j++];
    }
    for (int k = low, x = 0; k <= high; k++, x++) {
        a[k] = b[x];
    }
}

void merge_desc(struct Employee a[], int low, int mid, int high) {
    struct Employee b[high - low + 1];
    int h = low, i = 0, j = mid + 1;
    while (h <= mid && j <= high) {
        if (a[h].salary >= a[j].salary) {
            b[i] = a[h];
            h++;
        } else {
            b[i] = a[j];
            j++;
        }
        i++;
    }
    while (h <= mid) {
        b[i++] = a[h++];
    }
    while (j <= high) {
        b[i++] = a[j++];
    }
    for (int k = low, x = 0; k <= high; k++, x++) {
        a[k] = b[x];
    }
}

void mergeSort_asc(struct Employee arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        printBrackets(arr, l, r, -1);
        mergeSort_asc(arr, l, m);
        mergeSort_asc(arr, m + 1, r);
        merge_asc(arr, l, m, r);
        printBrackets(arr, l, r, m);
    }
}

void mergeSort_desc(struct Employee arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        printBrackets(arr, l, r, -1);
        mergeSort_desc(arr, l, m);
        mergeSort_desc(arr, m + 1, r);
        merge_desc(arr, l, m, r);
        printBrackets(arr, l, r, m);
    }
}

void printArray(struct Employee arr[], int size) {
    printf("[");
    for (int i = 1; i <= size; i++) {
        printf("%s(%s, %.2f)", arr[i].id, arr[i].name, arr[i].salary);
        if (i < size)
            printf(", ");
    }
    printf("]\n");
}

int main() {
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    getchar();
    struct Employee arr[numEmployees + 1];
    struct Employee arr_desc[numEmployees + 1];
    printf("\nEnter employee details:\n");
    for (int i = 1; i <= numEmployees; i++) {
        printf("\nEmployee %d:\n", i);
        printf("ID: ");
        fgets(arr[i].id, 10, stdin);
        arr[i].id[strcspn(arr[i].id, "\n")] = 0;
        printf("Name: ");
        fgets(arr[i].name, 50, stdin);
        arr[i].name[strcspn(arr[i].name, "\n")] = 0;
        printf("Salary: ");
        scanf("%f", &arr[i].salary);
        getchar();
        arr_desc[i] = arr[i];
    }
    printf("\nOriginal array is:\n");
    printArray(arr, numEmployees);
    printf("\nMerge Sort (Ascending Order):\n");
    clock_t start;
    start = clock();
    mergeSort_asc(arr, 1, numEmployees);
    clock_t end;
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSorted array (Ascending Order):\n");
    printArray(arr, numEmployees);
    printf("\nMerge Sort Steps (Descending Order):\n");
    mergeSort_desc(arr_desc, 1, numEmployees);
    printf("\nSorted array (Descending Order):\n");
    printArray(arr_desc, numEmployees);
    printf("Execution time of merge sort function was %f seconds \n", time_taken);
    return 0;
}