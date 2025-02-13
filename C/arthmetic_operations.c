/*
Code for some arthmetical operations and series
*/

#include <stdio.h>

int sum_digits(int);

int product_digits(int);

float res_series_sum(int);

int alt_series_sum(int);

void factors(int);

void main() {
    int n;
    printf("Enter the digit you want to find the sum of and product of: ");
    scanf("%d", &n);
    printf("The sum of the digits of %d is %d\n", n, sum_digits(n));
    printf("The product of the digits of %d is %d\n", n, product_digits(n));
    printf("How many terms should I find sum of for S=1-2+3-4....N series\nGive me the n: ");
    scanf("%d", &n);
    printf("The sum of the series till %d terms is %d\n", n, alt_series_sum(n));
    printf("How many terms should I find sum of for S=1+1/2+1/3+1/4....N series\nGive me the n: ");
    scanf("%d", &n);
    printf("The sum of the series till %d terms is %.3f\n", n, res_series_sum(n));
    printf("Enter the digit you want to find factors of: ");
    scanf("%d", &n);
    factors(n);
}

int alt_series_sum(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++){
        // if(i%2) sum += i;
        (i%2) ? (sum += i) : (sum -= i);
        // else sum -= i;
    }
    return sum;
}

int sum_digits(int n) {
    int sum = 0;

    while(n>0) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int product_digits(int n) {
    int product = 1;
    while (n>0) {
        product *= n%10;
        n /= 10;
    }
    return product;    
}

float res_series_sum(int n) {
    float sum = 1;
    for (int i = 2; i <= n; i++) {
        sum += 1.0/(float) i;
    }
    return sum;
}

void factors(int n) {
    printf("The factor of %d are:\n", n);
    for(int i = 1; i <= n; i++) {
        if (n%i) {
            continue;
        }
        else {
            printf("%d\n", i);
        }
    }

}