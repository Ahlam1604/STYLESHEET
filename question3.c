#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXSIZE 100

struct Stack {
    char laam[MAXSIZE];
    int top;
} st;

int isempty() {
    return st.top == -1;
}

int isfull() {
    return st.top == MAXSIZE - 1;
}

void push(char item) {
    if (isfull()) {
        printf("Error: Stack overflow!\n");
    } else {
        st.top++;
        st.laam[st.top] = item;
    }
}

char pop() {
    if (isempty()) {
        printf("Error: Stack underflow!\n");
        return '\0';
    } else {
        char item = st.laam[st.top];
        st.top--;
        return item;
    }
}

char peek() {
    if (isempty()) {
        return '\0';
    } else {
        return st.laam[st.top];
    }
}

int precedence(char operator) {
    if (operator == '+' || operator == '-') return 1;
    if (operator == '*' || operator == '/') return 2;
    if (operator == '^') return 3;
    return 0;
}

int isoperator(char character) {
    return character == '+' || character == '-' || character == '*' || character == '/' || character == '^';
}

void reversestring(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void converttoprefix(const char* infix, char* prefix) {
    char reversed[MAXSIZE], intermediate[MAXSIZE];
    int j = 0;

    strcpy(reversed, infix);
    reversestring(reversed);
    for (int i = 0; reversed[i] != '\0'; i++) {
        if (reversed[i] == '(') {
            reversed[i] = ')';
        } else if (reversed[i] == ')') {
            reversed[i] = '(';
        }
    }

    for (int i = 0; reversed[i] != '\0'; i++) {
        char current = reversed[i];
        if (isalnum(current)) {
            intermediate[j++] = current;
        } else if (current == '(') {
            push(current);
        } else if (current == ')') {
            while (!isempty() && peek() != '(') {
                intermediate[j++] = pop();
            }
            pop();
        } else if (isoperator(current)) {
            while (!isempty() && precedence(peek()) >= precedence(current)) {
                intermediate[j++] = pop();
            }
            push(current);
        }
    }

    while (!isempty()) {
        intermediate[j++] = pop();
    }
    intermediate[j] = '\0';

    strcpy(prefix, intermediate);
    reversestring(prefix);
}

int main() {
    st.top = -1;
    char infix[MAXSIZE], prefix[MAXSIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    converttoprefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);
    return 0;
}
