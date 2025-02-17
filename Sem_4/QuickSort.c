#include<stdio.h>
#include <time.h>
#define MAX 100
int a[MAX];
void display(int n){
    printf("\n[ ");
    for(int i = 0; i < n; i++){
        printf("%3d ", a[i]);
    }
    printf("]\n  ");
    for(int i = 0; i < n; i++){
        printf("%3d ", i+1);
    }
}
int partition(int a[],int m,int p){
    int v = a[m];
    int i = m;
    int j = p + 1;
    do{
        do{
            i++;
        }while(i <= p && a[i] <= v);
        do{
            j--;
        }while(a[j] > v);
        if(i < j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            display(9);
        }
        
    }while(i < j);
    a[m] = a[j];
    a[j] = v;
    display(9);
    return j;
}
void QuickSort(int p,int q){
    if(p<q){
        int j = partition(a,p,q);
        printf("\n\nj = %d\n",j);
        QuickSort(p,j-1);
        QuickSort(j+1,q);
    }
}
int main(){
    // int n=0;
    // printf("Enter the number of inputs in the array : ");
    // scanf("%d",&n);
    // for(int i = 0;i<n;i++){
    //     printf("Enter element %d: ", i + 1);
    //     scanf("%d",&a[i]);
    // }
    int n = 9;
    // int temp[] ={55,11,33,23,-17,89,-11,72,43};
    int temp[] ={34,56,-19,26,58,38,30,-24,22,35,76};
    for(int i = 0 ;i<n;i++){
        a[i] = temp[i];
    }
    clock_t start, end;
    double cpu_time_used;
    display(n);
    start = clock();
    QuickSort(0, n - 1);
    end = clock();
    display(n);
    cpu_time_used = ((double) (end - start)) * 1000 / CLOCKS_PER_SEC;
    printf("\nTime taken to sort the array: %f milliseconds\n", cpu_time_used);
}


//Binary
//Kth smallest
//Quick Sort
//Merge
//Multiplication
//Min max