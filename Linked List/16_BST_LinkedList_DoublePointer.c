//Program to implement BST using Double pointer.
#include<stdio.h>
#include<stdlib.h>
typedef struct BT{
    struct BT *left;
    int info;
    struct BT *right;
}node;
//Function Declarations..
void insert(node **, int);
void preOrder(node *);
void inOrder(node *);
void postOrder(node *);
//Main function
int main(){
    int ch, num;
    node *root=NULL;
    do{
        printf("\n---Menu---\n1. Insert\n2. InOrder\n3. PreOrder\n4. PostOrder\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            printf("Enter an element: ");
            scanf("%d", &num);
            insert(&root, num);
            break;
        case 2:
            inOrder(root);
            break;
        case 3:
            preOrder(root);
            break;
        case 4:
            postOrder(root);
        }
    }while(ch <= 4);
}
//Function Definitions...
//1. Function for insert.
void insert(node **root, int num){
    node *p=NULL;
    p = (node*)malloc(sizeof(node));
    if(p==NULL)
        printf("\tCan't insert, bcoz don't have enough memory\n");
    else{
        if(*root == NULL){
            p->left = NULL;
            p->right = NULL;
            p->info = num;
            *root = p;
            return;
        }
        else if((*root)->info > num){
            insert(&(*root)->left, num);
        }
        else{
            insert(&(*root)->right, num);
        }
    }
}
//2. Function for inOrder.
void inOrder(node *root){
    if(root != NULL){
        inOrder(root->left);
        printf("\t%d", root->info);
        inOrder(root->right);
    }
}
//3. Function for preOrder.
void preOrder(node *root){
    if(root != NULL){
        printf("\t%d", root->info);
        preOrder(root->left);
        preOrder(root->right);
    }
}
//4. Function for postOrder.
void postOrder(node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("\t%d", root->info);
    }
}
/***************OUTPUT***************
---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
Enter your choice: 1
Enter an element: 50

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
Enter your choice: 1
Enter an element: 40

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
Enter your choice: 1
Enter an element: 45

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
Enter your choice: 1
Enter an element: 60

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
Enter your choice: 1
Enter an element: 43

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
Enter your choice: 1
Enter an element: 55

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
Enter your choice: 2
        40      43      45      50      55      60
---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
Enter your choice: 3
        50      40      45      43      60      55
---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
Enter your choice: 4
        43      45      40      55      60      50
---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
Enter your choice: 5
************************************/
