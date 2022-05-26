//Program to implement Bubble Sort.
#include<stdio.h>
#define MAX 100
//Function declaration for Bubble Sort.
void bSort(int [], int);
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

    //Function call for Bubble Sort.
    bSort(a, n);
    printf("\nAfter Sorting = ");
    for(i=0; i<n; i++)
        printf(" %d", a[i]);
}
//Function definition for Bubble Sort.
void bSort(int a[], int n){
    int i, j, tmp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-1-i; j++){
            if(a[j] > a[j+1]){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }

}
/***************OUTPUT***************
Enter the size of an array: 10

---Enter 10 elements---
5
2
1
10
2
0
15
36
99
4
Before Sorting = 5 2 1 10 2 0 15 36 99 4
After Sorting =  0 1 2 2 4 5 10 15 36 99
************************************/
