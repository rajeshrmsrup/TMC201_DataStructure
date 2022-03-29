# TMC201_DataStructure
Data structure Class, Lab, &amp; TermWork, Practice problems with source code using C language
## Q1. Program to implement STACK using static memory allocation.

```c
#include<stdio.h>
#define MAX 5
//Function to PUSH Operation.
int push(int stack[], int top, int x){
    int i;
    if(top == MAX-1)
        printf("\n---Output---\nStack is overflow.\n");
    else{
        top++;
        stack[top] = x;
    }
    return top;
}

//Function to POP Operation.
int pop(int stack[], int top){
    int x;
    if(top == -1)
        printf("Stack is Underflow.\n");
    else{
        x = stack[top];
        printf("The poped element is %d\n", x);
        top--;
    }
    return top;
}

//Function to Display Stack.
void display(int stack[], int top){
    int i;
    if(top == -1)
        printf("Stack is empty.\n");
    for(i=0; i<=top; i++)
        printf("%d\t", stack[i]);
}

//Function for Peek of Stack.
void peek(int top){
    printf("%d\n", top+1);
}

int main(){
    int ch, stack[MAX], x, top=-1;
    do{
        printf("\n---Operations Menu---\n");
        printf("0. Exit\n1. Push\n2. Pop\n3. Display\n4. Peek\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                printf("Enter an element: ");
                scanf("%d", &x);
                top = push(stack, top, x);
                display(stack, top);
                break;
            case 2:
                printf("---Output---\n");
                top = pop(stack, top);
                display(stack, top);
                break;
            case 3:
                printf("---Output---\n");
                display(stack, top);
                break;
            case 4:
                printf("---Output---\n");
                printf("Peek of stack is ");
                peek(top);
                break;
            case 0: exit(1);
            default: printf("Wrong input--Enter a valid input");
        }
        printf("\nContinue...");
    }while(ch != 0);
}

```
