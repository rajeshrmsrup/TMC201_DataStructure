#include<stdio.h>
#include<stdlib.h>
void misTrm(int *ar, int n){
    int i, d, flg=0;
    d = ar[1] - ar[0];
    for(i=1; i<n-1; i++){
        if(d == ar[i+1]-ar[i])
            flg=0;
        else{
            flg++;
            break;
        }
    }
    if(flg == 0)
        printf("No missing term\n");
    else
        printf("The missing term is %d\n", ar[i]+d);
}
int main(){
    int i, n;
    printf("Enter total no. of elements: ");
    scanf("%d", &n);

    int *ptr = (int*)malloc(n*sizeof(int));

    for(i=0; i<n; i++)
        scanf("%d", ptr+i);
    misTrm(ptr, n);

}
