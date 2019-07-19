/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** create_key
*/

#include "prototypes.h"

int key_length(sk_t *key)
{
    double length = (double)strlen(key->string);

    length = sqrt(length);
    length = ceil(length);
    key->size = (int)length;
}

void fill_key_matrix(sk_t *key, int i, int j)
{
    int string_size = strlen(key->string);

    if (string_size < i * key->size + j)
        key->matrix[i][j] = 0;
    else
        key->matrix[i][j] = key->string[i*key->size + j];
}

void print_possible_tab(int j, int key_size)
{
    if (j != key_size - 1)
        printf("\t");
}

sk_t *key_create(char *string_key)
{
    sk_t *key = malloc(sizeof(sk_t));
    key->string = string_key;
    key_length(key);
    key->matrix = matrix_create(key->size, key->size);
    int string_size = strlen(key->string);

    for (int i = 0; i < key->size; i++)
        for (int j = 0; j < key->size; j++)
            fill_key_matrix(key, i, j);
    printf("Key matrix:\n");
    for (int i = 0; i < key->size; i++) {
        for (int j = 0; j < key->size; j++) {
            printf("%d", key->matrix[i][j]);
            print_possible_tab(j, key->size);
        }
        printf("\n");
    }
    return (key);
}