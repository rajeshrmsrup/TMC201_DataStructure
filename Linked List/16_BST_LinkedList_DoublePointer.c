//Program to implement BST using Double pointer.
/*
    1. Insert
    2. InOrder
    3. PreOrder
    4. PostOrder
    5. Count Nodes
    6. Count Leaf Nodes
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct BT{
    struct BT *left;
    int info;
    struct BT *right;
}node;
//Function Declarations..
void insert(node **, int);
void inOrder(node *);
void preOrder(node *);
void postOrder(node *);
void cntNode(node *, int *);
void cntLeafNode(node *, int *);
//Main function
int main(){
    int ch, num, cnt=0;
    node *root=NULL;
    do{
        printf("\n---Menu---\n1. Insert\n2. InOrder\n3. PreOrder\n4. PostOrder\n5. Total no. of nodes\n6. Total no. of Leaf nodes\n");
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
            break;
        case 5:
            cntNode(root, &cnt);
            printf("Total nodes = %d\n", cnt);
            cnt=0;
            break;
        case 6:
            cntLeafNode(root, &cnt);
            printf("Total leaf nodes = %d\n", cnt);
            cnt=0;
            break;
        }
    }while(ch <= 6);
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
//5. Function for CountNodes.
void cntNode(node *root, int *cnt){
    if(root != NULL){
        (*cnt)++;
        cntNode(root->left, cnt);
        cntNode(root->right, cnt);
    }
}
//6. Function for Count Leaf Nodes.
void cntLeafNode(node *root, int *cnt){
    if(root != NULL){
        cntLeafNode(root->left, cnt);
        if(root->left==NULL && root->right==NULL){
            (*cnt)++;
        }
        cntLeafNode(root->right, cnt);
    }
}
/***************OUTPUT***************
---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Total no. of nodes
6. Total no. of Leaf nodes
Enter your choice: 1
Enter an element: 50

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Total no. of nodes
6. Total no. of Leaf nodes
Enter your choice: 1
Enter an element: 40

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Total no. of nodes
6. Total no. of Leaf nodes
Enter your choice: 1
Enter an element: 60

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Total no. of nodes
6. Total no. of Leaf nodes
Enter your choice: 1
Enter an element: 45

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Total no. of nodes
6. Total no. of Leaf nodes
Enter your choice: 1
Enter an element: 55

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Total no. of nodes
6. Total no. of Leaf nodes
Enter your choice: 1
Enter an element: 43

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Total no. of nodes
6. Total no. of Leaf nodes
Enter your choice: 2
        40      43      45      50      55      60
---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Total no. of nodes
6. Total no. of Leaf nodes
Enter your choice: 3
        50      40      45      43      60      55
---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Total no. of nodes
6. Total no. of Leaf nodes
Enter your choice: 4
        43      45      40      55      60      50
---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Total no. of nodes
6. Total no. of Leaf nodes
Enter your choice: 5
Total nodes = 6

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Total no. of nodes
6. Total no. of Leaf nodes
Enter your choice: 6
Total leaf nodes = 2
************************************/
