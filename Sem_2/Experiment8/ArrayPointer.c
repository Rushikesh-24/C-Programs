#include <stdio.h>
#include <stdlib.h>

int main() {
    char* names[4]; 

    names[0] = (char*)malloc(20 * sizeof(char));
    names[1] = (char*)malloc(20 * sizeof(char));
    names[2] = (char*)malloc(20 * sizeof(char));
    names[3] = (char*)malloc(20 * sizeof(char));

    sprintf(names[0], "John");
    sprintf(names[1], "Alice");
    sprintf(names[2], "Bob");
    sprintf(names[3], "Emily");

    printf("Addresses stored in the array are:\n");
    for (int i = 0; i < 4; i++)
        printf("%p\n", (void*)names[i]);

    printf("\nValues pointed to by the addresses stored in the array are:\n");
    for (int i = 0; i < 4; i++)
        printf("%s\n", names[i]);

    for (int i = 0; i < 4; i++)
        free(names[i]);

    return 0;
}