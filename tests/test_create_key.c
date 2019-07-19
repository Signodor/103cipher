/*
** EPITECH PROJECT, 2019
** 103cipher_2018
** File description:
** text_create_key
*/

#include "prototypes.h"
#include <criterion/criterion.h>

Test(key_create, create_key_of_length_of_two)
{
    sk_t *key = key_create("dora");

    cr_assert_str_eq(key->string, "dora");
}

Test(key_create, create_key_with_remaining_zeros)
{
    sk_t *key = key_create("diego");

    cr_assert_str_eq(key->string, "diego");
}

Test(key_create, create_key_inversed_with_remaining_zeros)
{
    sk_t *key = key_create_decrypt("diego");
    reverse_matrix(key, determinant(key->fmatrix, key->size));

    cr_assert_str_eq(key->string, "diego");
}

Test(key_create, create_key_inversed)
{
    sk_t *key = key_create_decrypt("dora");
    reverse_matrix(key, determinant(key->fmatrix, key->size));

    cr_assert_str_eq(key->string, "dora");
}

Test(key_create, create_key_inversed_long)
{
    sk_t *key = key_create_decrypt("chipper");
    reverse_matrix(key, determinant(key->fmatrix, key->size));

    cr_assert_str_eq(key->string, "chipper");
}

Test(key_create, create_key_inversed_short)
{
    sk_t *key = key_create_decrypt("Q");
    reverse_matrix(key, determinant(key->fmatrix, key->size));

    cr_assert_str_eq(key->string, "Q");
}

Test(int_matrix_create, zero_zero_matrix)
{
    int_matrix_create(0, 0);
    cr_assert_eq(1, 1);
}

Test(int_matrix_create, one_zero_matrix)
{
    int_matrix_create(1, 0);
    cr_assert_eq(1, 1);
}

Test(int_matrix_create, one_ten_matrix)
{
    int_matrix_create(1, 10);
    cr_assert_eq(1, 1);
}