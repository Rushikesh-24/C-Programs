#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node {
    int info;
    struct node *link;
} *start = NULL;

void radix_sort();
int get_max_digits();
int get_digit(int number, int k);
void display_buckets(struct node *buckets[], int pass);
void iterative_divide(int arr[], int n);
void iterative_merge(int arr[], int n);
void recursive_merge_sort(int arr[], int temp[], int low, int high);
void merge(int arr[], int temp[], int low1, int up1, int low2, int up2);
void display_array(int arr[], int n, int segment_size);
void display_indices(int n, int segment_size);

void radix_sort() {
    int k, dig, least_sig = 1, most_sig = get_max_digits();
    struct node *p, *rear[10], *front[10];

    for (k = least_sig; k <= most_sig; k++) {
         for (int i = 0; i < 10; i++) {
              rear[i] = NULL;
              front[i] = NULL;
         }

         for (p = start; p != NULL; p = p->link) {
              dig = get_digit(p->info, k);
              if (front[dig] == NULL)
                    front[dig] = p;
              else
                    rear[dig]->link = p;
              rear[dig] = p;
         }

         display_buckets(front, k);

         int i = 0;
         while (front[i] == NULL) i++;
         start = front[i];
         while (i < 9) {
              if (rear[i + 1] != NULL)
                    rear[i]->link = front[i + 1];
              else
                    rear[i + 1] = rear[i];
              i++;
         }
         rear[9]->link = NULL;
    }
}

int get_max_digits() {
    struct node *p = start;
    int largest = 0, digits = 0;

    while (p != NULL) {
         if (p->info > largest)
              largest = p->info;
         p = p->link;
    }

    while (largest != 0) {
         digits++;
         largest /= 10;
    }
    return digits;
}

int get_digit(int number, int k) {
    for (int i = 1; i < k; i++)
         number /= 10;
    return number % 10;
}

void display_buckets(struct node *buckets[], int pass) {
    printf("Pass %d:\n", pass);
    for (int i = 0; i < 10; i++) {
         printf("Bucket %d: ", i);
         struct node *p = buckets[i];
         while (p != NULL) {
              printf("%d ", p->info);
              p = p->link;
         }
         printf("\n");
    }
}

void display_array(int arr[], int n, int segment_size) {
    for (int i = 0; i < n; i++) {
         printf("%3d", arr[i]);
         if ((i + 1) % segment_size == 0 && i != n - 1)
              printf("  | ");
         else if (i < n - 1)
              printf(" ");
    }
    printf("\n\n");
}

void display_indices(int n, int segment_size) {
    for (int i = 0; i < n; i++) {
         printf("[%2d]", i);
         if ((i + 1) % segment_size == 0 && i != n - 1)
              printf(" | ");
    }
    printf("\n");
}

void iterative_divide(int arr[], int n) {
    for (int segment_size = n / 2; segment_size >= 1; segment_size /= 2) {
         display_indices(n, segment_size);
         display_array(arr, n, segment_size);
    }
}

void iterative_merge(int arr[], int n) {
    int temp[MAX];
    for (int segment_size = 1; segment_size < n; segment_size *= 2) {
         display_indices(n, segment_size * 2);
         for (int start = 0; start < n; start += 2 * segment_size) {
              int mid = start + segment_size - 1;
              int end = (start + 2 * segment_size - 1 < n) ? start + 2 * segment_size - 1 : n - 1;
              if (mid < end) {
                    merge(arr, temp, start, mid, mid + 1, end);
              }
         }
         for (int i = 0; i < n; i++) {
              arr[i] = temp[i];
         }
         display_array(arr, n, segment_size * 2);
    }
}

void recursive_merge_sort(int arr[], int temp[], int low, int high) {
    if (low < high) {
         int mid = (low + high) / 2;
         recursive_merge_sort(arr, temp, low, mid);
         recursive_merge_sort(arr, temp, mid + 1, high);
         merge(arr, temp, low, mid, mid + 1, high);
         for (int i = low; i <= high; i++)
              arr[i] = temp[i];
    }
}

void merge(int arr[], int temp[], int low1, int up1, int low2, int up2) {
    int i = low1, j = low2, k = low1;
    while (i <= up1 && j <= up2) {
         if (arr[i] <= arr[j])
              temp[k++] = arr[i++];
         else
              temp[k++] = arr[j++];
    }
    while (i <= up1) temp[k++] = arr[i++];
    while (j <= up2) temp[k++] = arr[j++];
}

int main() {
    printf("Radix Sort:\n");
    struct node *temp, *q;
    int numbers[] = {6051, 2624, 5364, 2127, 8666, 8662, 2065, 4435, 4744, 5975};
    for (int i = 0; i < 10; i++) {
         temp = malloc(sizeof(struct node));
         temp->info = numbers[i];
         temp->link = NULL;
         if (start == NULL)
              start = temp;
         else {
              q = start;
              while (q->link != NULL)
                    q = q->link;
              q->link = temp;
         }
    }
    radix_sort();
    printf("\nSorted list from Radix Sort:\n");
    for (q = start; q != NULL; q = q->link) {
         printf("%d ", q->info);
    }
    printf("\n\n");

    int arr[] = {55, 12, 62, 58, 53, 44, 64, 70, 71, 85, 56, 65, 94, 15, 17, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp_arr[MAX];

    printf("\nInitial array for Merge Sort:\n");
    display_indices(n, n);
    display_array(arr, n, n);

    iterative_divide(arr, n);
    iterative_merge(arr, n);

    printf("\nSorted array from Merge Sort:\n");
    display_indices(n, n);
    display_array(arr, n, n);

    q = start;
    while (q != NULL) {
         struct node *next = q->link;
         free(q);
         q = next;
    }
    return 0;
}
