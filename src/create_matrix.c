/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** create_matrix
*/

#include "prototypes.h"

char **matrix_create(int rows, int cols)
{
    char **matrix = malloc(rows * sizeof(char *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(char));
        for (int j = 0; j < cols; j++)
            matrix[i][j] = 0;
    }
    return (matrix);
}

int **int_matrix_create(int rows, int cols)
{
    int **matrix = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
            matrix[i][j] = 0;
    }
    return (matrix);
}

float **float_matrix_create(int rows, int cols)
{
    float **matrix = malloc(rows * sizeof(float *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(float));
        for (int j = 0; j < cols; j++)
            matrix[i][j] = 0;
    }
    return (matrix);
}