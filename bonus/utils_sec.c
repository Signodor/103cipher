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
        printf("    ");
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

static void disp_floor(int size, int is_floor)
{
    printf("\e[33m+");
    for (int i = 0; i < (size * 12 - 4) / 2 - 7; i++)
        printf("-");
    if (is_floor)
        printf("[ \e[38;5;1mKey matrix\e[33m ]");
    else
        printf("--------------");
    for (int i = 0; i < (size * 12 - 4) / 2 - 7; i++)
        printf("-");
    printf("+\n");
}

void print_matrix(sk_t *key)
{
    char *buffer = malloc(sizeof(char) * 10);

    disp_floor(key->size, 1);
    for (int i = 0; i < key->size; i++) {
        printf("|\e[0m");
        for (int j = 0; j < key->size; j++) {
            sprintf(buffer, "\e[38;5;105m%- 8.4f", key->fmatrix[i][j]);
            print_buffer(buffer);
            possible_display(j, key->size);
        }
        printf("\e[33m|\n");
    }
    disp_floor(key->size, 0);
}

void print_if_secure(char c)
{
    if (c)
        printf("%c", c);
}