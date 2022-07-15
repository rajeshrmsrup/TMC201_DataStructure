/*
Program to find union (of two linked lists) based on their information field that implements
singly linked list (with information field Emp_Id and Name of employee for each node).

*/
/*
Name:           Rajesh Kumar
Roll No:        31
Course/Sem:     MCA-2nd
Sec:            B
*/
#include<stdio.h>
typedef struct UnionEmp{
    int emp_id;
    char emp_name[50];
    struct UnionEmp *next;
}node;

//Function Declarations...
void insert(node **, node **);
void findUnion(node *, node *, node *);
void display(node *);

//Main Function.
int main(){
    node *left1=NULL, *right1=NULL, *left2=NULL, *right2=NULL;
    int ch;
    do{
        printf("\n---Menu---\n1. Insert 1st Linked List\n2. Insert 2nd Linked List\n3. Union\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            insert(&left1, &right1);
            break;
        case 2:
            insert(&left2, &right2);
            break;
        case 3:
            findUnion(left1, right1, left2);
            break;
        case 4:
            printf("\n1st Linked List =");
            display(left1);
            printf("\n2nd Linked List =");
            display(left2);
        }
    }while(ch < 5);
}

//Function Definitions...
//1. Function for Insert.
void insert(node **left, node **right){
    node *p=NULL;
    p = (node*)malloc(sizeof(node));

    printf("Enter the Emp_ID: ");
    scanf("%d", &p->emp_id);
    printf("Enter the Employee Name: ");
    scanf("%s", p->emp_name);
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
//2. Function for Union.
void findUnion(node *left1, node *right1, node *left2){
    node *tmp=left1;
    while(left2!=NULL){
        if(left2->emp_id!=left1->emp_id && left1!=right1)
            left1 = left1->next;
        else if(left2->emp_id == left1->emp_id){
            left2 = left2->next;
            left1=tmp;
        }
        else{
            right1->next = left2;
            left2 = left2->next;
            right1 = right1->next;
            right1->next = NULL;
            left1=tmp;
        }
    }
    printf("Union = ");
    display(left1);
}
//3. Function for Display.
void display(node *left){
    if(left == NULL)
        printf("\tQueue is empty\n");
    else{
        while(left != NULL){
            printf("  |%d %s|", left->emp_id, left->emp_name);
            left = left->next;
        }
    }
}
/***************OUTPUT***************
---Menu---
1. Insert 1st Linked List
2. Insert 2nd Linked List
3. Union
4. Display
5. Exit
Enter your choice: 1
Enter the Emp_ID: 101
Enter the Employee Name: Ram

---Menu---
1. Insert 1st Linked List
2. Insert 2nd Linked List
3. Union
4. Display
5. Exit
Enter your choice: 1
Enter the Emp_ID: 102
Enter the Employee Name: Sam

---Menu---
1. Insert 1st Linked List
2. Insert 2nd Linked List
3. Union
4. Display
5. Exit
Enter your choice: 1
Enter the Emp_ID: 103
Enter the Employee Name: Raj

---Menu---
1. Insert 1st Linked List
2. Insert 2nd Linked List
3. Union
4. Display
5. Exit
Enter your choice: 1
Enter the Emp_ID: 104
Enter the Employee Name: Kus

---Menu---
1. Insert 1st Linked List
2. Insert 2nd Linked List
3. Union
4. Display
5. Exit
Enter your choice: 2
Enter the Emp_ID: 105
Enter the Employee Name: Ram

---Menu---
1. Insert 1st Linked List
2. Insert 2nd Linked List
3. Union
4. Display
5. Exit
Enter your choice: 2
Enter the Emp_ID: 101
Enter the Employee Name: Xyz

---Menu---
1. Insert 1st Linked List
2. Insert 2nd Linked List
3. Union
4. Display
5. Exit
Enter your choice: 2
Enter the Emp_ID: 102
Enter the Employee Name: Ravi

---Menu---
1. Insert 1st Linked List
2. Insert 2nd Linked List
3. Union
4. Display
5. Exit
Enter your choice: 2
Enter the Emp_ID: 108
Enter the Employee Name: Amit

---Menu---
1. Insert 1st Linked List
2. Insert 2nd Linked List
3. Union
4. Display
5. Exit
Enter your choice: 4

1st Linked List =  |101 Ram|  |102 Sam|  |103 Raj|  |104 Kus|
2nd Linked List =  |105 Ram|  |101 Xyz|  |102 Ravi|  |108 Amit|
---Menu---
1. Insert 1st Linked List
2. Insert 2nd Linked List
3. Union
4. Display
5. Exit
Enter your choice: 3
Union =   |101 Ram|  |102 Sam|  |103 Raj|  |104 Kus|  |105 Ram|  |108 Amit|
************************************/
