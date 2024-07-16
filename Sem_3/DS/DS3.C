#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Function to return precedence of operators
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX];
    int top = -1;
    int k = 0; // For index of postfix array

    for (int i = 0; infix[i]; i++) {
        // Ignore white spaces
        if (isspace(infix[i])) {
            continue;
        }
        // If the character is an operand, add it to the postfix expression
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }
        // If the character is '(', push it to the stack
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }
        // If the character is ')', pop and add to the postfix expression until '(' is found
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--; // Remove '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    // Pop all the remaining operators from the stack
    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove the newline character at the end

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
