#include<stdio.h>
#define MAX 5
//Function for PUSH
void push(int stack[], int *top){
    *top = *top+1;
    printf("Enter an element: ");
    scanf("%d", &stack[*top]);
}

//Function for POP
void pop(int stack[], int *top){
    printf("\tPoped element is %d\n", stack[*top]);
    *top = *top-1;
}

//Function for DISPLAY
void display(int stack[], int top){
    printf("\n---Your Stack---\n");
    while(top >= 0){
        printf("\t%d\n", stack[top]);
        top--;
    }
}

//Function for PEEK
void peek(int stack[], int top){
    printf("\tPeek of stack is %d\n", stack[top]);
}
int main(){
    int ch, top=-1, stack[MAX];
    do{
        printf("\n---Menu---\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            if(top == MAX-1)
                printf("\tStack is Overflow\n");
            else
                push(stack, &top);
            display(stack, top);
            break;
        case 2:
            if(top == -1)
                printf("\tStack is Underflow\n");
            else
                pop(stack, &top);
            display(stack, top);
            break;
        case 3:
            if(top == -1)
                printf("\tStack is Empty\n");
            else
                display(stack, top);
            break;
        case 4:
            if(top == -1)
                printf("\tStack is Empty\n");
            else
                peek(stack, top);
        }
    }while(ch <= 4);
}
/***************OUTPUT****************
---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 1
Enter an element: 10

---Your Stack---
	10

---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 1
Enter an element: 20

---Your Stack---
	20
	10

---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 1
Enter an element: 30

---Your Stack---
	30
	20
	10

---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 1
Enter an element: 40

---Your Stack---
	40
	30
	20
	10

---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 1
Enter an element: 4

---Your Stack---
	4
	40
	30
	20
	10

---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 1
	Stack is Overflow

---Your Stack---
	4
	40
	30
	20
	10

---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 4
	Peek of stack is 4

---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 2
	Poped element is 4

---Your Stack---
	40
	30
	20
	10

---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 2
	Poped element is 40

---Your Stack---
	30
	20
	10

---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 2
	Poped element is 30

---Your Stack---
	20
	10

---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 4
	Peek of stack is 20

---Menu---
1. Push
2. Pop
3. Display
4. Peek
5. Exit
Enter your choice: 3

---Your Stack---
	20
	10
*************************************/
