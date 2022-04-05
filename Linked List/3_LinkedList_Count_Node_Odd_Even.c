/*Program to create linked list and then...
1. Count total no. of nodes
2. Count nodes having Odd info
3. Count nodes having Even info
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int info;
    struct node *next;
}node;

//Function for count Nodes
int cntNode(node *left){
    int cnt=0;
    printf("\tLinked List =");
    while(left != NULL){
        printf("\t%d", left->info);
        cnt++;
        left = left->next;
    }
    return cnt;
}
//Function to count node having odd info
int cntOdd(node *left){
    int cnt=0;
    while(left != NULL){
        if(left->info%2 != 0)
            cnt++;
        left = left->next;
    }
    return cnt;
}
//Function to count node having Even info
int cntEven(node *left){
    int cnt=0;
    while(left != NULL){
        if(left->info%2 == 0)
            cnt++;
        left = left->next;
    }
    return cnt;
}
int main(){
    int x, ch;
    node *ptr=NULL, *left=NULL;
    while(1){
        printf("Enter an element: ");
        scanf("%d", &x);
        ptr = (node*)malloc(sizeof(node));

        ptr->info = x;
        ptr->next = left;
        left = ptr;

        printf("\nDo you want to continue 1 or 0: ");
        scanf("%d", &ch);
        if(ch == 0)
            break;
    }
    printf("\n\tTotal no. of Nodes = %d", cntNode(left));
    printf("\n\tTotal no. of Nodes having Odd info = %d", cntOdd(left));
    printf("\n\tTotal no. of Nodes having Even info = %d", cntEven(left));
}
/***************OUTPUT***************
Enter an element: 10

Do you want to continue 1 or 0: 1
Enter an element: 20

Do you want to continue 1 or 0: 1
Enter an element: 25

Do you want to continue 1 or 0: 1
Enter an element: 1

Do you want to continue 1 or 0: 1
Enter an element: 5

Do you want to continue 1 or 0: 1
Enter an element: 4

Do you want to continue 1 or 0: 1
Enter an element: 3

Do you want to continue 1 or 0: 1
Enter an element: 8

Do you want to continue 1 or 0: 1
Enter an element: 11

Do you want to continue 1 or 0: 0
	Linked List =	11	8	3	4	5	1	25	20	10
	Total no. of Nodes = 9
	Total no. of Nodes having Odd info = 5
	Total no. of Nodes having Even info = 4
************************************/
