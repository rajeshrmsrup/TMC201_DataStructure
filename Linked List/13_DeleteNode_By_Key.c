#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int info;
    struct stack *next;
}node;
//Function Declarations...
node* push(node *);
node* delKey(node *);
void display(node *);
//Main Function
int main(){
    int ch;
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
            top = delKey(top);
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
node *delKey(node *top){
    int key, cnt=0;
    node *tmp1, *tmp;
    tmp = top;
    printf("Enter the value of key: ");
    scanf("%d", &key);
    while(tmp != NULL){
        if(key == tmp->info){
            if(cnt == 0){
                top = tmp->next;
            }
            else{
                tmp1->next = tmp->next;
            }
            free(tmp);
            break;
        }
        else{
            cnt++;
            tmp1=tmp;
            tmp = tmp->next;
        }
    }
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
