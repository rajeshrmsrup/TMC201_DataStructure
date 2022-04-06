//Program to create "Singly Linked List" and Insert an element at "Left Hand".
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *next;
}node;
int main(){
    int x, ch;
    node *ptr=NULL, *left=NULL;
    while(1){
        printf("Enter an element: ");
        scanf("%d", &x);
        ptr = (node*)malloc(sizeof(node));

        ptr->info = x;
        ptr->next = left;
        left=ptr;

        printf("\nDo you want to continue 1 or 0: ");
        scanf("%d", &ch);
        if(ch == 0)
            break;
    }

    printf("\tLinked List =");
    int cnt=0;
    while(left != NULL){
        cnt++;
        printf("\t%d", left->info);
        left = left->next;
    }
    printf("count = %d", cnt);
}
