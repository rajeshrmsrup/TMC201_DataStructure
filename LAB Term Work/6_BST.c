/*
Program to create a binary search tree and perform following operations...
    1) Search a particular key.
    2) Delete a node from the tree.
    3) Find total number of leaf nodes.
    4) Find height of a binary search tree.
    5) Count total numbers of nodes from right hand side of root node.
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

void searchKey(node *, int, node *);
node* findMaxElement(node *);
void deleteNode(node **, int);
void cntLeafNode(node *, int *);
int height(node *);
void cntNodeRight(node *, int *);

//Main function
int main(){
    int ch, num, key, cnt=0;
    node *root=NULL, *parent=NULL;
    do{
        printf("\n---Menu---\n1. Insert\n2. InOrder\n3. Search for a key\n");
        printf("4. Delete a node\n5. Count Leaf nodes\n6. Find height\n7. Count right nodes\n");
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
            printf("Enter the key: ");
            scanf("%d", &key);
            searchKey(root, key, parent);
            break;
        case 4:
            printf("Enter the value of key: ");
            scanf("%d", &key);
            deleteNode(&root, key);
            break;
        case 5:
            cntLeafNode(root, &cnt);
            printf("Total leaf nodes = %d\n", cnt);
            cnt=0;
            break;
        case 6:
            printf("Height = %d\n", height(root));
            break;
        case 7:
            cntNodeRight(root->right, &cnt);
            printf("Total numbers of nodes from right hand side of root node = %d\n", cnt);
            cnt=0;
            break;
        }
    }while(ch <= 7);
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
//2. Function for Inorder Display
void inOrder(node *root){
    if(root != NULL){
        inOrder(root->left);
        printf("\t%d", root->info);
        inOrder(root->right);

    }
}
//3. Function for Search a particular key.
void searchKey(node *root, int key, node *parent){
    if(root == NULL){
        printf("\tKey is not found\n");
        return;
    }
    if(key == root->info){
        if(parent == NULL)
            printf("\n\tKey found at root node");
        else if(key < parent->info)
            printf("\n\tKey found at left side nodes");
        else
            printf("\n\tKey is found at right side nodes");
        return;
    }
    else if(key < root->info)
        searchKey(root->left, key, root);
    else
        searchKey(root->right, key, root);
}
//4. Function for "Delete a node".
void deleteNode(node **root, int key){
    node *tmp;
    if(*root == (node*) NULL){
        printf("\tElement is not found or tree is empty\t");
        return;
    }
    else if(key > (*root)->info)
        deleteNode(&((*root)->right), key);
    else if(key < (*root)->info)
        deleteNode(&((*root)->left), key);
    else if( (*root)->left && (*root)->right){
        tmp = findMaxElement( (*root)->left);
        (*root)->info = tmp->info;
        deleteNode( &((*root)->left), tmp->info);
    }
    else{
        tmp = *root;
        if( ((*root)->left)==NULL && ((*root)->right)==NULL)
            *root = (node *) NULL;
        else if( (*root)->left != NULL)
            *root = (*root)->left;
        else
            *root = (*root)->right;
        free(tmp);
    }
}
node *findMaxElement(node *root){
    if( (root==(node *) NULL) || (root->right==(node *) NULL))
        return root;
    else
        return findMaxElement(root->right);
}
//5. Function to find total number of leaf nodes.
void cntLeafNode(node *root, int *cnt){
    if(root != NULL){
        cntLeafNode(root->left, cnt);
        if(root->left==NULL && root->right==NULL){
            (*cnt)++;
        }
        cntLeafNode(root->right, cnt);
    }
}
//6. Function to find height of a binary search tree.
int height(node *root){
    if(root != NULL){
        //compute the depth of each subtree
        int leftSide = height(root->left);
        int rightSide = height(root->right);

        //use the larger one
        if(leftSide > rightSide)
            return (leftSide + 1);
        else
            return (rightSide + 1);
    }
}
//7. Function to count total numbers of nodes from right hand side of root node.
void cntNodeRight(node *root, int *cnt){
    if(root != NULL){
        (*cnt)++;
        cntNodeRight(root->left, cnt);
        cntNodeRight(root->right, cnt);
    }
}
/***************OUTPUT***************
---Menu---
1. Insert
2. InOrder
3. Search for a key
4. Delete a node
5. Count Leaf nodes
6. Find height
7. Count right nodes
Enter your choice: 1
Enter an element: 200

---Menu---
1. Insert
2. InOrder
3. Search for a key
4. Delete a node
5. Count Leaf nodes
6. Find height
7. Count right nodes
Enter your choice: 1
Enter an element: 100

---Menu---
1. Insert
2. InOrder
3. Search for a key
4. Delete a node
5. Count Leaf nodes
6. Find height
7. Count right nodes
Enter your choice: 1
Enter an element: 300

---Menu---
1. Insert
2. InOrder
3. Search for a key
4. Delete a node
5. Count Leaf nodes
6. Find height
7. Count right nodes
Enter your choice: 1
Enter an element: 250

---Menu---
1. Insert
2. InOrder
3. Search for a key
4. Delete a node
5. Count Leaf nodes
6. Find height
7. Count right nodes
Enter your choice: 1
Enter an element: 350

---Menu---
1. Insert
2. InOrder
3. Search for a key
4. Delete a node
5. Count Leaf nodes
6. Find height
7. Count right nodes
Enter your choice: 3
Enter the key: 250

        Key found at left side nodes
---Menu---
1. Insert
2. InOrder
3. Search for a key
4. Delete a node
5. Count Leaf nodes
6. Find height
7. Count right nodes
Enter your choice: 4
Enter the value of key: 300

---Menu---
1. Insert
2. InOrder
3. Search for a key
4. Delete a node
5. Count Leaf nodes
6. Find height
7. Count right nodes
Enter your choice: 2
        100     200     250     350
---Menu---
1. Insert
2. InOrder
3. Search for a key
4. Delete a node
5. Count Leaf nodes
6. Find height
7. Count right nodes
Enter your choice: 5
Total leaf nodes = 2

---Menu---
1. Insert
2. InOrder
3. Search for a key
4. Delete a node
5. Count Leaf nodes
6. Find height
7. Count right nodes
Enter your choice: 6
Height = 3

---Menu---
1. Insert
2. InOrder
3. Search for a key
4. Delete a node
5. Count Leaf nodes
6. Find height
7. Count right nodes
Enter your choice: 7
Total numbers of nodes from right hand side of root node = 2
************************************/
