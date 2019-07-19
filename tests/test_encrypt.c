/*
** EPITECH PROJECT, 2019
** 103cipher_2018
** File description:
** test_encrypt
*/

#include "prototypes.h"
#include <criterion/criterion.h>

Test(encrypt, telltale_test, .exit_code = 0)
{
    encrypt("Let's go friends", "Babouche");
}