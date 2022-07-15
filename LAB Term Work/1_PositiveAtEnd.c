/*
Program to store N elements to an array and then send all positive elements
of the array to the end without altering the original sequence.
*/
/*
Name:           Rajesh Kumar
Roll No:        31
Course/Sem:     MCA-2nd
Sec:            B
*/
#include<stdio.h>
#define MAX 100
//Function Declaration.
void posEleAtEnd(int [], int);

//Main Function.
int main(){
    int a[MAX], n, i;
    printf("Enter the size of an array: ");
    scanf("%d", &n);
    printf("\t---Enter %d elements---\n", n);
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    printf("---Before---\n");
    for(i=0; i<n; i++)
        printf(" %d", a[i]);

    posEleAtEnd(a, n);
    printf("\n---After---\n");
    for(i=0; i<n; i++)
        printf(" %d", a[i]);
}

//Function Definition.
void posEleAtEnd(int a[], int n){
    int i, j;
    for(i=0; i<n; i++){
        int t=a[i];
        if(t > 0)
            continue;
        for(j=i-1; j>=0 && a[j]>=0; j--){
            a[j+1] = a[j];
        }
        a[j+1] = t;
    }
}
/***************OUTPUT***************
Enter the size of an array: 10
        ---Enter 10 elements---
5
6
-1
0
-2
-3
50
6
9
-10
---Before---
 5 6 -1 0 -2 -3 50 6 9 -10
---After---
 -1 -2 -3 -10 0 5 6 50 6 9
************************************/
