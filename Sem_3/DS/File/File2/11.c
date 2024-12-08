#include <stdio.h>
#include <stdlib.h>

#define MAX 11

enum type_of_record { EMPTY, DELETED, OCCUPIED };

struct Number {
    int number;
};

struct Record {
    struct Number info;
    enum type_of_record status;
};

struct RecordSeparateChaining {
    int info;
    struct RecordSeparateChaining *link;
};

int hash(int key) {
    return key % MAX;
}

int secondHash(int key) {
    return 7 - (key % 7);
}

void insert(struct Number num, struct Record table[], int probingType) {
    int key = num.number;
    int h = hash(key);
    int location = h;

    for (int i = 0; i < MAX; i++) {
        if (table[location].status == EMPTY || table[location].status == DELETED) {
            table[location].info = num;
            table[location].status = OCCUPIED;
            return;
        }
        if (table[location].info.number == key) {
            printf("Duplicate key %d\n", key);
            return;
        }

        if (probingType == 1)
            location = (h + i * secondHash(key)) % MAX;
        else if (probingType == 2)
            location = (h + i) % MAX;
        else if (probingType == 3)
            location = (h + i * i) % MAX;
    }
    printf("Table is full, cannot insert %d\n", key);
}

int search(int key, struct Record table[], int probingType) {
    int h = hash(key);
    int location = h;

    for (int i = 0; i < MAX; i++) {
        if (table[location].status == EMPTY)
            return -1;
        if (table[location].info.number == key)
            return location;

        if (probingType == 1)
            location = (h + i * secondHash(key)) % MAX;
        else if (probingType == 2)
            location = (h + i) % MAX;
        else if (probingType == 3)
            location = (h + i * i) % MAX;
    }
    return -1;
}

void delete(int key, struct Record table[], int probingType) {
    int location = search(key, table, probingType);
    if (location == -1)
        printf("Key %d not found\n", key);
    else {
        table[location].status = DELETED;
        printf("Key %d deleted\n", key);
    }
}

void display(struct Record table[]) {
    for (int i = 0; i < MAX; i++) {
        printf("[%d] : ", i);
        if (table[i].status == OCCUPIED)
            printf("%d : Occupied\n", table[i].info.number);
        else if (table[i].status == DELETED)
            printf("     : Deleted\n");
        else
            printf("     : Empty\n");
    }
}

void insertSeparateChaining(int info, struct RecordSeparateChaining *table[]) {
    int h = hash(info);

    struct RecordSeparateChaining *ptr = table[h];
    while (ptr != NULL) {
        if (ptr->info == info) {
            printf("Duplicate key %d\n", info);
            return;
        }
        ptr = ptr->link;
    }

    struct RecordSeparateChaining *temp = (struct RecordSeparateChaining *)malloc(sizeof(struct RecordSeparateChaining));
    temp->info = info;
    temp->link = table[h];
    table[h] = temp;
}

int searchSeparateChaining(int key, struct RecordSeparateChaining *table[]) {
    int h = hash(key);
    struct RecordSeparateChaining *ptr = table[h];

    while (ptr != NULL) {
        if (ptr->info == key)
            return h;
        ptr = ptr->link;
    }
    return -1;
}

void deleteSeparateChaining(int key, struct RecordSeparateChaining *table[]) {
    int h = hash(key);
    struct RecordSeparateChaining *ptr = table[h];
    struct RecordSeparateChaining *prev = NULL;

    while (ptr != NULL) {
        if (ptr->info == key) {
            if (prev == NULL)
                table[h] = ptr->link;
            else
                prev->link = ptr->link;

            free(ptr);
            printf("Key %d deleted\n", key);
            return;
        }
        prev = ptr;
        ptr = ptr->link;
    }
    printf("Key %d not found\n", key);
}

void displaySeparateChaining(struct RecordSeparateChaining *table[]) {
    for (int i = 0; i < MAX; i++) {
        printf("[%d]", i);
        struct RecordSeparateChaining *ptr = table[i];
        while (ptr != NULL) {
            printf(" -> %d", ptr->info);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

int main() {
    struct Record tableLinear[MAX];
    struct Record tableQuadratic[MAX];
    struct Record tableDoubleHash[MAX];
    struct RecordSeparateChaining *tableChaining[MAX] = {NULL};

    int numbers[] = {7721, 7078, 1780, 3971, 2742, 1153, 3952, 3735, 5660, 5866};

    for (int i = 0; i < MAX; i++) {
        tableLinear[i].status = EMPTY;
        tableQuadratic[i].status = EMPTY;
        tableDoubleHash[i].status = EMPTY;
    }

    for (int i = 0; i < 10; i++) {
        struct Number num = {numbers[i]};
        insert(num, tableLinear, 2);
        insert(num, tableQuadratic, 3);
        insert(num, tableDoubleHash, 1);
        insertSeparateChaining(numbers[i], tableChaining);
    }

    printf("\nLinear Probing:\n");
    display(tableLinear);
    printf("\nQuadratic Probing:\n");
    display(tableQuadratic);
    printf("\nDouble Hashing:\n");
    display(tableDoubleHash);
    printf("\nSeparate Chaining:\n");
    displaySeparateChaining(tableChaining);

    int keysToDelete[] = {7078, 3952, 2742};
    printf("\nDeleting keys: 7078, 3952, 2742\n");
    for (int i = 0; i < 3; i++) {
        delete(keysToDelete[i], tableLinear, 2);
        delete(keysToDelete[i], tableQuadratic, 3);
        delete(keysToDelete[i], tableDoubleHash, 1);
        deleteSeparateChaining(keysToDelete[i], tableChaining);
    }

    printf("\nLinear Probing After Deletion:\n");
    display(tableLinear);
    printf("\nQuadratic Probing After Deletion:\n");
    display(tableQuadratic);
    printf("\nDouble Hashing After Deletion:\n");
    display(tableDoubleHash);
    printf("\nSeparate Chaining After Deletion:\n");
    displaySeparateChaining(tableChaining);

    return 0;
}
