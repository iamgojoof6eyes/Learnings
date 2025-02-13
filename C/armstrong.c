/*
In number theory, a narcissistic number in a given number base is a number that is the sum of its own digits each raised to the power of the number of digits.
Narcissistic numbers are also called armstrong numbers.
For example: 153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
*/

#include <stdio.h>
#include <math.h>

int num_length(int num);
int armstrong(int num, int length);

void main(){
    int n, l, arm;
    
    printf("Enter your number ");
    scanf("%d", &n);
    
    if(n <= 0){
        printf("Only natural numbers are allowed");
        return;
    }
    
    l = num_length(n);
    arm = armstrong(n, l);
    (arm == n) ? printf("%d is armstrong\n", n) : printf("%d is not an armstrong. The sum of the number raised to the length of number is %d\n", n, arm);
}

int num_length(int num){
    int count = 0;
    while(num > 0){
        count++;
        num /= 10;
    }
    return count;
}

int armstrong(int num, int length){
    int arm = 0, rem;
    while(num>0){
        rem = num % 10;
        arm = arm + pow(rem, length);
        num /= 10;
    }
    return arm;
    
}