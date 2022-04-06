#include<stdio.h>
#define MAX 5
//Function for INSERTION
int insert(int q[], int front, int rear){
    if(front==0 && rear==MAX-1 || front==rear+1)
        printf("\tQueue is Full\n");
    else if(front>0 && rear==MAX-1){
        rear=0;
        printf("Enter an element: ");
        scanf("%d", &q[rear]);
    }
    else{
        rear++;
        printf("Enter an element: ");
        scanf("%d", &q[rear]);
    }
    return rear;
}

//Function for DELETION
int serve(int q[], int front, int rear){
    if(front==-1 && rear==-1)
        printf("\tQueue is Empty\n");
    else if(front == rear){
        printf("\tDeleted element is %d\t", q[front]);
        front=-1;
    }
    else if(front==MAX-1 && rear>=0){
        printf("\tDeleted element is %d\t", q[front]);
        front=0;
    }
    else{
        printf("\tDeleted element is %d\t", q[front]);
        front++;
    }
    return front;

}

//Function for DISPLAY
void display(int q[], int front, int rear){
    if(front==-1 && rear==-1)
        printf("\tQueue is Empty\n");
    else if(front <= rear){
        printf("\n\tQueue =");
        while(front <= rear){
            printf("\t%d", q[front]);
            front++;
        }
    }
    else{
        printf("\n\tQueue =");
        while(front <= MAX-1){
            printf("\t%d", q[front]);
            front++;
        }
        int i=0;
        while(i <= rear){
            printf("\t%d", q[i]);
            i++;
        }
    }
}

int main(){
    int q[MAX], front=-1, rear=-1, ch;
    do{
        printf("\n---Menu---\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            rear = insert(q, front, rear);
            if(front==-1)
                front=0;
            display(q, front, rear);
            break;
        case 2:
            front = serve(q, front, rear);
            if(front == -1)
                rear=-1;
		break;
        case 3:
            display(q, front, rear);
        }
    }while(ch <= 3);
}
/***************OUTPUT***************
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter an element: 10

	Queue =	10
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter an element: 20

	Queue =	10	20
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter an element: 30

	Queue =	10	20	30
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter an element: 40

	Queue =	10	20	30	40
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter an element: 50

	Queue =	10	20	30	40	50
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
	Queue is Full

	Queue =	10	20	30	40	50
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 2
	Deleted element is 10
	Queue =	20	30	40	50
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter an element: 1

	Queue =	20	30	40	50	1
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 2
	Deleted element is 20
	Queue =	30	40	50	1
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 2
	Deleted element is 30
	Queue =	40	50	1
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter an element: 30

	Queue =	40	50	1	30
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter an element: 40

	Queue =	40	50	1	30	40
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
	Queue is Full

	Queue =	40	50	1	30	40
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice:
************************************/
