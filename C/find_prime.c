/*
Code to find prime numbers between the given range and also to check if the given number is prime or not
*/

#include <stdio.h>

int is_prime(int num){
    if (num==1){
        return 0;
    }
    for(int i = 2; i*i <= num; i++){
        if(!(num%i)){
            return 0; // number is not prime
        }
    }
    return 1; // number is prime
}

int main() {
    int left, right, n;
    printf("Enter a number you want to check if it is prime or not ");
    scanf("%d", &n);

    (is_prime(n)) ? printf("%d is a prime number\n", n) : printf("%d is not a prime number\n", n);

    printf("Now enter the start value of the range between which you want to print all prime number ");
    scanf("%d", &left);
    
    printf("Enter the last value ");
    scanf("%d", &right);
    
    int temp = left;
    
    printf("Printing all the prime number between %d and %d are\n", left, right);
    
    while(temp <= right){
        if (is_prime(temp)){
            printf("%d\n", temp);
            temp++;
        }
        else{
            temp++;
        }
    }
    
    return 0;
}