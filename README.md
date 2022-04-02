# TMC201_DataStructure
Data structure Class, Lab, &amp; TermWork, Practice problems with source code using C language

## Q1. Program to implement STACK using "call by value".
```c
#include<stdio.h>
#define MAX 5
//Function to PUSH operation.
int push(int stack[], int top){
    int x;
    printf("Enter an element: ");
    scanf("%d", &x);
    top++;
    stack[top] = x;
    return top;
}

//Function to POP operation.
int pop(int stack[], int top){
    printf("\tThe poped element is %d\n", stack[top]);
    top--;
    return top;
}

//Function to DISPLAY the Stack.
void display(int stack[], int top){
    while(top>=0){
        printf("\n\t%d", stack[top]);
        top--;
    }
}

//Function for PEEK of Stack.
void peek(int stack[], int top){
    printf("\tPeek of stack is %d\n", stack[top]);
}

int main(){
    int ch, top=-1, stack[MAX];
    do{
        printf("\n---Menu---\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            if(top == MAX-1)
                printf("\tStack is overflow\n");
            else
                top = push(stack, top);
            display(stack, top);
            break;
        case 2:
            if(top == -1)
                printf("\tStack is Underflow\n");
            else
                top = pop(stack, top);
            display(stack, top);
            break;
        case 3:
            printf("\n---Output---\n");
            if(top == -1)
                printf("\tStack is empty\n");
            else
                display(stack, top);
            break;
        case 4:
            if(top == -1)
                printf("\tStack is empty\n");
            else
                peek(stack, top);
            break;
        }
    }while(ch <= 4);
}
```
## Q2. Program to implement STACK using "call by Reference".

```c
#include<stdio.h>
#define MAX 5
//Function for PUSH
void push(int stack[], int *top){
    *top = *top+1;
    printf("Enter an element: ");
    scanf("%d", &stack[*top]);
}

//Function for POP
void pop(int stack[], int *top){
    printf("\tPoped element is %d\n", stack[*top]);
    *top = *top-1;
}

//Function for DISPLAY
void display(int stack[], int top){
    printf("\n---Your Stack---\n");
    while(top >= 0){
        printf("\t%d\n", stack[top]);
        top--;
    }
}

//Function for PEEK
void peek(int stack[], int top){
    printf("\tPeek of stack is %d\n", stack[top]);
}
int main(){
    int ch, top=-1, stack[MAX];
    do{
        printf("\n---Menu---\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            if(top == MAX-1)
                printf("\tStack is Overflow\n");
            else
                push(stack, &top);
            display(stack, top);
            break;
        case 2:
            if(top == -1)
                printf("\tStack is Underflow\n");
            else
                pop(stack, &top);
            display(stack, top);
            break;
        case 3:
            if(top == -1)
                printf("\tStack is Empty\n");
            else
                display(stack, top);
            break;
        case 4:
            if(top == -1)
                printf("\tStack is Empty\n");
            else
                peek(stack, top);
        }
    }while(ch <= 4);
}
```
