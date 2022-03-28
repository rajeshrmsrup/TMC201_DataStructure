#include<stdio.h>
//1. Function to find Even and Odd.
void evOdd(int ar[], int n){
    int i, ar1[n], ar2[n];
    for(i=0; i<n; i++){
        ar1[i] = ar2[i] = 0;
        if(ar[i]%2 == 0)
            ar1[i] = ar[i];
        else
            ar2[i] = ar[i];
    }
    printf("---Even---\n");
    for(i=0; i<n; i++){
        if(ar1[i] != 0)
        printf("%d\t", ar1[i]);
    }
    printf("\n---Odd---\n");
    for(i=0; i<n; i++){
        if(ar2[i] != 0)
            printf("%d\t", ar2[i]);
    }
}

//2. Functions...
// To find Palindrome.
int palindrome(int num){
    int tmp, rem, rev=0;
    tmp = num;
    while(num != 0){
        rem = num%10;
        rev = rev*10 + rem;
        num /= 10;
    }
    if(rev == tmp)
        return 0;
    else
        return 1;
}
//To find Armstrong.
int armstrong(int num){
    int tmp, rem, sum=0;
    tmp = num;
    while(num != 0){
        rem = num%10;
        sum += rem*rem*rem;
        num /= 10;
    }
    if(sum == tmp)
        return 0;
    else
        return 1;
}
//To calculate sum of digits.
int sum(int num){
    int rem, sum=0;
    while(num != 0){
        rem = num%10;
        sum += rem;
        num /= 10;
    }
    return sum;
}
//To check prime numbers.
void prime(int ar[], int n){
    int i, j, flg=0;
    for(i=0; i<n; i++){
        flg = 0;
        for(j=2; j<ar[i]; j++){
            if(ar[i]%j == 0){
                flg=1;
                break;
            }
        }
        if(flg == 0)
            printf("%d\t", ar[i]);
    }
}
//Function to implement case 2.
void nestSwitch(int ar[], int n, int ch2){
    int i, cnt=0;
    switch(ch2){
        case 1:
            for(int i=0; i<n; i++)
                if(palindrome(ar[i]) == 0)
                    cnt++;
            printf("\n---Output---\nTotal no. of palindrome numbers = %d", cnt);
            break;
        case 2:
            for(int i=0; i<n; i++)
                if(armstrong(ar[i]) == 0)
                    cnt++;
            printf("\n---Output---\nTotal no. of Armstrong numbers = %d", cnt);
            break;
        case 3:
            printf("\n---Output---\n");
            for(int i=0; i<n; i++)
                printf("Sum of %d = %d\n", ar[i], sum(ar[i]));
            break;
        case 4:
            printf("\n---Output---\nPrime numbers are = ");
            prime(ar, n);
            break;
        default: printf("Not a valid choice: ");
    }
}

//3. Function to check AP or not.
void ap(int ar[], int n){
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
        printf("is not AP.");
    }
}

//4. function to find missing term.
void misTrm(int ar[], int n){
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
        printf("No missing term");
    else
        printf("The missing term is %d", ar[i]+d);
}

//5. Function to separate +ve, -ve, & 0 elements.
void sepPNZ(int ar[], int n){
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
//6. Separate -ve & +ve elements on the sides of array
void sepPN(int ar[], int n){
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

//7. Function to 4th Non-repeating and Repeating element.
int nonRepEle(int ar[], int n){
    int i, j, ele;
    int cnt = 1;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(ar[i]==ar[j] && i!=j)
                break;
        }
        if(j == n ){
            if(cnt == 4){
                ele = ar[i];
                break;
            }
            else
                ele=0;
            ++cnt;
        }
    }
    return ele;
}
int repEle(int ar[], int n){
    int i, j, ele;
    int cnt = 0;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(ar[i]==ar[j] && i!=j && ar[i]>=0){
                ar[j] = -1;
                cnt++;
                break;
            }
        }
        if(cnt == 4){
            ele = ar[i];
            break;
        }
        else
            ele=0;
    }
    return ele;
}
//8. Function to find frequency of each element.
void frq(int ar[], int n){
    int i, j, cnt;
    for(i=0; i<n; i++){
        cnt=1;
        for(j=0; j<n; j++){
            if(ar[i]==ar[j] && i!=j && ar[i] > 0){
                ar[j] = -1;
                cnt++;
            }
        }
        if(ar[i] > 0)
            printf("%d = %d times\n", ar[i], cnt);
    }
}

//9. Functions to find Union & intersection.
void uni(int ara[], int arb[], int n){
    int  i, j, flg=0;
    printf("Union = ");
    for(i=0; i<n; i++)
        printf("%d\t", ara[i]);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(arb[i] == ara[j])
                flg=1;
        }
        if(flg == 0)
            printf("%d\t", arb[i]);
        flg=0;
    }
}
void inte(int ara[], int arb[], int n){
    int  i, j;
    uni(ara, arb, n);
    printf("\nIntersection = ");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(arb[i] == ara[j])
                printf("%d\t", arb[i]);
        }
    }
}

int main(){
    int n, i, ch1, ch2, ch3;
    printf("Enter the total number of elements: ");
    scanf("%d", &n);
    int a[n], b[n];
    printf("---Enter %d elements---\n", n);
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);

    printf("---Menu---");
    printf("\n1. Print Even and Odd elements.");
    printf("\n2. Count the following...");
    printf("\n\t1. Total no. of palindrome.");
    printf("\n\t2. Total no. of armstrong.");
    printf("\n\t3. Sum of digit of each element.");
    printf("\n\t4. Total no. of Prime.");
    printf("\n3. Check series is AP or not.");
    printf("\n4. Find and print missing term in AP.");
    printf("\n5. Separate +ve, -ve, & 0 elements.");
    printf("\n6. Separate +ve and -ve elements in same array.");
    printf("\n7. Display 4th Non-repeating and Repeating element.");
    printf("\n\t1. 4th Non-repeating element\n\t2. 4th Repeating element");
    printf("\n8. Display the frequency of each element.");
    printf("\n9. Print Union & Intersection.");
    printf("\n10. Exit");
    printf("\n--------------------------------------\n");
    printf("\nEnter your choice above menu: ");
    scanf("%d", &ch1);
    switch(ch1){
        case 1:
            printf("\n---Output---\n");
            evOdd(a, n);
            break;
        case 2:
            printf("Select sub choice: ");
            scanf("%d", &ch2);
            nestSwitch(a, n, ch2);
            break;
        case 3: ap(a, n); break;
        case 4:
            printf("\n---Output---\n");
            misTrm(a, n);
            break;
        case 5: sepPNZ(a, n); break;
        case 6: sepPN(a, n);
            printf("\n---output---\n");
            for(i=0; i<n; i++)
                printf("%d\t", a[i]);
            break;
        case 7:
            printf("Select sub Choice: ");
            scanf("%d", &ch3);
            switch(ch3){
                case 1: printf("\n---Output---\n4th Non-repeating element is %d", nonRepEle(a,n)); break;
                case 2: printf("\n---Output---\n4th Repeating element is %d", repEle(a,n)); break;
                default: printf("\n Select a valid option: ");
            } break;
        case 8:
            printf("\n---Output--\n");
            frq(a, n);
            break;
        case 9:
            printf("---Enter 2nd array---\n");
            for(i=0; i<n; i++)
                scanf("%d", &b[i]);
            printf("\n---Output---\n");
            inte(a, b, n);
            break;
        case 10: exit(1);
        default: printf("Wrong input");
    }
}
