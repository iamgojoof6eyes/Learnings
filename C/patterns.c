/*
Code of few pattern printing
Take number of lines to be printed by the user
*/ 

#include <stdio.h>

void pattern1(int);

void pattern2(int);

void pattern3(int);

void pattern4(int);

void pattern5(int);

int even(int, int);

int odd(int, int);


void main(){
    int lines;

    printf("How many lines should I print? ");
    scanf("%d", &lines);

    pattern1(lines);

    pattern2(lines);

    pattern3(lines);

    pattern4(lines);

    pattern5(lines);
}

void pattern1(int lines){
    /*
    print:
    1
    1 2
    1 2 3
    1 2 3 4
    .
    .
    */
    printf("Printing Pattern 1:\n");
    for(int i=1; i <= lines; i++){
        for(int j=1; j<=i; j++){
            printf("%3d", j);
        }
        printf("\n");
    }
    printf("\n");
}

void pattern2(int lines){
    /*
    print:
    1
    2 3
    4 5 6
    7 8 9 10
    .
    .
    */
    printf("Printing Pattern 2:\n");
    int temp = 1;
    for(int i=1; i <= lines; i++){
        for(int j=1; j<=i; j++){
            printf("%3d", temp++);
        }
        printf("\n");
    }
    printf("\n");
}

void pattern3(int lines){
    /*
    print:
       1
     1 2 1
    1 2 3 2 1
    */
    printf("Printing Pattern 3:\n");
    int s;
    for(int i = 1; i <= lines; i++){
        for(s=lines-i; s > 0; s--){
            printf("   ");
        }
        for(int j = 1; j <= i; j++){
            printf("%3d",j);
        }
        for(int j = i-1; j > 0; j--){
            printf("%3d",j); 
        }
        printf("\n");
    }
    printf("\n");
}


void pattern4(int lines) {
    /*
    print:
        *
      * * *
    * * * * *
    */
   printf("Printing Pattern 4:\n");

   int i, j, s;

    for(int i = 1; i <= lines; i++){
        for(s=lines-i; s > 0; s--){
            printf("   ");
        }
        for(j=1; j<i*2; j++){
            printf(" * ");
        }
        printf("\n");
    }
   printf("\n");
}

int even(int row, int n) {
    int num = 1;
    for(int i = 1; i<=n-row; i++){
        num += 2;
    }
    return num;
}

int odd(int row, int col) {
    return (row-col + 1)*2;
}

void pattern5(int n) {
    /*
    Pattern:
    1
    2 11
    3 10 12
    4 9 13 18
    5 8 14 17 19
    6 7 15 16 20 21
    */
    int start;

    printf("Printing Pattern 5:\n");

    for(int i = 1; i <= n; i++) {
        start = i;
        printf("%5d", i);
        for(int j = 2; j <= i; j++) {
            if(j%2) {
                start += odd(i, j);
            }
            else {
                start += even(i, n);
            }
            printf("%5d", start);
        }
        printf("\n");
    }
    printf("\n");
}