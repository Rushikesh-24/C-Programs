#include <stdio.h>
#include <ctype.h>
#include <math.h>
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
    if (ch == '^') {
        return 4;
    } else if (ch == '*' || ch == '/' || ch == '%') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '(') {
        return 0;
    } else {
        return -1;
    }
}

int instack_priority(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '*' || ch == '/' || ch == '%') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '(') {
        return 0;
    } else {
        return -1;
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
  printf("-------------------------------\n");
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
               symbol_priority(peek()) >= instack_priority(symbol)) {
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
    long int stack[MAX];
    int top = -1;
    char ch;
    int val1, val2;

    int variableValues[256] = {0};
    int assigned[256] = {0};

    for (int i = 0; i < strlen(postfix); i++) {
        ch = postfix[i];
        if (isalpha(ch)) {
            if (!assigned[ch]) {
                int val;
                printf("Enter the value of %c: ", ch);
                scanf("%d", &val);
                variableValues[ch] = val;
                assigned[ch] = 1;
            }
            stack[++top] = variableValues[ch];
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

    printf("\nSymbol\tInt\tFloat\n");
    printf("-----------------------\n");
    for (int i = 0; i < strlen(postfix); i++) {
        ch = postfix[i];
        if (isalpha(ch)) {
            printf("%c\t%d\t%.2f\n", ch, variableValues[ch], (float)variableValues[ch]);
        }
    }

    return stack[top];
}

int main() {
  printf("Enter infix expression: ");
  scanf("%s", infix);
  infixToPostfix();
  printf("\nThe postfix expression is: %s\n", postfix);
  printf("Steps during evaluation:\n");
  long int result = evaluatePostfix();
  printf("After evaluating: %ld\n", result);
  return 0;
}
