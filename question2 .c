#include <stdio.h>
#include <ctype.h>
#define MAX 20

struct Stack {
    char elements[MAX];
    int top;
} st;


void push(char item) {
    if (st.top >= MAX- 1) {
        printf("Stack is overflow!\n");
    } else {
        st.top++;
        st.elements[st.top] = item;
    }
}


char pop() {
    if (st.top == -1) {
        printf("Error: Stack underflow!\n");
        return '\0';
    } else {
        char item = st.elements[st.top];
        st.top--;
        return item;
    }
}

int is_empty() {
    return st.top == -1;
}

int precedence(char operator) {
    if (operator == '+' || operator == '-') {
        return 1;
    }
    if (operator == '*' || operator == '/') {
        return 2;
    }
    return 0;
}


int is_operator(char character) {
    return character == '+' || character == '-' || character == '*' || character == '/';
}


void convert_to_postfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char current = infix[i];

       
        if (isalnum(current)) {
            postfix[j++] = current;
        }
       
        else if (current == '(') {
            push(current);
        }
        
        else if (current == ')') {
            while (!is_empty() && st.elements[st.top] != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        }
        else if (is_operator(current)) {
            while (!is_empty() && precedence(st.elements[st.top]) >= precedence(current)) {
                postfix[j++] = pop();
            }
            push(current);
        }
        i++;
    }

    while (!is_empty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; 
}

int main() {
    st.top = -1; 
    char infix_expression[MAX], postfix_expression[MAX];

    printf("\n Enter an infix expression: ");
    scanf("%s", infix_expression);

    convert_to_postfix(infix_expression, postfix_expression);

    printf("\n Postfix expression: %s\n", postfix_expression);

    return 0;
}
