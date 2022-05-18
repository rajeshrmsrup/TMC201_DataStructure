//Program to implement Queue using Linked List with Single Pointer.
#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int info;
    struct queue *next;
}node;
//Function Declarations...
node* insert(node *, node *, int);
node* serve(node *, node *);
void display(node *);
//Main Function
int main(){
    int ch, num;
    node *front=NULL, *rear=NULL;
    do{
        printf("\n---Menu---\n1. Insert\n2. Serve\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            printf("Enter an element: ");
            scanf("%d",  &num);
            rear=insert(front, rear, num);
            if(front==NULL)
                front=rear;
            break;
        case 2:
            front=serve(front, rear);
            if(front == NULL)
                rear = NULL;
            break;
        case 3:
            display(front);
        }

    }while(ch <= 3);
}
//Function Definitions...
//1. Function for insert.
node *insert(node *front, node *rear, int num){
    node *p=NULL;
    p=(node*)malloc(sizeof(node));
    p->info = num;
    p->next = NULL;
    if(front == NULL){
        front = p;
        rear = p;
    }
    else{
        rear->next = p;
        rear = p;
    }
    return rear;
}
//2. Function for serve.
node *serve(node *front, node *rear){
    node *tmp = front;
    if(front==NULL && rear==NULL)
        printf("\tQueue is empty\n");
    else{
        printf("\tServed element is %d\n",front->info);
        front = front->next;
        free(tmp);
    }
     return front;
}
//3. Function for display.
void display(node *front){
    if(front==NULL)
        printf("\tQueue is empty\n");
    else{
        while(front != NULL){
            printf("\t%d", front->info);
            front = front->next;
        }
    }
}
/***************OUTPUT***************
---Menu---
1. Insert
2. Serve
3. Display
4. Exit
Enter your choice: 1
Enter an element: 10

---Menu---
1. Insert
2. Serve
3. Display
4. Exit
Enter your choice: 1
Enter an element: 20

---Menu---
1. Insert
2. Serve
3. Display
4. Exit
Enter your choice: 1
Enter an element: 30

---Menu---
1. Insert
2. Serve
3. Display
4. Exit
Enter your choice: 1
Enter an element: 40

---Menu---
1. Insert
2. Serve
3. Display
4. Exit
Enter your choice: 3
        10      20      30      40
---Menu---
1. Insert
2. Serve
3. Display
4. Exit
Enter your choice: 2
        Served element is 10

---Menu---
1. Insert
2. Serve
3. Display
4. Exit
Enter your choice: 2
        Served element is 20

---Menu---
1. Insert
2. Serve
3. Display
4. Exit
Enter your choice: 3
        30      40
---Menu---
1. Insert
2. Serve
3. Display
4. Exit
Enter your choice: 4
************************************/
