#include<stdio.h>
#include<stdlib.h>
void evOdd(int *ar, int n){
    int i;
    printf("\n---Even numbers---\n");
    for(i=0; i<n; i++){
        if(ar[i]%2==0)
            printf("%d\t", ar[i]);
    }
    printf("\n---Odd numbers---\n");
    for(i=0; i<n; i++){
        if(ar[i]%2 != 0)
            printf("%d\t", ar[i]);
    }
}
int main(){
    int *ptr, i, n;
    printf("Enter total no. of elements: ");
    scanf("%d", &n);
    ptr = (int*)malloc(n*sizeof(int));

    printf("Enter %d elements\n", n);
    for(i=0; i<n; i++)
        scanf("%d", ptr+i);
    evOdd(ptr, n);
}
