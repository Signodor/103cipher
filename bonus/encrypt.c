/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** encrypt
*/

#include "prototypes.h"

void fill_msg_matrix(message_t *message, int i, int j)
{
    int string_size = strlen(message->string);

    if (string_size < i * message->cols + j)
        message->matrix[i][j] = 0;
    else
        message->matrix[i][j] = message->string[i*message->cols + j];
}

message_t *message_to_clear(char *str_message, sk_t *key)
{
    message_t *message = malloc(sizeof(message_t));
    message->rows = (int)ceil((double)strlen(str_message)/(double)key->size);

    message->cols = key->size;
    message->string = str_message;
    message->matrix = matrix_create(message->rows, message->cols);
    for (int i = 0; i < message->rows; i++)
        for (int j = 0; j < message->cols; j++)
            fill_msg_matrix(message, i, j);
    return (message);
}

int summ_matrix(message_t *message, sk_t *key, int i, int j)
{
    int somme = 0;

    for (int k = 0; k < key->size; k++)
            somme += message->matrix[i][k] * key->matrix[k][j];
    return (somme);
}

void print_possible_space(int i, int j, int rows, int cols)
{
    if (j == cols - 1 && i == rows - 1)
        return;
    printf(" ");
}

void encrypt(char *str_message, char *string_key)
{
    sk_t *key = key_create(string_key);
    message_t *message = message_to_clear(str_message, key);

    message->encrypted = int_matrix_create(message->rows, message->cols);
    for (int i = 0; i < message->rows; i++)
        for (int j = 0; j < message->cols; j++)
            message->encrypted[i][j] = summ_matrix(message, key, i, j);
    printf("\n\e[38;5;1mEncrypted message\e[0m\n\t\e[32;1m->\e[0m ");
    for (int i = 0; i < message->rows; i++)
        for (int j = 0; j < message->cols; j++) {
            printf("%d", message->encrypted[i][j]);
            print_possible_space(i, j, message->rows, message->cols);
        }
    printf(" \e[32;1m<-\e[0m\n");
    exit(0);
}