#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX 50
char infix[MAX];
char postfix[MAX];
char stack_arr[MAX];
int top = -1;

int isFull() {
  if (top == MAX - 1) {
    return 1;
  } else {
    return 0;
  }
  // return top == MAX - 1;
}
int isEmpty() {
  if (top == -1) {
    return 1;
  } else {
    return 0;
  }
}

void push(char item) {
  if (isFull()) {
    printf("Stack Overflow");
    return;
  }
  top = top + 1;
  stack_arr[top] = item;
}
char pop() {
  if (isEmpty()) {
    printf("Stack Underflow");
    return '\0';
  }
  char item = stack_arr[top];
  top = top - 1;
  return item;
}
char peek() {
  if (isEmpty()) {
    printf("Stack Underflow");
    return '\0';
  }
  return stack_arr[top];
}

int whitespace(char symbol) {
  if (symbol == ' ' || symbol == '\t') {
    return 1;
  } else {
    return 0;
  }
}
int symbol_priority(char ch) {
  switch (ch) {
  case '^':
    return 4;
  case '*':
  case '/':
  case '%':
    return 2;
  case '+':
  case '-':
    return 1;
  default:
    return 0;
  }
}
int instack_priority(char ch) {
  switch (ch) {
  case '^':
    return 3;
  case '*':
    return 2;
  case '/':
    return 2;
  case '%':
    return 2;
  case '+':
    return 1;
  case '-':
    return 1;
  default:
    return 0;
  }
}

void printStep(char symbol, char postfix[], int k) {
  printf("%-10c", symbol);
  for (int i = 0; i <= top; i++) {
    printf("%c", stack_arr[i]);
  }
  printf("\t\t");
  for (int i = 0; i < k; i++) {
    printf("%c", postfix[i]);
  }
  printf("\n");
}

void infixToPostfix() {
  int k = 0;
  char symbol, next;

  printf("Symbol\tStack\t\tPostfix\n");

  for (int i = 0; i < strlen(infix); i++) {
    symbol = infix[i];

    if (!whitespace(symbol)) {
      switch (symbol) {
      case '(':
        push(symbol);
        break;

      case ')':
        while ((next = pop()) != '(') {
          postfix[k++] = next;
        }
        break;

      case '+':
      case '-':
      case '*':
      case '/':
      case '%':
      case '^':
        while (top != -1 &&
               symbol_priority(peek()) >= symbol_priority(symbol)) {
          postfix[k++] = pop();
        }
        push(symbol);
        break;

      default:
        postfix[k++] = symbol;
      }
      printStep(symbol, postfix, k);
    }
  }

  while (top != -1) {
    postfix[k++] = pop();
    printStep(' ', postfix, k);
  }

  postfix[k] = '\0';
}

long int evaluatePostfix() {
  long int stack[MAX], top = -1;
  char ch;
  int val1, val2;

  for (int i = 0; i < strlen(postfix); i++) {
    ch = postfix[i];
    if (isalpha(ch)) {
      int val;
      printf("Enter the value of %c: ", ch);
      scanf("%d", &val);
      stack[++top] = val;
    } else {
      val2 = stack[top--];
      val1 = stack[top--];
      switch (ch) {
      case '+':
        stack[++top] = val1 + val2;
        break;
      case '-':
        stack[++top] = val1 - val2;
        break;
      case '*':
        stack[++top] = val1 * val2;
        break;
      case '/':
        stack[++top] = val1 / val2;
        break;
      case '%':
        stack[++top] = val1 % val2;
        break;
      case '^':
        stack[++top] = (int)pow(val1, val2);
        break;
      }
    }
  }
  return stack[top];
}

int main() {
  printf("Enter infix expression: ");
  scanf("%s", infix);
  infixToPostfix();
  printf("\nThe postfix expression is: %s\n", postfix);
  printf("After evaluating %ld", evaluatePostfix());
  return 0;
}
