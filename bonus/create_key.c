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

static void disp_floor(int size, int is_floor)
{
    printf("\e[33m+");
    for (int i = 0; i < (size * 8 - 5) / 2 - 7; i++)
        printf("-");
    if (is_floor)
        printf("[ \e[38;5;1mKey matrix\e[33m ]");
    else
        printf("--------------");
    for (int i = 0; i < (size * 8 - 5) / 2 - 7; i++)
        printf("-");
    printf("+\n");
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
    disp_floor(key->size, 1);
    for (int i = 0; i < key->size; i++) {
        printf("|\e[0m");
        for (int j = 0; j < key->size; j++) {
            printf("\e[38;5;105m%-3d", key->matrix[i][j]);
            print_possible_tab(j, key->size);
        }
        printf("\e[33m|\n");
    }
    disp_floor(key->size, 0);
    printf("\e[0m");
    return (key);
}