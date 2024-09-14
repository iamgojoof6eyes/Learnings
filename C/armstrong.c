/*
Armstrong is a number of where the sum of cube of every single digit of the given number is equal to the original number.
For example: 153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
*/

#include <stdio.h>

int main(){
    int num, rem, arm = 0;
    
    printf("Give me a number ");
    scanf("%d", &num);

    int temp = num;

    while(temp > 0){
        rem = temp % 10;
        arm += rem*rem*rem;
        temp /= 10;
    }

    {
        if(num == arm)
        printf("%d is an armstrong", num);
        else
        printf("%d is not an armstrong\nThe sum of the cube of given number is %ld", num, arm);
    }
}