//Program to implement Doubly Linked List and Delete a node by searching key.
#include<stdio.h>
#include<stdlib.h>
typedef struct DLL{
    struct DLL *prv;
    int info;
    struct DLL *next;
}node;
//Function Declarations...
void insert(node **, node **, int);
void deleteNode(node **, node **, int);
void display(node *, node *);
int main(){
    int ch, num, key;
    node *left=NULL, *right=NULL;
    do{
        printf("\n---Menu---\n1. Insert\n2. Delete Node By Key\n3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            printf("Enter an element: ");
            scanf("%d", &num);
            insert(&left, &right, num);
            break;
        case 2:
            if(left == NULL)
                printf("\tList is empty\n");
            else{
                printf("Enter the value of key: ");
                scanf("%d", &key);
                deleteNode(&left, &right, key);
            }
            break;
        case 3:
            if(left == NULL)
            printf("\tList is empty\n");
         else
            display(left, right);
         }
    }while(ch<=3);
}
//Function Definitions...
//Function for Insert.
void insert(node **left, node **right, int num){
     node *p=NULL;
     p = (node*)malloc(sizeof(node));
     if(p == NULL)
        printf("\tCan't insert, bcoz don't have enough memory\n");
     else{
        p->info = num;
        p->next = NULL;
        if(*left==NULL){
            *left=*right=p;
            p->prv = NULL;
        }
        else{
            (*right)->next = p;
            p->prv = *right;
            *right = p;
        }
    }
}
//Function for Delete Node
void deleteNode(node **left, node **right, int key){
    node *tmp=*left;
    int cnt=1;
    while(tmp->info!=key && tmp->next!=NULL){
        tmp = tmp->next;
        cnt++;
    }
    if(key!=tmp->info && tmp->next==NULL)
        printf("\tKey is not found\n");
    else{
        printf("\t%d is found at node %d\n",key, cnt);
        if(tmp == *left){
                if(*left==*right){
                    *left=NULL;
                    *right=NULL;
                }
                else{
                    *left = (*left)->next;
                    (*left)->prv = NULL;
            }
        }
        else if(tmp == *right){
            *right = (*right)->prv;
            (*right)->next = NULL;
        }
        else{
            (tmp->prv)->next = tmp->next;
            (tmp->next)->prv = tmp->prv;
        }
    }
    free(tmp);
}
//Function for display.
void display(node *left, node *right){
    while(left != NULL){
        printf("\t%d", left->info);
        left = left->next;
    }
}
/***************OUTPUT***************
---Menu---
1. Insert
2. Delete Node By Key
3. Display
Enter your choice: 2
        List is empty

---Menu---
1. Insert
2. Delete Node By Key
3. Display
Enter your choice: 1
Enter an element: 10

---Menu---
1. Insert
2. Delete Node By Key
3. Display
Enter your choice: 1
Enter an element: 20

---Menu---
1. Insert
2. Delete Node By Key
3. Display
Enter your choice: 1
Enter an element: 30

---Menu---
1. Insert
2. Delete Node By Key
3. Display
Enter your choice: 3
        10      20      30
---Menu---
1. Insert
2. Delete Node By Key
3. Display
Enter your choice: 2
Enter the value of key: 20
        20 is found at node 2

---Menu---
1. Insert
2. Delete Node By Key
3. Display
Enter your choice: 3
        10      30
************************************/
