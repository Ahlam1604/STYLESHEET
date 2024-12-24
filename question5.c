#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int value) {
 if (top >= MAX - 1) {
 printf("Stack overflow!\n");
 exit(1);
 }
 stack[++top] = value;
}
int pop() {
 if (top < 0) {
 printf("Stack underflow!\n");
 exit(1);
 }
 return stack[top--];
}
int evaluatePostfix(char *expression) {
 int i = 0;
 while (expression[i] != '\0') {
 char ch = expression[i];
 if (isdigit(ch)) {
 push(ch - '0');
 } else {
 int b = pop();
 int a = pop();
 int result;
 switch (ch) {
 case '+': result = a + b; break;
 case '-': result = a - b; break;
 case '*': result = a * b; break;
 case '/':
 if (b == 0) {
 printf("Division by zero error!\n");
 exit(1);
 }
 result = a / b;
 break;
 default:
 printf("Invalid operator: %c\n", ch);
 exit(1);
 }
 push(result);
 }
 i++;
 }
 return pop();
}
int main() {
 char expression[MAX];
 printf("\n Enter a postfix expression: ");
 scanf("%s", expression);
 int result = evaluatePostfix(expression);
 printf("\n Result of the postfix evaluation: %d\n", result);
 return 0;
}