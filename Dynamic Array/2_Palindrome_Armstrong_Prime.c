#include<stdio.h>
#include<stdlib.h>
//Function to find Palindrome.
int palindrome(int num){
    int tmp, rem, rev=0;
    tmp=num;
    while(num != 0){
        rem = num % 10;
        rev = (rev * 10) + rem;
        num /=10;
    }
    if(tmp == rev)
        return 1;
    else
        return 0;
}

//Function to find Armstrong.
int armstrong(int num){
    int tmp=num, rem, sum=0;
    while(num != 0){
        rem = num % 10;
        sum += rem*rem*rem;
        num /= 10;
    }
    if(sum == tmp)
        return 1;
    else
        return 0;
}

//Function to calculate sum of each digit.
int sumOfDigits(int num){
    int rem, sum=0;
    while(num != 0){
        rem = num % 10;
        sum += rem;
        num /= 10;
    }
    return sum;
}

//Function to find prime numbers.
void prime(int *ar, int n){
    int i, j, flg=0, cnt=0;
    for(i=0; i<n; i++){
        flg = 0;
        for(j=1; j<=ar[i]; j++){
            if(ar[i]%j == 0){
                flg++;
            }
        }
        if(flg == 2){
            printf("%d\t", ar[i]);
            cnt++;
        }
    }
    printf("\nTotal no. of Armstrong = %d\n", cnt);
}

int main(){
    int i, n, ch, cnt=0;
    printf("Enter total no. of elements: ");
    scanf("%d", &n);
    int *ptr = (int*)malloc(n*sizeof(int));

    printf("Enter %d elements\n", n);
    for(i=0; i<n; i++)
        scanf("%d", ptr+i);

    printf("\n---Menu---");
    printf("\n1. Print Palindrome numbers & count.");
    printf("\n2. Print Armstrong numbers & count.");
    printf("\n3. Sum of digits of each element.");
    printf("\n4. Print Prime numbers & count.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch(ch){
        case 1:
            printf("\nPalindrome numbers are = ");
            for(i=0; i<n; i++){
                if(palindrome(*(ptr+i)) == 1){    //*(ptr+i) Means ptr[i]
                    printf("%d\t", *(ptr+i));
                    cnt++;
                }
            }
            printf("\nTotal no. of Palindrome = %d\n", cnt);
            break;
        case 2:
            printf("\nArmstrong numbers are = ");
            for(i=0; i<n; i++){
                if(armstrong(ptr[i]) == 1){    //ptr[i] Means *(ptr+i)
                    printf("%d\t", *(ptr+i));
                    cnt++;
                }
            }
            printf("\nTotal no. of Armstrong = %d\n", cnt);
            break;
        case 3:
            for(i=0; i<n; i++)
                printf("\nSum of %d = %d", ptr[i], sumOfDigits(ptr[i]));
            break;
        case 4:
            printf("\nPrime numbers are = ");
            prime(ptr, n);
            break;
        default: printf("\nWrong Input--Plz enter a valid input from menu.\n");
    }
}
