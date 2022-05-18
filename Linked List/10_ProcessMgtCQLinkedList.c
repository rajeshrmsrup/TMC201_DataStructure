#include<stdio.h>
#include<stdlib.h>
typedef struct CQ{
    int info;
    struct CQ *next;
}node;
node* insertTime(node *, node *, int);
void displayTable(node *, int);
int main(){
    node *left=NULL, *right=NULL;
    int i, n, ch, time;
    printf("Enter total no. of processes: ");
    scanf("%d", &n);
    do{
        printf("\n---Menu---\n1. Insert Time\n2. Display Process Table\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            for(i=1; i<=n; i++){
                printf("\nEnter completion time for P%d: ", i);
                scanf("%d", &time);
                right = insertTime(left, right, time);
                if(left == NULL)
                    left = right;
            }
            break;
        case 2:
            displayTable(left, n);
        }
    }while(ch <= 2);
}
node *insertTime(node *left, node *right, int time){
    node *p=NULL;
    p=(node*)malloc(sizeof(node));
    p->info = time;
    if(p==NULL)
        printf("\tCan't insert, bcoz don't have enough memory\n");
    else{
        if(left==NULL && right==NULL)
            left=right=p;
        else{
            right->next = p;
            right = p;
        }
        right->next = left;
    }
    return right;
}
void displayTable(node *left, int n){
    int i;
    node *tmp, *mx;
    tmp = left;
    mx = left;
    int wt=0, wt1=0;
    for(i=1; i<=n; i++)
        printf("\tP%d", i);
    printf("\n");
    do{
        wt += 10;
        printf("\t%d", tmp->info);
        tmp->info = tmp->info-10;
        tmp = tmp->next;
        if(tmp->info > mx->info)
            mx = tmp;
    }while(tmp != left);
    printf("\n");
    int size = mx->info/10;
    for(int i=0; i<size; i++){
        do{
            if(tmp->info >= 0){
                if(tmp->info > 0){
                    wt += 10;
                    printf("\t%d", tmp->info);
                }
                wt1 += 10;
            }
            if(tmp->info == 0){
                printf("\tWT = %d", wt1);
            }
            tmp->info = tmp->info-10;
            tmp = tmp->next;
        }while(tmp != left);
        printf("\n");
    }
    printf("\tWT = %d", wt);
}
/***************OUTPUT***************
Enter total no. of processes: 4

---Menu---
1. Insert Time
2. Display Process Table
3. Exit
Enter your choice: 1

Enter completion time for P1: 100

Enter completion time for P2: 70

Enter completion time for P3: 50

Enter completion time for P4: 20

---Menu---
1. Insert Time
2. Display Process Table
3. Exit
Enter your choice: 2
        P1      P2      P3      P4
        100     70      50      20
        90      60      40      10
        80      50      30      WT = 80
        70      40      20
        60      30      10
        50      20      WT = 170
        40      10
        30      WT = 210
        20
        10
        WT = 240
---Menu---
1. Insert Time
2. Display Process Table
3. Exit
Enter your choice: 3
************************************/
