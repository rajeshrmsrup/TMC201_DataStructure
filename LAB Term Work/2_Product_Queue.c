/*
Program to Insert and Delete nodes form a Queue using Linked List, each node
should have the following information about a product...
    ->Product_Id(char)
    ->Product_Name(string)
    ->Total_sale(integer)
    ->Product_Grade(Char)
*/
/*
Name:           Rajesh Kumar
Roll No:        31
Course/Sem:     MCA-2nd
Sec:            B
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Product{
    char p_id;
    char p_name[50];
    int tot_sale;
    char p_grade;
    struct Product *next;
}node;

//Function Declarations...
void insert(node **, node **);
void Delete(node **, node **);
void display(node *);

//Main Function.
int main(){
    node *left=NULL, *right=NULL;
    int ch;
    do{
        printf("\n---Menu---\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            insert(&left, &right);
            break;
        case 2:
            Delete(&left, &right);
            break;
        case 3:
            display(left);
        }
    }while(ch < 4);
}

//Function Definitions...
//1. Function for Insert.
void insert(node **left, node **right){
    node *p=NULL;
    p = (node*)malloc(sizeof(node));

    printf("Enter the Product ID: ");

    scanf("%c", &p->p_id);
    printf("Enter the Product Name: ");
    scanf("%s", p->p_name);
    printf("Enter the total no. of Sales: ");
    scanf("%d", &p->tot_sale);
    printf("Enter the Grade: ");
    getchar();
    scanf("%c", &p->p_grade);
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
//2. Function for Delete.
void Delete(node **left, node **right){
    node *tmp = *left;
    if(*left==NULL && *right==NULL)
        printf("\tQueue is empty\n");
    else{
        printf("\tNode has been deleted.\n");
        *left = (*left)->next;
        free(tmp);
        if(*left == NULL)
            *right = NULL;
    }
}
//3. Function for Display.
void display(node *left){
    if(left == NULL)
        printf("\tQueue is empty\n");
    else{
        printf("\n---Product Queue---\n");
        while(left != NULL){
            printf("  |%c %s %d %c|", left->p_id, left->p_name, left->tot_sale, left->p_grade);
            left = left->next;
        }
    }
}
/***************OUTPUT***************
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the Product ID: a
Enter the Product Name: Box
Enter the total no. of Sales: 15205
Enter the Grade: A

---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the Product ID: B
Enter the Product Name: Pen
Enter the total no. of Sales: 3645646
Enter the Grade: A

---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the Product ID: c
Enter the Product Name: ABC
Enter the total no. of Sales: 5454
Enter the Grade: C

---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 3

---Product Queue---
  |a Box 15205 A|  |B Pen 3645646 A|  |c ABC 5454 C|
---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 2
        Node has been deleted.

---Menu---
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 3

---Product Queue---
  |B Pen 3645646 A|  |c ABC 5454 C|
************************************/
