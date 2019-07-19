/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** utils2
*/

#include "prototypes.h"

void possible_display(int j, int key_size)
{
    if (j != key_size - 1)
        printf("\t");
}

void print_buffer(char *str)
{
    if (str[strlen(str) - 1] == '0')
        str[strlen(str) - 1] = 0;
    if (str[strlen(str) - 1] == '0')
        str[strlen(str) - 1] = 0;
    if (strcmp(str, "-0.0") == 0)
        printf("0.0");
    else
        printf("%s", str);

}

void print_matrix(sk_t *key)
{
    char *buffer = malloc(sizeof(char) * 10);

    printf("Key matrix:\n");
    for (int i = 0; i < key->size; i++) {
        for (int j = 0; j < key->size; j++) {
            sprintf(buffer, "%0.3f", key->fmatrix[i][j]);
            print_buffer(buffer);
            possible_display(j, key->size);
        }
        printf("\n");
    }
}

void print_if_secure(char c)
{
    if (c)
        printf("%c", c);
}