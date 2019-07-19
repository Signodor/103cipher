/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** determinant
*/

#include "prototypes.h"

int multiply(float **matrix, int fac, int size)
{
    int res;

    res = fac * determinant(matrix, size);
    return (res);
}

float **new_matrix(float **matrix, int col, int row, int size)
{
    float **res = float_matrix_create(size - 1, size - 1);
    int temp;
    int rows = 0;

    for (int j = 0; j < size - 1; j++) {
        temp = 0;
        rows += j == row;
        for (int k = 0; k < size - 1; k++) {
            temp += k == col;
            res[j][k] = matrix[rows][temp];
            temp++;
        }
        rows++;
    }
    return (res);
}

int determinant(float **matrix, int size)
{
    int det = 0;
    int sign = 1;

    if (size == 1)
        det = matrix[0][0];
    if (size == 2)
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    else {
        for (int i = 0; i < size; i++) {
            det += multiply(
                new_matrix(matrix, i, 0, size), matrix[0][i], size - 1) * sign;
            sign *= -1;
        }
    }
    return (det);
}