#include<stdio.h>
void sepPN(int *ar, int n){
    int i, j, tmp;
    for(i=1; i<n; i++){
        tmp = ar[i];
        if(tmp > 0)
            continue;
        j = i-1;
        while(j>=0 && ar[j] > 0){
            ar[j+1] = ar[j];
            j--;
        }
        ar[j+1] = tmp;
    }
}
int main(){
    int i, n;
    printf("Enter total no. of elements: ");
    scanf("%d", &n);

    int *ptr = (int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
        scanf("%d", ptr+i);

    sepPN(ptr, n);
    for(i=0; i<n; i++)
        printf("%d\t", *(ptr+i));
}

