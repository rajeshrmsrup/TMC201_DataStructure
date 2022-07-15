//Program to add of two polynomials of degree n, using linked list.
/*
Name:           Rajesh Kumar
Roll No:        31
Course/Sem:     MCA-2nd
Sec:            B
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct poly{
    int exp, coef;
    struct poly *next;
}node;
//Function Declarations...
void insert(node **, int , int);
void display(node *);
void addPoly(node *, node *);
//Main Function...
int main(){
    int ch, exp, coef;
    node *poly1=NULL, *poly2=NULL, *tmp1=NULL, *tmp2=NULL;
    do{
        printf("\n---Menu---\n1. Insert Polynomial 1\n2. Insert Polynomial 2\n3. Display and Add\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            printf("Enter the value of Exponent: ");
            scanf("%d", &exp);
            printf("Enter the value of Coefficient: ");
            scanf("%d", &coef);
            insert(&poly1, exp, coef);
            if(tmp1 == NULL)
                tmp1 = poly1;
            break;
        case 2:
            printf("Enter the value of Exponent: ");
            scanf("%d", &exp);
            printf("Enter the value of Coefficient: ");
            scanf("%d", &coef);
            insert(&poly2, exp, coef);
            if(tmp2 == NULL)
                tmp2 = poly2;
            break;
        case 3:
            if(poly1 == NULL)
                printf("\t1st Polynomial is not exist\n");
            else{
                printf("\n1st Polynomial = ");
                display(tmp1);
            }
            if(poly2 == NULL)
                printf("\n\t2nd Polynomial is not exist\n");
            else{
                printf("\n2nd Polynomial = ");
                display(tmp2);
            }
            addPoly(tmp1, tmp2);
            break;
        }
    }while(ch <= 3);
}
//Function definitions...
//1. Function for input Polynomials.
void insert(node **poly, int exp, int coef){
    node *p = NULL;
    p=(node*)malloc(sizeof(node));
    if(p == NULL)
        printf("\tCan't insert, bcoz don't have enough space\n");
    else{
        p->exp = exp;
        p->coef = coef;
        p->next = NULL;
        if(*poly == NULL)
            *poly = p;
        else{
            (*poly)->next = p;
            *poly = p;
        }
    }
}
//2. Function for Display.
void display(node *tmp){
    while(tmp != NULL){
        printf("%dx^%d", tmp->coef, tmp->exp);
        tmp = tmp->next;
        if(tmp != NULL)
            printf(" + ");
    }
}
//3. Function for Polynomial Addition.
void addPoly(node *poly1, node *poly2){
    node *poly3=NULL, *tmp=NULL, *p1=poly1, *p2=poly2;
    while(poly1 != NULL && poly2 != NULL){
        if(poly1->exp == poly2->exp){
            insert(&poly3, poly1->exp, poly1->coef+poly2->coef);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if(poly1->exp > poly2->exp){
            insert(&poly3, poly1->exp, poly1->coef);
            poly1 = poly1->next;
        }
        else if(poly1->exp < poly2->exp){
            insert(&poly3, poly2->exp, poly2->coef);
            poly2 = poly2->next;
        }
        if(tmp == NULL)
            tmp = poly3;
    }
    while(poly1 != NULL){
        insert(&poly3, poly1->exp, poly1->coef);
        poly1 = poly1->next;
    }
    while(poly2 != NULL){
        insert(&poly3, poly2->exp, poly2->coef);
        poly2 = poly2->next;
    }
    if(poly3!=NULL && p1!=NULL && p2!=NULL){
        printf("\n--------------------\n");
        printf("\nSum\t=\t");
        display(tmp);
    }
}
/***************OUTPUT***************
---Menu---
1. Insert Polynomial 1
2. Insert Polynomial 2
3. Display and Add
Enter your choice: 1
Enter the value of Exponent: 5
Enter the value of Coefficient: 4

---Menu---
1. Insert Polynomial 1
2. Insert Polynomial 2
3. Display and Add
Enter your choice: 1
Enter the value of Exponent: 4
Enter the value of Coefficient: 3

---Menu---
1. Insert Polynomial 1
2. Insert Polynomial 2
3. Display and Add
Enter your choice: 1
Enter the value of Exponent: 2
Enter the value of Coefficient: 2

---Menu---
1. Insert Polynomial 1
2. Insert Polynomial 2
3. Display and Add
Enter your choice: 1
Enter the value of Exponent: 0
Enter the value of Coefficient: 1

---Menu---
1. Insert Polynomial 1
2. Insert Polynomial 2
3. Display and Add
Enter your choice: 3

1st Polynomial = 4x^5 + 3x^4 + 2x^2 + 1x^0
        2nd Polynomial is not exist

---Menu---
1. Insert Polynomial 1
2. Insert Polynomial 2
3. Display and Add
Enter your choice: 2
Enter the value of Exponent: 7
Enter the value of Coefficient: 6

---Menu---
1. Insert Polynomial 1
2. Insert Polynomial 2
3. Display and Add
Enter your choice: 2
Enter the value of Exponent: 4
Enter the value of Coefficient: 3

---Menu---
1. Insert Polynomial 1
2. Insert Polynomial 2
3. Display and Add
Enter your choice: 2
Enter the value of Exponent: 2
Enter the value of Coefficient: 2

---Menu---
1. Insert Polynomial 1
2. Insert Polynomial 2
3. Display and Add
Enter your choice: 2
Enter the value of Exponent: 1
Enter the value of Coefficient: 2

---Menu---
1. Insert Polynomial 1
2. Insert Polynomial 2
3. Display and Add
Enter your choice: 2
Enter the value of Exponent: 0
Enter the value of Coefficient: 2

---Menu---
1. Insert Polynomial 1
2. Insert Polynomial 2
3. Display and Add
Enter your choice: 3

1st Polynomial = 4x^5 + 3x^4 + 2x^2 + 1x^0
2nd Polynomial = 6x^7 + 3x^4 + 2x^2 + 2x^1 + 2x^0
--------------------

Sum     =       6x^7 + 4x^5 + 6x^4 + 4x^2 + 2x^1 + 3x^0
---Menu---
1. Insert Polynomial 1
2. Insert Polynomial 2
3. Display and Add
Enter your choice: 5
************************************/
