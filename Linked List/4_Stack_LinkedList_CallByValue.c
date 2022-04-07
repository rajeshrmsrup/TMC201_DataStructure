//Program to implement STACK using "Linked List" with "Call By Value".
#include<stdio.h>
typedef struct stack{
    int info;
    struct stack *next;
}node;
//Function Declarations...
node* push(node *);
node* pop(node *);
void display(node *);
//Main Function
int main(){
    int ch;
    node *top=NULL;
    do{
        printf("\n---Menu---\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            top = push(top);
            display(top);
            break;
        case 2:
            if(top==NULL)
                printf("\tStack is Empty\n");
            else
                top = pop(top);
            break;
        case 3:
            if(top==NULL)
                printf("\tStack is Empty\n");
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

//2. Function for POP
node* pop(node *top){
    node *ptr=NULL;
    ptr = top;
    printf("\tPoped element is %d", top->info);
    top = top->next;
    free(ptr);
    return top;
}
//3. function for DISPLAY
void display(node *top){
    printf("\n\t---Stack---");
    while(top != NULL){
        printf("\n\t%d", top->info);
        top = top->next;
    }
}
/***************OUTPUT***************
---Menu---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter an element: 10

	---Stack---
	10
---Menu---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter an element: 20

	---Stack---
	20
	10
---Menu---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter an element: 30

	---Stack---
	30
	20
	10
---Menu---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
	Poped element is 30
---Menu---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
	Poped element is 20
---Menu---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3

	---Stack---
	10
---Menu---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
	Poped element is 10
---Menu---
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
	Stack is Empty
************************************/
