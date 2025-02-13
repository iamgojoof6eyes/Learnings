/*
Code to swap variables (I am going to write using 4 different methods)
*/

#include <stdio.h>

#define macro_swap(a, b) int temp = a; a = b; b = temp;

void arth_swap(int, int);

void bit_swap(int, int);

void pnt_swap(int*, int*);

void main() {
    int x, y;
    printf("Enter your first number: ");
    scanf("%d", &x);
    printf("Enter your second number: ");
    scanf("%d", &y);
    printf("Number you have entered are: %d and %d\n", x, y);
    // arth_swap(x, y);
    // bit_swap(x, y);
    // pnt_swap(&x, &y);
    macro_swap(x, y);
    printf("Number after swap is %d and %d\n", x, y);
    
}

void arth_swap(int x, int y) { 
    // This will take pointers as the argments and change the values. Also it will not change the original references from outside of the function. However if u put this part inside the main function it will swap the variables
    x = x + y;
    y = x - y;
    x = x - y;
    printf("Number after swap is %d and %d\n", x, y);
}

void bit_swap(int x, int y) {
    // This will take pointers as the argments and change the values. Also it will not change the original references from outside of the function. However if u put this part inside the main function it will swap the variables
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    printf("Number after swap is %d and %d\n", x, y);
}

void pnt_swap(int* x, int* y) {
    // This will take pointers as the argments and change the values. Also it changes the original references as from outside the main function
    int temp = *x;
    *x = *y;
    *y = temp;
}