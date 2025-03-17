#include <stdio.h>
#include <time.h>
#define MAX 100

int n;

void interchange(char arr[], int i, int j) {
    char temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void print(char arr[], int low, int up) {
    printf("\n");
    for (int i = 1; i <= n; i++) {
        if (i == low) {
            printf("[ ");
        }
        printf("%c", arr[i]);
        if (i != up - 1) {
            printf(" ");
        }
        if (i == up - 1) {
            printf("]");
        }
    }
}

int partition(char arr[], int low, int up) {
    char pivot = arr[low];
    int i = low + 1, j = up;
    while (i <= j) {
        while (i <= up && arr[i] <= pivot) {
            i++;
        }
        while (j > low && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            interchange(arr, i, j);
            print(arr, low, up);
        }
    }
    interchange(arr, low, j);
    print(arr, low, up);
    printf(" j= %d", j);
    return j;
}

char select(char arr[], int n, int k) {
    int low = 1, up = n, j;
    while (low <= up) {
        j = partition(arr, low, up);
        if (k == j) {
            return arr[k];
        } else if (k < j) {
            up = j - 1;
        } else {
            low = j + 1;
        }
    }
    return '\0';
}

int main() {
    int k1, k2;
    printf("Enter the number of elements (max %d): ", MAX);
    scanf("%d", &n);
    char arr[MAX + 1];
    arr[0] = '\0';
    printf("Enter %d characters: ", n);
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &arr[i]);
    }
    printf("Enter the value of k1: ");
    scanf("%d", &k1);
    printf("Enter the value of k2: ");
    scanf("%d", &k2);

    clock_t start = clock();
    char m = select(arr, n, k1);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\n%dth smallest element is %c\n", k1, m);
    m = select(arr, n, k2);
    printf("\n\n%dth smallest element is %c\n", k2, m);
    printf("Execution time of select function was %f seconds \n", time_taken);

    return 0;
}