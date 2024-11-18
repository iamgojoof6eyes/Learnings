/*
Code of few pattern printing
Take number of lines to be printed by the user
*/ 

#include <stdio.h>

void pattern1(int);

void pattern2(int);

void pattern3(int);

void pattern4(int);

void main(){
    int lines;

    printf("How many lines should I print? ");
    scanf("%d", &lines);

    pattern1(lines);

    pattern2(lines);

    pattern3(lines);

    pattern4(lines);
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


void pattern4(int lines){
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