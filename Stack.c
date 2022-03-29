#include<stdio.h>
#define MAX 5
//Function to PUSH Operation.
int push(int stack[], int top){
    int x;
    if(top == MAX-1)
        printf("\n---Output---\nStack is overflow.\n");
    else{
        printf("Enter an element: ");
        scanf("%d", &x);
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
    else{
        while(top>=0){
            printf("%d\n", stack[top]);
            top--;
        }
    }
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
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                top = push(stack, top);
                display(stack, top);
                break;
            case 2:
                printf("\n---Output---\n");
                top = pop(stack, top);
                display(stack, top);
                break;
            case 3:
                printf("\n---Output---\n");
                display(stack, top);
                break;
            case 4:
                printf("\n---Output---\n");
                printf("Peek of stack is ");
                peek(top);
                break;
            case 0: exit(1);
            default: printf("Wrong input--Enter a valid input");
        }
        printf("\n\nContinue...");
    }while(ch != 0);
}
