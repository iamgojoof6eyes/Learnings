/*
Those natural numbers that only have two factors: the number itself and 1 are called prime numbers.

*/

#include <stdio.h>

int main(){
	int n, i = 2;
	
	printf("Enter your number ");
	scanf("%d", &n);

	// will loop from 2 to the square root of the given number or the square of the iterating number (basic maths)
	// Why till square root? Because a number has the lowest factor within its square root, for example, 15 its square root is 3.87 and 3 is a factor of 15 which is less than its square root, you can also loop it till n/2 if u want
	for(i; i*i <= n; i++){
		if(!(n%i)){
			printf("%d is not a prime number.\nOne of the factor of the number is: %d", n, i);
			return 0;
		}
	}
	
	printf("%d is a prime number.", n);
	
	return 0;
}
