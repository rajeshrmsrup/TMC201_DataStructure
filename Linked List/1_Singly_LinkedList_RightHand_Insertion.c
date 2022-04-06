//Program to create "Singly Linked List" and Insert an element at "Right Hand".
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *next;
}node;
int main(){
    int x, ch;
    node *ptr=NULL, *left=NULL, *right=NULL;
    while(1){
        printf("Enter an Element: ");
        scanf("%d", &x);
        ptr = (node*)malloc(sizeof(node));

        ptr->info = x;
        if(left==NULL && right==NULL){
            left=right=ptr;
            right->next = NULL;
        }
        else{
            right->next = ptr;
            right=ptr;
            right->next = NULL;
        }
        printf("\nDo you want to continue 1 or 0: ");
        scanf("%d", &ch);
        if(ch == 0)
            break;
    }
    printf("\tLinked List =");
    while(left != NULL){
        printf("\t%d", left->info);
        left = left->next;
    }
}
