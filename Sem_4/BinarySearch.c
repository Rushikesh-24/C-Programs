#include <stdio.h>
#include <time.h> 
    

void printArray(int a[], int low, int high) {
    printf("[");
    for (int i = low; i <= high; i++) {
        printf("%d", a[i]);
        if (i < high) {
            printf(", ");
        }
    }
    printf("]\n");
}

int BinarySearch(int a[], int n, int x) {
  
    int low = 1, high = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        printf("\nCurrent list segment: ");
        printArray(a, low, high);
        printf("Current mid index: %d, mid value: %d\n", mid, a[mid]);
        
        if (x < a[mid]) {
            printf("Element %d is less than %d, searching the left half\n", x, a[mid]);
            high = mid - 1;
        } else if (x > a[mid]) {
            printf("Element %d is greater than %d, searching the right half\n", x, a[mid]);
            low = mid + 1;
        } else {
            printf("Element %d found at index %d\n", x, mid);
            return mid;
        }
    }
    printf("Element %d is not present in the array\n", x);
    return -1; // Not Found
}

int main() {
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n + 1]; // Adjust array size to accommodate 1-based index
    printf("Enter %d elements (sorted in ascending order): ", n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &x);
    clock_t t; 
    t = clock();
    int result = BinarySearch(a, n, x);
    if (result != -1)
        printf("Element is present at index %d\n", result);
    else
        printf("Element is not present in array\n");
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 

    printf("BinarySearch fun() took %f seconds to execute \n", time_taken);     
    return 0;
}
