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
        return 0;
    }
    else{
        f = factorial(n); 
    }
    printf("Factorial of %d is %d", n, f);

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
