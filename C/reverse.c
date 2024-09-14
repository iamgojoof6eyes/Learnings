#include <stdio.h>

int main() {
    int n, rem, rev = 0;
    
    printf("Give a number ");
    scanf("%d", &n);
    
    int original = n;
    
    if (n < 0){
        printf("Reverse of a negative number is not possible.");
    }
    else{
        while(n > 0){
            rem = n % 10;
            rev = rev*10 + rem;
            n /= 10;
        }
        printf("Reverse of the number %d is %d", original, rev);
    }
    
    return 0;
}