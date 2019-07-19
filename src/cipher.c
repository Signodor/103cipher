/*
** EPITECH PROJECT, 2018
** 103cipher_2018
** File description:
** cipher
*/

#include "prototypes.h"

void display_usage(int ac, char **av)
{
    if (ac != 2 || strcmp(av[1], "-h"))
        exit(84);
    printf("\e[1mUSAGE\e[0m\n");
    printf("\t./103cipher message key flag\n\n");
    printf("\e[1mDESCRIPTION\e[0m\n");
    printf("\tmessage\t\ta message made of ASCII characters\n");
    printf("\tkey\t\tthe encryption key, made of ASCII characters\n");
    printf("\tflag\t\t0 to encrypt, 1 to decrypt\n");
    exit(0);
}

int main(int argc, char **argv)
{
    if (argc < 4)
        display_usage(argc, argv);
    check_errors(argv);
    if (strcmp(argv[3], "0") == 0)
        encrypt(argv[1], argv[2]);
    if (strcmp(argv[3], "1") == 0) {
        hard_check_decrypt(argv[1]);
        decrypt(argv[1], argv[2]);
    }
    return (84);
}