//Program to implement linked list and delete a node by key match and Split linked list after and before key match.
#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int info;
    struct stack *next;
}node;
//Function Declarations...
node* insert(node *, node *, int);
void delKey(node **, int);
void display(node *);
//Main Function
int main(){
    int ch, key, num;
    node *front=NULL, *rear=NULL;
    do{
        printf("\n---Menu---\n1. Push\n2. Delete Node by Key\n3. Display\n");
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
            printf("Enter the value of key: ");
            scanf("%d", &key);
            delKey(&front, key);
            break;
        case 3:
            if(front==NULL)
                printf("\tList is Empty\n");
            else
                display(front);
        }
    }while(ch <= 3);
}

//function Definitions...
//1. Function for push
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
//2. function for delete node by key
void delKey(node **front, int key){
    node *move, *tmp=*front;
    move = *front;
    if(*front == NULL)
        printf("\tList is empty\n");
    else if(key == (*front)->info){
        (*front) = (*front)->next;
    }
    else{
        while(key != move->info){
            move = move->next;
        }
        while(key != (tmp->next)->info){
            tmp = tmp->next;
        }
        tmp->next = NULL;
        display(*front);
        printf("\n");
        display(move->next);

    }
    free(move);
}
//3. funtion for display.
void display(node *front){
    while(front != NULL){
        printf("\t%d", front->info);
        front=front->next;
    }
}
/***************OUTPUT***************
---Menu---
1. Push
2. Delete Node by Key
3. Display
Enter your choice: 1
Enter an element: 10

---Menu---
1. Push
2. Delete Node by Key
3. Display
Enter your choice: 1
Enter an element: 20

---Menu---
1. Push
2. Delete Node by Key
3. Display
Enter your choice: 1
Enter an element: 30

---Menu---
1. Push
2. Delete Node by Key
3. Display
Enter your choice: 1
Enter an element: 40

---Menu---
1. Push
2. Delete Node by Key
3. Display
Enter your choice: 1
Enter an element: 50

---Menu---
1. Push
2. Delete Node by Key
3. Display
Enter your choice: 1
Enter an element: 60

---Menu---
1. Push
2. Delete Node by Key
3. Display
Enter your choice: 3
        10      20      30      40      50      60
---Menu---
1. Push
2. Delete Node by Key
3. Display
Enter your choice: 2
Enter the value of key: 40
        10      20      30
        50      60
---Menu---
1. Push
2. Delete Node by Key
3. Display
Enter your choice: 6
************************************/
