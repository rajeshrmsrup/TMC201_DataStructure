//Program to implement Insertion Sort.
#include<stdio.h>
#define MAX 100
//Function declaration for Insertion Sort.
void insertionSort(int [], int);
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

    //Function call for Insertion Sort.
    insertionSort(ar, n);
    printf("\nAfter Sorting = ");
    for(i=0; i<n; i++)
        printf(" %d", ar[i]);
}
//Function definition for Insertion Sort.
void insertionSort(int ar[], int n){
    int i, j, tmp;
    for(i=1; i<n; i++){
        j = i-1;
        tmp = ar[i];
        while(j>=0 && tmp<ar[j]){
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = tmp;
    }

}
/***************OUTPUT***************
Enter the size of an array: 10

---Enter 10 elements---
12
0
15
1
52
3
6
789
2564
1
Before Sorting = 12 0 15 1 52 3 6 789 2564 1
After Sorting =  0 1 1 3 6 12 15 52 789 2564
************************************/
