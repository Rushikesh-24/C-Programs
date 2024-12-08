#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX 50
char infix[MAX], postfix[MAX], stack_arr[MAX];
int top = -1, topLong = -1, topFloat = -1;
long int longStack[MAX];
float floatStack[MAX];
int variableValues[256] = {0};
float variableFloatValues[256] = {0};

void pushLong(int value) { longStack[++topLong] = value; }
void pushFloat(float value) { floatStack[++topFloat] = value; }
int popLong() { return longStack[topLong--]; }
float popFloat() { return floatStack[topFloat--]; }
void printStacks(char symbol) {
  printf("%-10c\t", symbol);
  for (int i = 0; i <= topLong; i++)
    printf("%ld, ", longStack[i]);
  printf("\t\t");
  if (topLong < 2)
    printf("\t\t");
  else
    printf("\t");
  for (int i = 0; i <= topFloat; i++)
    printf("%.2f, ", floatStack[i]);
  printf("\n");
}
void push(char item) { stack_arr[++top] = item; }
char pop() { return stack_arr[top--]; }
char peek() { return stack_arr[top]; }
int symbol_priority(char ch) {
  if (ch == '^')
    return 4;
  if (ch == '*' || ch == '/' || ch == '%')
    return 2;
  if (ch == '+' || ch == '-')
    return 1;
  return 0;
}
int stack_priority(char ch) {
  if (ch == '^')
    return 3;
  if (ch == '*' || ch == '/' || ch == '%')
    return 2;
  if (ch == '+' || ch == '-')
    return 1;
  return 0;
}
void printStep(char symbol, int k) {
  printf("%-10c", symbol);
  for (int i = 0; i <= top; i++)
    printf("%c", stack_arr[i]);
  printf("\t\t");
  for (int i = 0; i < k; i++)
    printf("%c", postfix[i]);
  printf("\n");
}
void infixToPostfix() {
  int k = 0;
  printf("Symbol\tStack\t\tPostfix\n");
  for (int i = 0; i < strlen(infix); i++) {
    char symbol = infix[i];
    if (isspace(symbol))
      continue;

    if (isalnum(symbol)) {
      postfix[k++] = symbol;
    } else if (symbol == '(') {
      push(symbol);
    } else if (symbol == ')') {
      while (top != -1 && (postfix[k++] = pop()) != '(')
        ;
      k--;
    } else {
      while (top != -1 && stack_priority(peek()) >= symbol_priority(symbol)) {
        postfix[k++] = pop();
      }
      push(symbol);
    }
    printStep(symbol, k);
  }
  while (top != -1) {
    postfix[k++] = pop();
    printStep(' ', k);
  }
  postfix[k] = '\0';
}
void evaluatePostfix() {
  printf("Symbol\t\tLong Stack\t\t\tFloat Stack\n");
  for (int i = 0; i < strlen(postfix); i++) {
    char ch = postfix[i];
    if (isalnum(ch)) {
      int digit = isdigit(ch) ? ch - '0' : variableValues[ch];
      pushLong(digit);
      pushFloat((float)digit);
    } else {
      int val2 = popLong(), val1 = popLong();
      float fval2 = popFloat(), fval1 = popFloat();
      if (ch == '+') {
        pushLong(val1 + val2);
        pushFloat(fval1 + fval2);
      }
      if (ch == '-') {
        pushLong(val1 - val2);
        pushFloat(fval1 - fval2);
      }
      if (ch == '*') {
        pushLong(val1 * val2);
        pushFloat(fval1 * fval2);
      }
      if (ch == '/') {
        pushLong(val1 / val2);
        pushFloat(fval1 / fval2);
      }
      if (ch == '^') {
        pushLong((long int)pow(val1, val2));
        pushFloat(pow(fval1, fval2));
      }
    }
    printStacks(ch);
  }
}
int main() {
  printf("Enter infix expression: ");
  scanf("%s", infix);
  infixToPostfix();
  printf("\nThe postfix expression is: %s\n", postfix);
  for (int i = 0; i < strlen(postfix); i++) {
    if (isalpha(postfix[i]) && variableValues[postfix[i]] == 0) {
      printf("Enter the value of %c: ", postfix[i]);
      scanf("%d", &variableValues[postfix[i]]);
      variableFloatValues[postfix[i]] = (float)variableValues[postfix[i]];
    }
  }
  evaluatePostfix();
  printf("Final Result: Long int: %ld, Float: %.2f\n", longStack[topLong],
         floatStack[topFloat]);
  return 0;
}