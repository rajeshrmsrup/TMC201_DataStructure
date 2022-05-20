//Program to implement "Circular Queue" using Linked List by "Double Pointer".
#include<stdio.h>
#include<stdlib.h>
typedef struct CQ{
    int info;
    struct CQ *next;
}node;
//Function Declarations...
void insert(node **, node **);
void serve(node **, node **);
void display(node *);
//Main Function.
int main(){
    node *left=NULL, *right=NULL;
    int ch;
    do{
        printf("\n---Menu---\n1. Insert\n2. Serve\n3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            insert(&left, &right);
            break;
        case 2:
            serve(&left, &right);
            break;
        case 3:
            display(left);
        }
    }while(ch <= 3);
}
//Function Definitions...
//1. Function for insert.
void insert(node **left, node **right){
    node *p=NULL;
    p=(node*)malloc(sizeof(node));
    printf("Enter an element: ");
    scanf("%d", &p->info);
    if(p == NULL)
        printf("\tCan't insert, bcoz don't have enough memory\n");
    else{
        if(*left==NULL && *right==NULL)
            *left=*right=p;
        else{
            (*right)->next = p;
            *right = p;
        }
        (*right)->next = *left;
    }
}
//Function for serve.
void serve(node **left, node **right){
    node *tmp;
    tmp = *left;
    if(*left == NULL)
        printf("\tCircular Queue is Empty\n");
    else{
        printf("\tServed element is %d", (*left)->info);
        if(*left == *right){
            *left = NULL;
            *right = NULL;
        }
        else{
            *left = (*left)->next;
            (*right)->next = *left;
        }
        free(tmp);
    }
}
//Function for display.
void display(node *left){
    if(left == NULL)
        printf("\tCircular Queue is Empty\n");
    else{
        node *tmp = left;
        do{
            printf("\t%d", tmp->info);
            tmp = tmp->next;
        }while(tmp != left);
    }
}
/***************OUTPUT***************
---Menu---
1. Insert
2. Serve
3. Display
Enter your choice: 1
Enter an element: 10

---Menu---
1. Insert
2. Serve
3. Display
Enter your choice: 1
Enter an element: 20

---Menu---
1. Insert
2. Serve
3. Display
Enter your choice: 1
Enter an element: 30

---Menu---
1. Insert
2. Serve
3. Display
Enter your choice: 3
        10      20      30
---Menu---
1. Insert
2. Serve
3. Display
Enter your choice: 2
        Served element is 10
---Menu---
1. Insert
2. Serve
3. Display
Enter your choice: 2
        Served element is 20
---Menu---
1. Insert
2. Serve
3. Display
Enter your choice: 2
        Served element is 30
---Menu---
1. Insert
2. Serve
3. Display
Enter your choice: 2
        Circular Queue is Empty
************************************/
