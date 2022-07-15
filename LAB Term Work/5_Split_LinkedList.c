/*
Program to create a linked list P, then write a function named "split" to create two linked
lists Q & R from P So that Q contains all elements in odd positions of P and R contains the
remaining elements. Finally print both linked lists i.e. Q and R.
*/
/*
Name:           Rajesh Kumar
Roll No:        31
Course/Sem:     MCA-2nd
Sec:            B
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct SplitQ{
    int info;
    struct SplitQ *next;
}node;

//Function Declarations...
void insert(node **, node **, int);
void split(node *, node **, node **);
void display(node *);

//Main Function.
int main(){
    node *P=NULL, *Q=NULL, *R=NULL, *right=NULL;
    int ch, num;
    do{
        printf("\n---Menu---\n1. Insert\n2. Display Linked Lists\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            printf("Enter an element: ");
            scanf("%d", &num);
            insert(&P, &right, num);
            break;
        case 2:
            split(P, &Q, &R);
            printf("Linked List P =");
            display(P);
            printf("\nLinked List Q =");
            display(Q);
            printf("\nLinked List R =");
            display(R);
        }
    }while(ch < 3);
}

//Function Definitions...
//1. Function for Insert.
void insert(node **left, node **right, int num){
    node *ptr=NULL;
    ptr = (node*)malloc(sizeof(node));
    ptr->info = num;
    ptr->next = NULL;

    if(ptr == NULL)
        printf("\tCan't insert, bcoz don't have enough memory\n");
    else{
        if(*left == NULL)
            *left=*right=ptr;
        else{
            (*right)->next=ptr;
            *right = ptr;
        }
    }
}
//2. Function for Split.
void split(node *P, node **Q, node **R){
    node *Qright=NULL, *Rright=NULL;
    int pos = 1;
    while(P != NULL){
        if(pos%2 == 0)
            insert(&(*Q), &Qright, P->info);
        else
            insert(&(*R), &Rright, P->info);
        P = P->next;
        pos++;
    }
}
//3. Function for Display.
void display(node *left){
    if(left == NULL)
        printf("\tQueue is empty\n");
    else{
        while(left != NULL){
            printf("\t%d", left->info);
            left = left->next;
        }
    }
}
/***************OUTPUT***************
---Menu---
1. Insert
2. Display Linked Lists
3. Exit
Enter your choice: 1
Enter an element: 10

---Menu---
1. Insert
2. Display Linked Lists
3. Exit
Enter your choice: 1
Enter an element: 20

---Menu---
1. Insert
2. Display Linked Lists
3. Exit
Enter your choice: 1
Enter an element: 1

---Menu---
1. Insert
2. Display Linked Lists
3. Exit
Enter your choice: 1
Enter an element: 30

---Menu---
1. Insert
2. Display Linked Lists
3. Exit
Enter your choice: 1
Enter an element: 50

---Menu---
1. Insert
2. Display Linked Lists
3. Exit
Enter your choice: 1
Enter an element: 5

---Menu---
1. Insert
2. Display Linked Lists
3. Exit
Enter your choice: 2
Linked List P = 10      20      1       30      50      5
Linked List Q = 20      30      5
Linked List R = 10      1       50
************************************/
