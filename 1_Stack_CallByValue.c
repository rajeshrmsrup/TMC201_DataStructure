//Program to implement STACK using "Call By Value".
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
    printf("\n---Your Stack---");
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
/***************OUTPUT****************
---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 1
Enter an element: 10

---Your Stack---
	10
---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 1
Enter an element: 20

---Your Stack---
	20
	10
---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 1
Enter an element: 30

---Your Stack---
	30
	20
	10
---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 2
	The poped element is 30

---Your Stack---
	20
	10
---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 4
	Peek of stack is 20

---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 2
	The poped element is 20

---Your Stack---
	10
---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 2
	The poped element is 10

---Your Stack---
---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 2
	Stack is Underflow

---Your Stack---
---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 3

---Output---
	Stack is empty
*************************************/
