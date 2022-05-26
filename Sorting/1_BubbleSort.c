//Program to implement Bubble Sort.
#include<stdio.h>
#define MAX 100
//Function declaration for Bubble Sort.
void bSort(int [], int);
//Main Function.
int main(){
    int n, i, ar[MAX];
    printf("Enter the size of an array: ");
    scanf("%d", &n);

    printf("\n---Enter %d elements---\n", n);
    for(i=0; i<n; i++)
        scanf("%d", &ar[i]);

    printf("Before Sorting =");
    for(i=0; i<n; i++)
        printf(" %d", ar[i]);

    //Function call for Bubble Sort.
    bSort(ar, n);
    printf("\nAfter Sorting = ");
    for(i=0; i<n; i++)
        printf(" %d", ar[i]);
}
//Function definition for Bubble Sort.
void bSort(int ar[], int n){
    int i, j, tmp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-1-i; j++){
            if(ar[j] > ar[j+1]){
                tmp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = tmp;
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
