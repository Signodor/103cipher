/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** check_errors
*/

#include "prototypes.h"

void hard_check_decrypt(char const *str)
{
    for (int i = 0; str[i]; i++)
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ') {
            fprintf(stdout, "Error : invalid entry\n");
            exit(84);
        }
}

void check_errors(char * const * argv)
{
    if (!strlen(argv[1])) {
        fprintf(stdout, "Error : message empty\n");
        exit(84);
    }
    if (!strlen(argv[2])) {
        fprintf(stdout, "Error : please enter a key\n");
        exit(84);
    }
}