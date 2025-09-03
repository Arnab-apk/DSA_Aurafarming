#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push into stack
void push(int x) {
    stack[++top] = x;
}

// Pop from stack
int pop() {
    return stack[top--];
}

// Function to evaluate Postfix Expression
int evaluatePostfix(char exp[]) {
    int i = 0;
    char ch;

    while ((ch = exp[i++]) != '\0') {
        if (isdigit(ch)) {
            // Convert char digit to int and push
            push(ch - '0');
        } else {
            // Operator → pop two operands
            int val2 = pop();
            int val1 = pop();

            switch (ch) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
    }
    return pop();  // final result
}

int main() {
    char exp[MAX];
    printf("Enter a Postfix Expression (e.g., 231*+9-): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result of Postfix Evaluation: %d\n", result);

    return 0;
}
