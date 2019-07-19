/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** decrypt
*/

#include "prototypes.h"

int summ_fmatrix(message_t *message, sk_t *key, int i, int j)
{
    float somme = 0;
    int res = 0;

    for (int k = 0; k < key->size; k++)
        somme += message->fmatrix[i][k] * key->fmatrix[k][j];
    res = rond(somme);
    return (res);
}

void fill_key_fmatrix(sk_t *key, int i, int j)
{
    int string_size = strlen(key->string);

    if (string_size < i * key->size + j)
        key->fmatrix[i][j] = 0;
    else
        key->fmatrix[i][j] = key->string[i * key->size + j];
}

sk_t *key_create_decrypt(char *str)
{
    sk_t *key = malloc(sizeof(sk_t));
    int det;
    key->string = str;
    key_length(key);
    key->fmatrix = float_matrix_create(key->size, key->size);

    for (int i = 0; i < key->size; i++)
        for (int j = 0; j < key->size; j++)
            fill_key_fmatrix(key, i, j);
    if (key->size == 1) {
        key->fmatrix[0][0] = 1 / key->fmatrix[0][0];
        print_matrix(key);
        return (key);
    }
    det = determinant(key->fmatrix, key->size);
    reverse_matrix(key, det);
    print_matrix(key);
    return (key);
}

message_t *fill_matrix_msg(char *str, sk_t *key)
{
    int compt = 0;
    message_t *message = malloc(sizeof(message_t));
    int temp = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == ' ')
            compt++;
    compt++;
    if (compt % key->size > 0)
        compt += key->size - 1;
    init_message(message, key, str, compt);
    for (int i = 0; i < message->rows; i++)
        for (int j = 0; j < message->cols; j++) {
            message->fmatrix[i][j] =
            my_int_getnbr(message->string, i * message->cols + j + temp);
            temp += compt_int_len(my_int_getnbr(
            message->string, i * message->cols + j + temp));
        }
    return (message);
}

void decrypt(char *str_message, char *str_key)
{
    sk_t *key = key_create_decrypt(str_key);
    message_t *message = fill_matrix_msg(str_message, key);

    message->decrypted = matrix_create(message->rows, message->cols);
    for (int i = 0; i < message->rows; i++)
        for (int j = 0; j < message->cols; j++)
            message->decrypted[i][j] = summ_fmatrix(message, key, i, j);
    printf("\n\e[38;5;1mDecrypted message\e[0m\n\t\e[32;1m->\e[0m ");
    for (int i = 0; i < message->rows; i++)
        for (int j = 0; j < message->cols; j++)
            print_if_secure(message->decrypted[i][j]);
    printf(" \e[32;1m<-\e[0m\n");
    exit(0);
}