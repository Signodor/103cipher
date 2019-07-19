/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** reverse_matrix
*/

#include "prototypes.h"

void fmultiply(float **matrix, float divise, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] /= divise;
}

void reverse_little_one(sk_t *key)
{
    float **temp = copy_matrix(key->fmatrix, key->size);

    key->fmatrix[0][0] = temp[key->size - 1][key->size - 1];
    key->fmatrix[0][key->size - 1] = temp[key->size - 1][0];
    key->fmatrix[key->size - 1][0] = temp[0][key->size - 1];
    key->fmatrix[key->size - 1][key->size - 1] = temp[0][0];
    free(temp);
}

void reverse_matrix(sk_t *key, int det)
{
    float **temp = copy_matrix(key->fmatrix, key->size);

    for (int i = 0; i < key->size && key->size > 2; i++)
        for (int j = 0; j < key->size; j++)
            key->fmatrix[i][j] = determinant(new_matrix(
                temp, j, i, key->size), key->size - 1);
    if (key->size <= 2)
        reverse_little_one(key);
    if (key->size != 1) {
        change_sign(key);
        transform_matrix(key);
    }
    fmultiply(key->fmatrix, det, key->size);
}