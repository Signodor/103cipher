/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** utils
*/

#include "prototypes.h"

void init_message(message_t *message, sk_t *key, char *str, int compt)
{
    message->cols = key->size;
    message->rows = compt / key->size;
    message->string = str;
    message->fmatrix = float_matrix_create(message->rows, message->cols);
}

int rond(float src)
{
    int res = (int)src;
    int temp;

    src *= 10;
    temp = (int)src;
    for (int i = 0; temp > 9; i++)
        temp %= 10;
    if (temp >= 5)
        res++;
    return (res);
}

void change_sign(sk_t *key)
{
    int sign;

    for (int i = 0; i < key->size; i++)
        for (int j = 0; j < key->size; j++) {
            sign = (i + j) % 2 != 0 ? -1 : 1;
            key->fmatrix[i][j] *= sign;
        }
}

float **copy_matrix(float **matrix, int size)
{
    float **res = float_matrix_create(size, size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            res[i][j] = matrix[i][j];
    return (res);
}

void transform_matrix(sk_t *key)
{
    float **temp = float_matrix_create(key->size, key->size);

    for (int i = 0; i < key->size; i++)
        for (int j = i + 1; j < key->size; j++) {
            temp[i][j] = key->fmatrix[i][j];
            key->fmatrix[i][j] = key->fmatrix[j][i];
            key->fmatrix[j][i] = temp[i][j];
        }
    free(temp);
}