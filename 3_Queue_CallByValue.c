//Program to implement QUEUE using "Call By Value".
#include<stdio.h>
#define MAX 5
//Function for INSERTION
int enQ(int q[], int rear){
    rear = (rear + 1) % MAX;
    printf("Enter an element: ");
    scanf("%d", &q[rear]);
    return rear;
}

//Function for DELETION
int deQ(int q[], int rear, int front){
    if(front == rear){
        printf("\tDeleted element is %d\n", q[front]);
        front = -1;
        rear = -1;
    }
    else
        printf("\tDeleted element is %d\n", q[front]);
    front = (front + 1)%MAX;
    return front;
}

//Function to DISPLAY
void display(int q[], int rear, int front){
    int tmp = front;
    printf("\tQueue =");
    while(tmp != rear){
        printf("\t%d", q[tmp]);
        tmp = (tmp+1) % MAX;
    }
    printf("\t%d", q[tmp]);
}
//Function to PEEK
void peek(int q[], int rear, int front){
    printf("\tPeek of queue is %d", q[front]);
}
int main(){
    int q[MAX], rear=-1, front=-1, ch;
    do{
        printf("\n---Menu---\n1. EnQueue\n2. DeQueue\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            if((rear+1)%MAX == front)
                printf("\tQueue is full\n");
            else{
                if(front == -1)
                    front=0;
                rear = enQ(q, rear);
                display(q, rear, front);
            }
            break;
        case 2:
            if(front == -1)
                printf("\tQueue is Empty\n");
            else
                if(front == rear){
                    printf("\tDeleted element is %d\n", q[front]);
                    front = -1;
                    rear = -1;
                }
                else
                    front = deQ(q, rear, front);
            break;
        case 3:
            if(front == -1)
                printf("\tQueue is Empty\n");
            else
                display(q, rear, front);
            break;
        case 4:
            if(front == -1)
                printf("\tQueue is Empty\n");
            else
                peek(q, rear, front);
            break;
        }

    }while(ch <= 4);
}
/***************OUTPUT***************
---Menu---
1. EnQueue
2. DeQueue
3. Display
4. Peek
5. Exit
Enter your choice: 1
Enter an element: 10
	Queue =	10
---Menu---
1. EnQueue
2. DeQueue
3. Display
4. Peek
5. Exit
Enter your choice: 1
Enter an element: 20
	Queue =	10	20
---Menu---
1. EnQueue
2. DeQueue
3. Display
4. Peek
5. Exit
Enter your choice: 1
Enter an element: 36
	Queue =	10	20	36
---Menu---
1. EnQueue
2. DeQueue
3. Display
4. Peek
5. Exit
Enter your choice: 1
Enter an element: 45
	Queue =	10	20	36	45
---Menu---
1. EnQueue
2. DeQueue
3. Display
4. Peek
5. Exit
Enter your choice: 1
Enter an element: 25
	Queue =	10	20	36	45	25
---Menu---
1. EnQueue
2. DeQueue
3. Display
4. Peek
5. Exit
Enter your choice: 1
	Queue is full

---Menu---
1. EnQueue
2. DeQueue
3. Display
4. Peek
5. Exit
Enter your choice: 2
	Deleted element is 10

---Menu---
1. EnQueue
2. DeQueue
3. Display
4. Peek
5. Exit
Enter your choice: 2
	Deleted element is 20

---Menu---
1. EnQueue
2. DeQueue
3. Display
4. Peek
5. Exit
Enter your choice: 2
	Deleted element is 36

---Menu---
1. EnQueue
2. DeQueue
3. Display
4. Peek
5. Exit
Enter your choice: 3
	Queue =	45	25
---Menu---
1. EnQueue
2. DeQueue
3. Display
4. Peek
5. Exit
Enter your choice: 4
	Peek of queue is 45
---Menu---
1. EnQueue
2. DeQueue
3. Display
4. Peek
5. Exit
Enter your choice: 2
	Deleted element is 45

---Menu---
1. EnQueue
2. DeQueue
3. Display
4. Peek
5. Exit
Enter your choice: 2
	Deleted element is 25

---Menu---
1. EnQueue
2. DeQueue
3. Display
4. Peek
5. Exit
Enter your choice: 2
	Queue is Empty
************************************/
