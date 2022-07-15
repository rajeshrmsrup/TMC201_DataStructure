/*
Program to sort an unsorted sequence of strings given by user in an array,
using Quick sort technique.
*/
/*
Name:           Rajesh Kumar
Roll No:        31
Course/Sem:     MCA-2nd
Sec:            B
*/
#include<stdio.h>
#include<string.h>
#define MAX 10
//Function declaration for QuickSort.
void quickSort(char a[][MAX], int, int);
//Main function
int main(){
    int i, n;
    char a[MAX][MAX];
    printf("Enter the array size: ");
    scanf("%d", &n);
    printf("\nEnter sequence of stings\n");
    for(i=0; i<n; i++)
        scanf("%s", a[i]);

    printf("\n\n---Before sort---\n");
    for(i=0; i<n; i++) {
        printf("\t%s", a[i]);
    }

    printf("\n\n---After sort---\n");
    quickSort(a, 0, n-1);
    for(i=0; i<n; i++) {
        printf("\t%s", a[i]);
    }
}

//Function definition for QuickSort.
void quickSort(char a[][MAX], int lb, int ub){
    int i, j;
    char *key;
    char temp[MAX];

    i = lb;
    j = ub;
    key = a[(lb+ub)/2];

    if(lb>=ub)
        return;
    while(i <= j){
        while((strcmp(a[i],key) < 0) && (i < ub)) {
            i++;
        }
        while((strcmp(a[j],key) > 0) && (j > lb)) {
            j--;
        }
        if(i <= j) {
            strcpy(temp, a[i]);
            strcpy(a[i], a[j]);
            strcpy(a[j], temp);
            i++;
            j--;
        }
    }
    quickSort(a, lb, j);
    quickSort(a, i, ub);
}
/***************OUTPUT***************
Enter the array size: 7

Enter sequence of stings
xyz
xzzy
xzyz
qwer
abcs
aasa
aaaa


---Before sort---
    xyz     xzzy    xzyz    qwer    abcs    aasa    aaaa

---After sort---
    aaaa    aasa    abcs    qwer    xyz     xzyz    xzzy
************************************/
