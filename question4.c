#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

struct Stack {
    int myArray[MAX];
    int top;
} sr = {.top = -1};

void push(int value) {
    if (sr.top >= MAX - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    sr.myArray[++sr.top] = value;
}

int pop() {
    if (sr.top < 0) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return sr.myArray[sr.top--];
}

int evaluatePrefix(char *expression) {
    int length = strlen(expression);
    for (int i = length - 1; i >= 0; i--) {
        char ch = expression[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            int operand1 = pop();
            int operand2 = pop();
            int result;
            switch (ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero error!\n");
                        exit(1);
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    exit(1);
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    char expression[MAX];
    printf("Enter a prefix expression: ");
    scanf("%s", expression);
    int result = evaluatePrefix(expression);
    printf("Result of the prefix evaluation: %d\n", result);
    return 0;
}
