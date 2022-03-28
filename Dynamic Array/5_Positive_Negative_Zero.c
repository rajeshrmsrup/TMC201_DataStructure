#include<stdio.h>
#include<stdlib.h>
void sepPNZ(int *ar, int n){
    int i;
    int pcnt=0, ncnt=0, cnt=0;
    int pa[n], na[n], za[n];
    for(i=0; i<n; i++){
        if(ar[i] > 0){
            pa[pcnt] = ar[i];
            pcnt++;
        }
        else if(ar[i] < 0){
            na[ncnt] = ar[i];
            ncnt++;
        }
        else{
            za[cnt] = ar[i];
            cnt++;
        }
    }
    printf("\n---Output---\n");
    printf("Positive elements = ");
    for(i=0; i<pcnt; i++){
        printf("%d\t", pa[i]);
    }
    printf("\nNegative elements = ");
    for(i=0; i<ncnt; i++){
        printf("%d\t", na[i]);
    }
    printf("\nZeros elements = ");
    for(i=0; i<cnt; i++){
        printf("%d\t", za[i]);
    }
}
int main(){
    int i, n;
    printf("Enter total no. of elements: ");
    scanf("%d", &n);
    int *ptr = (int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
        scanf("%d", ptr+i);

    sepPNZ(ptr, n);
}
