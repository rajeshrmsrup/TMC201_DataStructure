/*
Program to create two link lists positive and negative from a Original linked list, so that positive
linked list contains all positive elements and negative linked list contains negative elements.
Positive and negative linked lists should use the node of existing original linked list.
*/
/*
Name:           Rajesh Kumar
Roll No:        31
Course/Sem:     MCA-2nd
Sec:            B
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct PosNegElementQ{
    int info;
    struct PosNegElementQ *next;
}node;

//Function Declarations...
void insert(node **, node **, int);
void makeNegativePositiveLL(node *, node **, node **);
void display(node *);

//Main Function.
int main(){
    node *orgLL=NULL, *negLL=NULL, *posLL=NULL, *right=NULL;
    int ch, num;
    do{
        printf("\n---Menu---\n1. Insert\n2. Display all 3 type of Linked List\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            printf("Enter an element: ");
            scanf("%d", &num);
            insert(&orgLL, &right, num);
            break;
        case 2:
            makeNegativePositiveLL(orgLL, &negLL, &posLL);
            printf("Original Linked List =");
            display(orgLL);
            printf("\nNegative Linked List =");
            display(negLL);
            printf("\nPositive Linked List =");
            display(posLL);
        }
    }while(ch < 3);
}

//Function Definitions...
//1. Function for Insert.
void insert(node **left, node **right, int num){
    node *p=NULL;
    p = (node*)malloc(sizeof(node));
    p->info = num;
    p->next = NULL;

    if(p == NULL)
        printf("\tCan't insert, bcoz don't have enough memory\n");
    else{
        if(*left == NULL)
            *left=*right=p;
        else{
            (*right)->next=p;
            *right = p;
        }
    }
}
//2. Function for making Negative and Positive Linked List.
void makeNegativePositiveLL(node *orgLL, node **negLL, node **posLL){
    node *negRight=NULL, *posRight=NULL;
    while(orgLL != NULL){
        if(orgLL->info < 0)
            insert(&(*negLL), &negRight, orgLL->info);
        else
            insert(&(*posLL), &posRight, orgLL->info);
        orgLL = orgLL->next;
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
2. Display all 3 type of Linked List
3. Exit
Enter your choice: 1
Enter an element: -1

---Menu---
1. Insert
2. Display all 3 type of Linked List
3. Exit
Enter your choice: 1
Enter an element: -2

---Menu---
1. Insert
2. Display all 3 type of Linked List
3. Exit
Enter your choice: 1
Enter an element: 1

---Menu---
1. Insert
2. Display all 3 type of Linked List
3. Exit
Enter your choice: 1
Enter an element: 2

---Menu---
1. Insert
2. Display all 3 type of Linked List
3. Exit
Enter your choice: 1
Enter an element: -10

---Menu---
1. Insert
2. Display all 3 type of Linked List
3. Exit
Enter your choice: 1
Enter an element: 36

---Menu---
1. Insert
2. Display all 3 type of Linked List
3. Exit
Enter your choice: 1
Enter an element: -50

---Menu---
1. Insert
2. Display all 3 type of Linked List
3. Exit
Enter your choice: 2
Original Linked List =  -1      -2      1       2       -10     36      -50
Negative Linked List =  -1      -2      -10     -50
Positive Linked List =  1       2       36
************************************/
