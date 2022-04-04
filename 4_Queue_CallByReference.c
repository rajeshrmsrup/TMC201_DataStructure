//Program to implement QUEUE using "Call By Reference".
#include<stdio.h>
#define MAX 5
//Function for INSERTION
void inQue(int q[], int *front, int *rear){
    if((*rear+1)%MAX == *front)
        printf("\tQueue is Full\n");
    else{
        *rear = (*rear+1)%MAX;
        printf("Enter an element: ");
        scanf("%d", &q[*rear]);
    }
}

//Function for DELETION
void deQue(int q[], int *front, int *rear){
    if(*front==-1)
        printf("\tQueue is Empty\n");
    else if(*front == *rear){
        printf("\tDeleted element is %d\n", q[*front]);
        *front = -1;
        *rear = -1;
    }
    else{
        printf("\tDeleted element is %d\n", q[*front]);
        *front = (*front+1)%MAX;
    }
}

//Function for DISPLAY
void display(int q[], int front, int rear){
    if(front==-1)
        printf("\tQueue is Empty\n");
    else{
        printf("\tQueue =");
        while(front != rear){
            printf("\t%d", q[front]);
            front = (front+1) % MAX;
        }
        printf("\t%d", q[front]);
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
            inQue(q, &front, &rear);
            if(front==-1)
                front=0;
            display(q, front, rear);
            break;
        case 2:
            deQue(q, &front, &rear);
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
