#include<stdio.h>
#define MAX 100
//Function definitions...
//Function definition for mergeSort.
void mergeSort(int [], int [], int, int);
//Function definition for mergeArray.
void mergeArray(int [], int [], int, int, int);
//Main Function.
int main(){
    int a[MAX], t[MAX], n, i;
    printf("Enter the size of an Array: ");
    scanf("%d", &n);
    printf("---Enter %d elements---\n", n);
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    printf("Before Sorting: ");
    for(i=0; i<n; i++)
        printf("%d ", a[i]);

    mergeSort(a, t, 0, n-1);
    printf("\nAfter Sorting: ");
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
}
//Function Declarations...
//Function for mergeSort().
void mergeSort(int a[], int t[], int lb, int ub){
    int mid;
    if(lb < ub){
        mid = (lb+ub)/2;
        mergeSort(a, t, lb, mid);
        mergeSort(a, t, mid+1, ub);
        mergeArray(a, t, lb, mid, ub);
    }
}
//Function for mergeArray().
void mergeArray(int a[], int t[], int lb, int mid, int ub){
    int k=lb, l1=mid+1, i;
    while(lb<=mid && l1<=ub){
        if(a[lb] < a[l1]){
            t[k] = a[lb];
            k++;
            lb++;
        }
        else if(a[lb] > a[l1]){
            t[k] = a[l1];
            k++;
            l1++;
        }
    }
    while(lb <= mid){
        t[k] = a[lb];
        k++;
        lb++;
    }
    while(l1 <= ub){
        t[k] = a[l1];
        k++;
        l1++;
    }
    for(i=0; i<=ub; i++)
        a[i] = t[i];
}
