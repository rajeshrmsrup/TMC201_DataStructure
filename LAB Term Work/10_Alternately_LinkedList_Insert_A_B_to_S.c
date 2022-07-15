/*
program to create a new Linked List ‘S’ that contains elements alternately from A and B
beginning with the first element of A. If you run out of elements in one of the lists,
then append the remaining.
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct altLL{
    int info;
    struct altLL *next;
}node;
//Function Declarations...
void insert(node **, node **, int);
void alternate(node **, node *, node *);
void display(node *);
//Main Function
int main(){
    int ch, num;
    node *A=NULL, *Arear=NULL, *B=NULL, *Brear=NULL, *S=NULL;
    do{
        printf("\n---Menu---\n1. Insert Linked List 'A'\n2. Insert Linked List 'B'\n3. Merge Alternate positions\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            printf("Enter an element: ");
            scanf("%d", &num);
            insert(&A, &Arear, num);
            break;
        case 2:
            printf("Enter an element: ");
            scanf("%d", &num);
            insert(&B, &Brear, num);
            break;
        case 3:
            printf("\nLinked Liked list 'A' = ");
            display(A);
            printf("\nLinked Liked list 'B' = ");
            display(B);

            alternate(&S, A, B);

            printf("\nLinked Liked list 'S' = ");
            display(S);
        }
    }while(ch <= 3);
}
//Function Definitions...
//1. Function for insert.
void insert(node **front, node **rear, int num){
    node *p=NULL;
    p=(node*)malloc(sizeof(node));
    p->info = num;
    p->next = NULL;
    if(*front == NULL){
        *front = p;
        *rear = p;
    }
    else{
        (*rear)->next = p;
        *rear = p;
    }
}
//2. Function for Merge Alternate nodes.
void alternate(node **S, node *A, node *B){
    *S = A;
    node *SRear=A;
    while(SRear!=NULL && B!=NULL){
        if(SRear->next==NULL){
            SRear->next = B;
            return;
        }
        node *Snext = SRear->next;
        node *Bnext = B->next;
        SRear->next = B;
        B->next = Snext;
        SRear = Snext;
        B = Bnext;
    }
}

//3. Function for display.
void display(node *front){
    if(front==NULL)
        printf("\tQueue is empty\n");
    else{
        while(front != NULL){
            printf(" %d", front->info);
            front = front->next;
        }
    }
}
/***************OUTPUT***************

---Menu---
1. Insert Linked List 'A'
2. Insert Linked List 'B'
3. Merge Alternate positions
Enter your choice: 1
Enter an element: 10

---Menu---
1. Insert Linked List 'A'
2. Insert Linked List 'B'
3. Merge Alternate positions
Enter your choice: 1
Enter an element: 20

---Menu---
1. Insert Linked List 'A'
2. Insert Linked List 'B'
3. Merge Alternate positions
Enter your choice: 2
Enter an element: 30

---Menu---
1. Insert Linked List 'A'
2. Insert Linked List 'B'
3. Merge Alternate positions
Enter your choice: 2
Enter an element: 40

---Menu---
1. Insert Linked List 'A'
2. Insert Linked List 'B'
3. Merge Alternate positions
Enter your choice: 2
Enter an element: 50

---Menu---
1. Insert Linked List 'A'
2. Insert Linked List 'B'
3. Merge Alternate positions
Enter your choice: 2
Enter an element: 60

---Menu---
1. Insert Linked List 'A'
2. Insert Linked List 'B'
3. Merge Alternate positions
Enter your choice: 3

Linked Liked list 'A' =  10 20
Linked Liked list 'B' =  30 40 50 60
Linked Liked list 'S' =  10 30 20 40 50 60
************************************/
