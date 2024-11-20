/*
This file contains basic of matrix, like multiplication of the matrices, transverse of the matrix and addition of the matrices.

You can use every feature in this file for any size of matrix.
*/

#include <stdio.h>

void create_matrix(int n, int mat[n][n]);

void log_matrix(int n, int mat[n][n]);

void transverse_matrix(int n, int mat[n][n]);

void matrices_addition(int n, int mat1[n][n], int mat2[n][n]);

void matrices_multiplication(int n, int mat1[n][n], int mat2[n][n]);

void main(){
    int n;

    printf("How many rows you want (NOTE: number of rows will be equal to coloums ");
    scanf("%d", &n);

    int a[n][n], b[n][n];

    printf("Creating first matrix\n");
    create_matrix(n, a);
    printf("Thanks for giving all the values of first matrix\n");
    printf("Creating second matrix\n");
    create_matrix(n, b);
    printf("Thanks for giving all the values of second matrix\n");

    matrices_addition(n, a, b);
    matrices_multiplication(n, a, b);
    printf("Transverse of the matrix: \n");
    log_matrix(n, a);
    transverse_matrix(n, a);
    printf("is\n");
    log_matrix(n, a);
    
}

void create_matrix(int n, int mat[n][n]){
    int i, j, val;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("Please enter the value of row %d and column %d: ", i + 1, j + 1);
            scanf("%d", &val);
            mat[i][j] = val;
        }
    }
}

void log_matrix(int n, int mat[n][n]){
    int i, j;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
}

void transverse_matrix(int n, int mat[n][n]){
    int i, j;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i <= j){
                continue;
            }
            /*
            a = a - b
            b = b + a
            a = b - a
            Using this formula we will swap values since transverse is nothing but swap of values
            In case you don't trust me you can check this if it is true or not by talking some random vlaues
            */
            mat[i][j] = mat[i][j] - mat[j][i];
            mat[j][i] = mat[j][i] + mat[i][j];
            mat[i][j] = mat[j][i] - mat[i][j];
        }
    }
}


void matrices_addition(int n, int mat1[n][n], int mat2[n][n]){
    int i, j, a[n][n];

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            a[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("The sum of matrix\n");
    log_matrix(n, mat1);
    printf("and matrix\n");
    log_matrix(n, mat2);
    printf("is\n");
    log_matrix(n, a);
}

void matrices_multiplication(int n, int mat1[n][n], int mat2[n][n]){
    int i, j, k, a[n][n];

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            a[i][j] = 0;
            for(k = 0; k < n; k++){
                a[i][j] += mat1[i][k] * mat2[k][j];
            }        
        }
    }

    printf("The multiplication of matrix\n");
    log_matrix(n, mat1);
    printf("and matrix\n");
    log_matrix(n, mat2);
    printf("is\n");
    log_matrix(n, a);
}