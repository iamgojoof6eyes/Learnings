/*
Factorial is a mathematical term where we multiply every integer smaller than or equal to the given number down to one. The "!" sign denotes it. For example, the factorial of 4 is written as 4! and equals to 4*3*2*1. 
It's worth noting that the factorial of 0 and 1 is 1 and for any negative integer factorial is not a real number.

I will write a code in C that will calculate the factorial of any given positive number.
*/


#include <stdio.h>

/*
//factorial using loop
int main() {
    int n, factorial = 1;
    
    printf("Give a positive number ");
    
    scanf("%d", &n);
    
    if (n == 1 || n == 0){
        printf("Factorial of %d is 1",n);
        return 0;
    }
    else if (n < 0){
        printf("Factorial of a negative number is not real.");
    }
    else{
        for(int i = n; i >= 1; i--){
            factorial *= i;
        }
    }
    printf("Factorial of %d is %d", n, factorial);

    return 0;
}
*/

//factorial using recursion
int factorial(int num);

int main() {
    int n, f;
    
    printf("Give a positive number ");
    
    scanf("%d", &n);
    
    if (n == 1 || n == 0){
        printf("Factorial of %d is 1",n);
    }
    else if (n < 0){
        printf("Factorial of a negative number is not real.");
    }
    else{
        f = factorial(n); 
        printf("Factorial of %d is %d", n, f);
    }
    return 0;
}

int factorial(int num){
    {
        if (num <= 1)
        return 1;
        else
        return num*factorial(num-1);
    }
}
