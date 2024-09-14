/*
Those number which only have two factors which are the number itself and 1 are called prime number.

*/

#include <stdio.h>

int main(){
	int n, i = 2;
	
	printf("Enter your number ");
	scanf("%d", &n);
	
	for(i; i*i <= n; i++){
		if(n%i == 0){
			printf("%d is not a prime number.", n);
			return 0;
		}
	}
	
	printf("%d is a prime number.", n);
	
	return 0;
}