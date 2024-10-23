/*
This file contains basic of matrix, like multiplication of the matrices, transverse of the matrix and addition of the matrices.

You can use every feature in this file for any size of matrix.
*/

#include <stdio.h>

void create_matrix(int mat[3][3]);

void log_matrix(int mat[3][3]);

void transverse_matrix(int mat[3][3]);

void matrices_addition(int mat1[3][3], int mat2[3][3]);

void matrices_multiplication(int mat1[3][3], int mat2[3][3]);

void main(){
    int a[3][3], b[3][3];

    printf("Creating first matrix\n");
    create_matrix(a);
    printf("Thanks for giving all the values of first matrix\n");
    printf("Creating second matrix\n");
    create_matrix(b);
    printf("Thanks for giving all the values of second matrix\n");

    matrices_addition(a, b);
    matrices_multiplication(a, b);
    printf("Transverse of the matrix: \n");
    log_matrix(a);
    transverse_matrix(a);
    printf("is\n");
    log_matrix(a);
    
}

void create_matrix(int mat[3][3]){
    int i, j, val;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Please enter the value of row %d and column %d: ", i + 1, j + 1);
            scanf("%d", &val);
            mat[i][j] = val;
        }
    }
}

void log_matrix(int mat[3][3]){
    int i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
}

void transverse_matrix(int mat[3][3]){
    int i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
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


void matrices_addition(int mat1[3][3], int mat2[3][3]){
    int i, j, a[3][3];

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            a[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("The sum of matrix\n");
    log_matrix(mat1);
    printf("and matrix\n");
    log_matrix(mat2);
    printf("is\n");
    log_matrix(a);
}

void matrices_multiplication(int mat1[3][3], int mat2[3][3]){
    int i, j, k, a[3][3];

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            a[i][j] = 0;
            for(k = 0; k < 3; k++){
                a[i][j] += mat1[i][k] * mat2[k][j];
            }        
        }
    }

    printf("The multiplication of matrix\n");
    log_matrix(mat1);
    printf("and matrix\n");
    log_matrix(mat2);
    printf("is\n");
    log_matrix(a);
}