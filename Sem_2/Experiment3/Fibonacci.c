#include <stdio.h>
int main() {
    int n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter number of terms: ");
    scanf("%d", &n);
            printNextTerm:
            printf("%d",t1);
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            n--;
        if(n>0)goto printNextTerm;
    return 0;
}
