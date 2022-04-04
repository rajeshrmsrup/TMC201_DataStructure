# TMC201_DataStructure
Data structure Class, Lab, &amp; TermWork, Practice problems with source code using C language

## Q1. Program to implement STACK using "Call By Value".
```c
#include<stdio.h>
#define MAX 5
//Function for PUSH operation.
int push(int stack[], int top){
    int x;
    printf("Enter an element: ");
    scanf("%d", &x);
    top++;
    stack[top] = x;
    return top;
}

//Function for POP operation.
int pop(int stack[], int top){
    printf("\tThe poped element is %d\n", stack[top]);
    top--;
    return top;
}

//Function for DISPLAY the Stack.
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
```
## Q2. Program to implement STACK using "Call By Reference".

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
```
## Q3. Program to implement QUEUE using "Call By Value".

```c
#include<stdio.h>
#define MAX 5
//Function for INSERTION
int inQue(int q[], int front, int rear){
    if((rear+1)%MAX == front)
        printf("\tQueue is Full\n");
    else{
        rear = (rear+1)%MAX;
        printf("Enter an element: ");
        scanf("%d", &q[rear]);
    }
    return rear;
}

//Function for DELETION
int deQue(int q[], int front, int rear){
    if(front==-1)
        printf("\tQueue is Empty\n");
    else if(front == rear){
        printf("\tDeleted element is %d\n", q[front]);
        front = -1;
    }
    else{
        printf("\tDeleted element is %d\n", q[front]);
        front = (front+1)%MAX;
    }
    return front;
}

//Function for DISPLAY
void display(int q[], int front, int rear){
    if(front==-1)
        printf("\tQueue is Empty\n");
    else{
        int tmp = front;
        printf("\tQueue =");
        while(tmp != rear){
            printf("\t%d", q[tmp]);
            tmp = (tmp+1) % MAX;
        }
        printf("\t%d", q[tmp]);
    }
}

int main(){
    int q[MAX], front=-1, rear=-1, ch;
    do{
        printf("\n---Menu---\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            rear = inQue(q, front, rear);
            if(front==-1)
                front=0;
            display(q, front, rear);
            break;
        case 2:
            if(front == -1){
                rear=-1;
            }
            front = deQue(q, front, rear);
            break;
        case 3:
            display(q, front, rear);
        }
    }while(ch <= 3);
}
/***************OUTPUT***************
---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice: 1
Enter an element: 10
	Queue =	10
---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice: 1
Enter an element: 20
	Queue =	10	20
---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice: 1
Enter an element: 30
	Queue =	10	20	30
---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice: 1
Enter an element: 40
	Queue =	10	20	30	40
---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice: 1
Enter an element: 50
	Queue =	10	20	30	40	50
---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice: 1
	Queue is Full
	Queue =	10	20	30	40	50
---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice: 2
	Deleted element is 10

---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice: 1
Enter an element: 1
	Queue =	20	30	40	50	1
---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice: 2
	Deleted element is 20

---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice: 2
	Deleted element is 30

---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice: 3
	Queue =	40	50	1
---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice: 2
	Deleted element is 40

---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice: 2
	Deleted element is 50

---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice: 2
	Deleted element is 1

---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice: 2
	Queue is Empty

---Menu---
1. Insertion
2. Deletion
3. Display
4. Exit
Enter your choice:
1
Enter an element: 10
	Queue =	10
************************************/
```
