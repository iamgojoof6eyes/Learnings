/*
Code to find prime numbers between the given range
*/

#include <stdio.h>

int is_prime(int num){
    if (num==1){
        return 1;
    }
    for(int i = 2; i <= num/2; i++){
        if(num%i == 0){
            return 1;
        }
    }
    return 0;
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
        int prime = is_prime(temp);
        if (prime == 1){
            temp++;
        }
        else{
            printf(" %d ", temp);
            temp++;
        }
    }
    
    return 0;
}