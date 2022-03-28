#include<stdio.h>
#include<stdlib.h>
void ap(int *ar, int n){
    int i, d, flg=0;
    d = ar[1] - ar[0];
    for(i=1; i<n-1; i++){
        if(d == ar[i+1]-ar[i]){
            d = ar[i+1]-ar[i];
            flg=0;
        }
        else{
            flg++;
            break;
        }
    }
    if(flg == 0){
        for(i=0; i<n; i++){
            printf("%d\t", ar[i]);
        }
        printf("is AP.");
    }
    else{
        for(i=0; i<n; i++){
            printf("%d\t", ar[i]);
        }
        printf("Series is not AP.\n");
    }
}
int main(){
    int i, n;
    printf("Enter the total no. of elements: ");
    scanf("%d", &n);

    int *ptr = (int*)malloc(n*sizeof(int));

    for(i=0; i<n; i++)
        scanf("%d", ptr+i);
    ap(ptr, n);
}
