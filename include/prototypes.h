/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** prototypes
*/

#include "stdio.h"
#include <stdlib.h>
#include "unistd.h"
#include <string.h>
#include <math.h>

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_

typedef struct sk
{
    char const *string;
    int size;
    char **matrix;
    float **fmatrix;
} sk_t;

typedef struct message
{
    char const *string;
    int rows;
    int cols;
    char **matrix;
    float **fmatrix;
    int **encrypted;
    char **decrypted;
} message_t;

char **matrix_create(int rows, int cols);
int **int_matrix_create(int rows, int cols);
void encrypt(char *message, char *string_key);
sk_t *key_create(char *string_key);
float **float_matrix_create(int rows, int cols);
int compt_int_len(int x);
void reverse_matrix(sk_t *key, int det);
int key_length(sk_t *key);
void fill_key_matrix(sk_t *key, int i, int j);
int summ_matrix(message_t *message, sk_t *key, int i, int j);
int my_getnbr(char const *str);
int my_int_getnbr(char const *str, int start);
void decrypt(char *str_message, char *str_key);
int determinant(float **matrix, int size);
float **new_matrix(float **matrix, int col, int row, int size);
float **copy_matrix(float **matrix, int size);
void change_sign(sk_t *key);
void transform_matrix(sk_t *key);
int summ_fmatrix(message_t *message, sk_t *key, int i, int j);
int multiply(float **matrix, int fac, int size);
int rond(float src);
void init_message(message_t *message, sk_t *key, char *str, int compt);
void print_matrix(sk_t *key);
void hard_check_decrypt(char const *str);
void check_errors(char * const * argv);
void print_possible_space(int i, int j, int rows, int cols);
void print_if_secure(char c);
sk_t *key_create_decrypt(char *str);

#endif /* !PROTOTYPES_H_ */
