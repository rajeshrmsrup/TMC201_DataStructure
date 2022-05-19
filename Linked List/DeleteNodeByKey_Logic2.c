//Program to implement linked list and delete a node by key match.
#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int info;
    struct stack *next;
}node;
//Function Declarations...
node* push(node *);
node* delKey(node *, int);
void display(node *);
//Main Function
int main(){
    int ch, key;
    node *top=NULL;
    do{
        printf("\n---Menu---\n1. Push\n2. Delete Node by Key\n3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            top = push(top);
            break;
        case 2:
            printf("Enter the value of key: ");
            scanf("%d", &key);
            top = delKey(top, key);
            break;
        case 3:
            if(top==NULL)
                printf("\tList is Empty\n");
            else
                display(top);
        }
    }while(ch <= 3);
}

//function Definitions...
//1. Function for push
node* push(node *top){
    node *ptr = NULL;
    ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL)
        printf("\tNot enough memory, Can't Push\n");
    else{
        printf("Enter an element: ");
        scanf("%d", &ptr->info); //10,20
        ptr->next = top;
        top = ptr;
    }
    return top;
}
//2. function for delete node by key
node *delKey(node *top, int key){
    node *move, *tmp=top;
    move = top;
    if(top == NULL)
        printf("\tList is empty\n");
    else if(key == top->info){
        top = top->next;
    }
    else{
        while(key != move->info){
            move = move->next;
        }
        while(key != (tmp->next)->info){
            tmp = tmp->next;
        }
        tmp->next = move->next;
        move->next = NULL;
    }
    free(move);
    return top;
}
//3. funtion for display.
void display(node *top){
    printf("\n\t---Stack---");
    while(top != NULL){
        printf("\n\t%d", top->info);
        top=top->next;
    }
}
