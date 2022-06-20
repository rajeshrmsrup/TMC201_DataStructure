//Program to implement BST and perform Deletion operation.
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
int successor(node *);
int predecessor(node *);
node *deleteNode(node *, int);
//Main function
int main(){
    int ch, num, cnt=0, key;
    node *root=NULL;
    do{
        printf("\n---Menu---\n1. Insert\n2. InOrder\n3. PreOrder\n4. PostOrder\n5. Deletion\n");
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
            printf("Enter the key of the node to be deleted: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
        }
    }while(ch <= 5);
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
//5. Function for "Delete a node".
node *deleteNode(node *root, int key) {
    if(root == NULL){
        printf("\tElement is not found or tree is empty\t");
        return NULL;
    }
    if(key > root->info)
        root->right = deleteNode(root->right, key);
    else if(key < root->info)
        root->left = deleteNode(root->left, key);
    else{
        if(root->left==NULL && root->right==NULL){
            printf("\tNode has been deleted\n");
            free(root);
            return NULL;
        }
        else if(root->right != NULL) {
            root->info = successor(root);
            root->right = deleteNode(root->right, root->info);
        }
        else{
            root->info = predecessor(root);
            root->left = deleteNode(root->left, root->info);
        }
    }
    return root;
}
int successor(node *root){
    root = root->right;
    while(root->left != NULL)
        root = root->left;
    return root->info;
}
int predecessor(node *root){
    root = root->left;
    while(root->right != NULL)
        root = root->right;
    return root->info;
}
/***************OUTPUT***************
---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Deletion
Enter your choice: 1
Enter an element: 200

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Deletion
Enter your choice: 1
Enter an element: 150

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Deletion
Enter your choice: 1
Enter an element: 300

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Deletion
Enter your choice: 1
Enter an element: 250

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Deletion
Enter your choice: 1
Enter an element: 350

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Deletion
Enter your choice: 2
        150     200     250     300     350
---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Deletion
Enter your choice: 5
Enter the key of the node to be deleted: 150
        Node has been deleted

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Deletion
Enter your choice: 2
        200     250     300     350
---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Deletion
Enter your choice: 5
Enter the key of the node to be deleted: 300
        Node has been deleted

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Deletion
Enter your choice: 2
        200     250     350
---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Deletion
Enter your choice: 5
Enter the key of the node to be deleted: 200
        Node has been deleted

---Menu---
1. Insert
2. InOrder
3. PreOrder
4. PostOrder
5. Deletion
Enter your choice: 2
        250     350
************************************/
