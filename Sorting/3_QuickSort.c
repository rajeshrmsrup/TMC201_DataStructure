//Program to implement Quick Sort.
#include<stdio.h>
#define MAX 100
//Function declaration for Quick Sort.
void quickSort(int [], int, int);
//Main Function.
int main(){
    int n, i, a[MAX];
    printf("Enter the size of an array: ");
    scanf("%d", &n);

    printf("\n---Enter %d elements---\n", n);
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    printf("Before Sorting =");
    for(i=0; i<n; i++)
        printf(" %d", a[i]);
    //Function call for Quick Sort.
    quickSort(a, 0, n-1);
    printf("\nAfter Sorting = ");
    for(i=0; i<n; i++)
        printf(" %d", a[i]);
}
//Function definition for Quick Sort.
void quickSort(int a[], int lb, int ub){
    int i=lb, j=ub, key=a[lb], tmp=0;
    if(lb>=ub)
        return;
    while(i < j){
        while(key>=a[i] && i<j)
            i++;
        while(key<a[j])
            j--;
        if(i<j){
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    a[lb] = a[j];
    a[j] = key;

    quickSort(a, lb, j-1);
    quickSort(a, j+1, ub);
}
/***************OUTPUT***************
Enter the size of an array: 10

---Enter 10 elements---
5
1
2
10
3
80
75
26
11
23
Before Sorting = 5 1 2 10 3 80 75 26 11 23
After Sorting =  1 2 3 5 10 11 23 26 75 80
************************************/
