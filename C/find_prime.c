/*
Code to find prime numbers between the given range
*/

#include <stdio.h>

int is_prime(int num){
    if (num==1){
        return 1;
    }
    for(int i = 2; i*i <= num; i++){
        if(!(num%i)){
            return 1; // number is prime
        }
    }
    return 0; // number is not prime
}

int main() {
    int left, right;
    
    printf("Enter the start value ");
    scanf("%d", &left);
    
    printf("Enter the last value ");
    scanf("%d", &right);
    
    int temp = left;
    
    printf("Printing all the prime number between %d and %d are\n", left, right);
    
    while(temp <= right){
        if (is_prime(temp)){
            temp++;
        }
        else{
            printf("%d\n", temp);
            temp++;
        }
    }
    
    return 0;
}