// Implementation of Stack using Array
#include <stdio.h>
#define SIZE 5

int top = -1;
int stack[SIZE];

// Push
void push(int x) {
    if (top == SIZE - 1) 
        printf("Stack overflow!\n");
    else {
        stack[++top] = x;
        printf("%d pushed\n", x);
    }
}

// Pop
void pop() {
    if (top == -1) 
        printf("Stack underflow!\n");
    else 
        printf("%d popped\n", stack[top--]);
}

// Peek
void peek() {
    if (top == -1)
        printf("Stack is empty!\n");
    else
        printf("Top element is %d\n", stack[top]);
}

// Display
void display() {
    if (top == -1) 
        printf("The stack is empty!\n");
    else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, n;

    printf("Stack Implementation using Array\n");
    do {
        printf("\nEnter\n1. Push\n2. Pop\n3. Peek\n4. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element you want to push: ");
                scanf("%d", &n);
                push(n);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
