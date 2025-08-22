//implementation of stack using a#
#include <stdio.h>
#define size 5
int top=-1;
int stack[size];
//push
void push(int x)
{
if(top==size-1) printf("Stack overflow!\n");
else
    {
        stack[++top]=x;
        printf("%d pushed\n",x);
    }
}

//pop
void pop()
{
    if (top== -1) printf("Stack underflow!\n");
    else
        {
            printf("%d popped ",stack[top--]);
        }
}

//peek
void peek()
{
    if(top ==-1)
        printf("Stack is empty!\n");
    else
        printf("Top element is %d\n",stack[top]);
}

//display
void display()
{
    if(top==-1) printf("The stack is empty!\n");
    else
        {
            printf("Stack elements are!\n");
            for(int i=top;i>=0;i--)
            {
                printf("%d",stack[i]);    
            }
            printf("\n");
        }
}

int main()
{

}