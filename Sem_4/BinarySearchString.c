#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

void print_array(char *a[], int low, int high) {
    for (int i = 1; i <= high; i++) {
        if (i == low) printf("[");
        printf("%s", a[i]);
        if (i == high) printf("]");
        printf(" ");
    }
    printf("\n");
    printf("low=%d mid=%d high=%d\n\n", low, (low + high) / 2, high);
}

int BinarySearch(char *a[], int i, int l, char x[MAX]) {
    int mid;
    if (i > l) {
        return -1;
    }
    mid = (i + l) / 2;
    print_array(a, i, l);
    if (strcmp(x, a[mid]) == 0) {
        return mid;
    } else if (strcmp(x, a[mid]) < 0) {
        return BinarySearch(a, i, mid - 1, x);
    } else {
        return BinarySearch(a, mid + 1, l, x);
    }
}

int main() {
    int n;
    char x[MAX];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    char *a[n + 1]; 
    printf("Enter %d elements (sorted in ascending order):\n", n);
    for (int i = 1; i <= n; i++) {
        a[i] = malloc(MAX * sizeof(char));
        scanf("%s", a[i]);
    }
    printf("Enter the element to search: ");
    scanf("%s", x);
    clock_t t; 
    t = clock();
    int result = BinarySearch(a, 1, n, x);
    if (result != -1)
        printf("Element is present at index %d\n", result);
    else
        printf("Element is not present in array\n");
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("BinarySearch fun() took %f seconds to execute \n", time_taken);

    for (int i = 1; i <= n; i++) {
        free(a[i]);
    }
    return 0;
}