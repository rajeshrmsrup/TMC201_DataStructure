//Program to implement "Doubly linked list" and Display list "Forward" & "Reverse"
#include<stdio.h>
#include<stdlib.h>
typedef struct DoublyLL{
    struct DoublyLL *prv;
    int info;
    struct DoublyLL *next;
}node;
//Function Declarations..
void insert(node **, node **, int);
void displayForward(node *);
void displayReverse(node *);
//Main function
void main(){
    node *left=NULL, *right=NULL;
    int ch, num;
    do{
        printf("\n---Menu---\n1. Insert\n2. Display in forward order\n3. Display in Reverse order\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            printf("Enter an element: ");
            scanf("%d", &num);
            insert(&left, &right, num);
            break;
        case 2:
            displayForward(left);
            break;
        case 3:
            displayReverse(right);
        }
    }while(ch <= 3);
}
void insert(node **left, node **right, int num){
    node *p=NULL;
    p=(node*)malloc(sizeof(node));
    if(p == NULL)
        printf("\tCan't insert, bcoz don't have enough memory\n");
    else{
        p->info = num;
        if(*right == NULL){
            *left=p;
            *right=p;
        }
        else if(num > (*right)->info){
            (*right)->next = p;
            p->prv = *right;
            *right = p;
        }
        else if(num < (*left)->info){
            p->next=*left;
            (*left)->prv = p;
            *left = p;

        }
        else{
            node *tmp = *left;
            while(num > (tmp->next)->info){
                tmp = tmp->next;
            }
            (tmp->next)->prv = p;
            p->next = tmp->next;
            tmp->next = p;
            p->prv = tmp;
        }
        (*left)->prv=NULL;
        (*right)->next = NULL;
    }
}
void displayForward(node *left){
    if(left == NULL)
        printf("\tLinked list is Empty\n");
    else
        while(left !=  NULL){
            printf("\t%d", left->info);
            left = left->next;
        }
}
void displayReverse(node *right){
    if(right == NULL)
        printf("\tLinked list is Empty\n");
    else
        while(right !=  NULL){
            printf("\t%d", right->info);
            right = right->prv;
        }
}
/***************OUTPUT***************
---Menu---
1. Insert
2. Display in forward order
3. Display in Reverse order
Enter your choice: 1
Enter an element: 10

---Menu---
1. Insert
2. Display in forward order
3. Display in Reverse order
Enter your choice: 1
Enter an element: 5

---Menu---
1. Insert
2. Display in forward order
3. Display in Reverse order
Enter your choice: 1
Enter an element: 60

---Menu---
1. Insert
2. Display in forward order
3. Display in Reverse order
Enter your choice: 1
Enter an element: 25

---Menu---
1. Insert
2. Display in forward order
3. Display in Reverse order
Enter your choice: 1
Enter an element: 36

---Menu---
1. Insert
2. Display in forward order
3. Display in Reverse order
Enter your choice: 2
        5       10      25      36      60
---Menu---
1. Insert
2. Display in forward order
3. Display in Reverse order
Enter your choice: 3
        60      36      25      10      5
************************************/
