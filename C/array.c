/*
Few operations on array
*/ 

#include <stdio.h>
#include <limits.h>

#define macro_swap(a, b) a = a ^ b; b = a ^ b; a = a ^ b;

void input(int, int*);

void print(int, int*);

void print_even(int, int*);

void print_odd(int, int*);

void sum_avg(int, int*);

void max_min(int, int*);

void rmv_duplicates(int*, int*);

void reverse(int, int*);

void main() {
    int size;
    printf("Give me the size of the list: ");
    scanf("%d", &size);
    int array[size];
    input(size, array);
    // print(size, array);
    // print_even(size, array);
    // print_odd(size, array);
    // sum_avg(size, array);
    // max_min(size, array);
    // print(size, array);
    // reverse(size, array);
    print(size, array);
    rmv_duplicates(&size, array);
    print(size, array);
}

void input(int size, int* array) {
    for(int i = 0; i < size; i++) {
        printf("Enter the %d element: ", i+1);
        int val;
        scanf("%d", &array[i]);
    }
}

void print(int size, int* array) {
    printf("Elements in array are:\n");
    for(int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
}

void print_even(int size, int* array) {
    printf("The even valued elements in array are:\n");
    for(int i = 0; i < size; i++) {
        if(array[i]%2) continue;
        else printf("%d\n", array[i]);
    }
}

void print_odd(int size, int* array) {
    printf("The odd valued elements in array are:\n");
    for(int i = 0; i < size; i++) {
        if(array[i]%2) printf("%d\n", array[i]);
        else continue;
    }
}

void sum_avg(int size, int* array) {
    int sum = 0, avg;
    for(int i = 0; i < size; i++) {
        sum += array[i];
    }
    avg = sum/size;
    printf("The sum of all elements of the array is: %d\nAnd the average is: %d\n", sum, avg);
}

void max_min(int size, int* array) {
    int min = INT_MAX, max = INT_MIN;
    for(int i = 0; i < size; i++) {
        if(array[i] < min) min = array[i];
        if(array[i] > max) max = array[i];
    }
    printf("The maximum value in the array is: %d\nThe minimum value in the array is: %d\n", max, min);
}

void reverse(int size, int* array) {
    printf("Elements after reversed are:\n");
    for(int i = 0; i < size/2; i++) {
        macro_swap(array[i], array[size-1-i]);
    }
}

void rmv_duplicates(int* size, int* array) {
    printf("After removing duplicates \n");
    for(int i = 0; i < (*size); i++) {
        for(int j = i+1; j < (*size); j++) {
            if(array[i] == array[j]) {
                for(int k = j; k < (*size); k++) {
                    array[k] = array[k+1];
                }
                j--;
                (*size)--;
            }
        }
    }
}