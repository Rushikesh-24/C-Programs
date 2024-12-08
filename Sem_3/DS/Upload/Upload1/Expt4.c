#include <stdio.h>

#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(int data) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}
void displayStack() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\n\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int data;
                    printf("Enter the element to push: ");
                    scanf("%d", &data);
                    push(data);
                    displayStack();
                    break;
                }
            case 2:
                {
                    int poppedElement = pop();
                    if (poppedElement != -1) {
                        printf("Popped element: %d\n", poppedElement);
                    }
                    displayStack();
                    break;
                }
            case 3:
                {
                    int topElement = peek();
                    if (topElement != -1) {
                        printf("Top element: %d\n", topElement);
                    }
                    displayStack();
                    break;
                }
            case 4:
                {
                    displayStack();
                    break;
                }
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}
