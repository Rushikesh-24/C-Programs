#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define CHAIN_SIZE 10

int hash(int key) {
    return key % TABLE_SIZE;
}

int linearProbing(int key, int i) {
    return (hash(key) + i) % TABLE_SIZE;
}

int quadraticProbing(int key, int i) {
    return (hash(key) + i * i) % TABLE_SIZE;
}

int doubleHashing(int key, int i) {
    int h1 = hash(key);
    int h2 = 7 - (key % 7);
    return (h1 + i * h2) % TABLE_SIZE;
}

void insertChaining(int table[][CHAIN_SIZE], int key) {
    int index = hash(key);
    for (int i = 0; i < CHAIN_SIZE; i++) {
        if (table[index][i] == -1) {
            table[index][i] = key;
            return;
        }
    }
    printf("Chain at index %d is full\n", index);
}

void displayChaining(int table[][CHAIN_SIZE]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("table[%d]: ", i);
        for (int j = 0; j < CHAIN_SIZE; j++) {
            if (table[i][j] != -1)
                printf("%d -> ", table[i][j]);
            else
                break;
        }
        printf("NULL\n");
    }
}

void insertLinear(int table[], int key) {
    int i = 0;
    int index;
    do {
        index = linearProbing(key, i);
        if (table[index] == -1) {
            table[index] = key;
            return;
        }
        i++;
    } while (i < TABLE_SIZE);
    printf("Hash table is full\n");
}

void insertQuadratic(int table[], int key) {
    int i = 0;
    int index;
    do {
        index = quadraticProbing(key, i);
        if (table[index] == -1) {
            table[index] = key;
            return;
        }
        i++;
    } while (i < TABLE_SIZE);
    printf("Hash table is full\n");
}

void insertDoubleHashing(int table[], int key) {
    int i = 0;
    int index;
    do {
        index = doubleHashing(key, i);
        if (table[index] == -1) {
            table[index] = key;
            return;
        }
        i++;
    } while (i < TABLE_SIZE);
    printf("Hash table is full\n");
}

void displayTable(int table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != -1)
            printf("table[%d]: %d\n", i, table[i]);
        else
            printf("table[%d]: NULL\n", i);
    }
}

int main() {
    int chainTable[TABLE_SIZE][CHAIN_SIZE];
    int linearTable[TABLE_SIZE];
    int quadraticTable[TABLE_SIZE];
    int doubleHashTable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < CHAIN_SIZE; j++) {
            chainTable[i][j] = -1;
        }
        linearTable[i] = -1;
        quadraticTable[i] = -1;
        doubleHashTable[i] = -1;
    }

    int keys[] = {23, 43, 13, 27, 37, 33, 47, 57, 67, 73};
    int n = 10;

    for (int i = 0; i < n; i++) {
        insertChaining(chainTable, keys[i]);
        insertLinear(linearTable, keys[i]);
        insertQuadratic(quadraticTable, keys[i]);
        insertDoubleHashing(doubleHashTable, keys[i]);
    }

    printf("Chaining:\n");
    displayChaining(chainTable);

    printf("\nLinear Probing:\n");
    displayTable(linearTable);

    printf("\nQuadratic Probing:\n");
    displayTable(quadraticTable);

    printf("\nDouble Hashing:\n");
    displayTable(doubleHashTable);

    return 0;
}