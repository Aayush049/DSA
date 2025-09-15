/*Write a program to convert infix expression to postfix expression using stack.*/

#include <stdio.h>
#include <stdlib.h>

char stack[100];   // stack to hold operators
int top = -1;      // index of top of stack

// push character onto stack
void push(char c) {
    stack[++top] = c;
}

// pop character from stack
char pop() {
    return stack[top--];
}

// see top element without removing it
char peek() {
    if (top == -1)
        return -1;
    return stack[top];
}

// precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

// check if character is operand (letter or digit)
int isOperand(char c) {
    if ((c >= 'a' && c <= 'z') || 
        (c >= 'A' && c <= 'Z') || 
        (c >= '0' && c <= '9'))
        return 1;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int i = 0, j = 0;   // i -> read infix, j -> write postfix
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    // go through the expression one by one
    while (infix[i] != '\0') {
        ch = infix[i];

        // if operand, put directly into postfix
        if (isOperand(ch)) {
            postfix[j++] = ch;
        }
        // if (, push to stack
        else if (ch == '(') {
            push(ch);
        }
        // if ), pop until (
        else if (ch == ')') {
            while (peek() != '(') {
                postfix[j++] = pop();
            }
            pop();  // remove '(' from stack
        }
        // if operator
        else {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                // for ^ operator (right-associative)
                if (ch == '^' && precedence(peek()) == precedence(ch)) {
                    break;
                }
                postfix[j++] = pop();
            }
            push(ch);
        }

        i++;
    }

    // pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // null terminate

    printf("Postfix: %s\n", postfix);

    return 0;
}
