//Program to implement STACK using "Linked List" and "Display Bottom to Top".
#include<stdio.h>
typedef struct stack{
    int info;
    struct stack *next;
}node;
//Function Declarations...
node* push(node *);
void display(node *);
//Main Function
int main(){
    int ch;
    node *top=NULL;
    do{
        printf("\n---Menu---\n1. Push\n2. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            top = push(top);
            break;
        case 2:
            display(top);
        }
    }while(ch <= 2);
}

//function Definitions...
//1. Function for push
node* push(node *top){
    node *ptr = NULL;
    ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL)
        printf("\tNot enough memory, Can't Push\n");
    else{
        printf("Enter an element: ");
        scanf("%d", &ptr->info);
        ptr->next = top;
        top = ptr;
    }
    return top;
}
//2. function for DISPLAY Bottom to Top
void display(node *top){
    if(top == NULL)
        return;
    display(top->next);
    printf("\n%d", top->info);
}
/***************OUTPUT***************

---Menu---
1. Push
2. Display
Enter your choice: 1
Enter an element: 10

---Menu---
1. Push
2. Display
Enter your choice: 1
Enter an element: 20

---Menu---
1. Push
2. Display
Enter your choice: 1
Enter an element: 30

---Menu---
1. Push
2. Display
Enter your choice: 1
Enter an element: 40

---Menu---
1. Push
2. Display
Enter your choice: 2

10
20
30
40
---Menu---
1. Push
2. Display
Enter your choice: 3
************************************/
