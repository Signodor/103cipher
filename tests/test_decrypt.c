/*
** EPITECH PROJECT, 2019
** 103cipher_2018
** File description:
** test_decrypt
*/

#include <criterion/criterion.h>
#include "prototypes.h"

Test(my_getnbr, telltale_test)
{
    cr_assert_eq(my_getnbr("12"), 12);
}

Test(my_getnbr, alphanumerics_behind_nb_test)
{
    cr_assert_eq(my_getnbr("12aeae"), 12);
}

Test(my_getnbr, neg_nb)
{
    cr_assert_eq(my_getnbr("-12"), -12);
}

Test(my_getnbr, spaces_before_nb)
{
    cr_assert_eq(my_getnbr("-12"), -12);
}

Test(my_getnbr, alphanumerics_before_nb)
{
    cr_assert_eq(my_getnbr("abcd-12"), -12);
}

Test(my_getnbr, no_nb)
{
    cr_assert_eq(my_getnbr("abcd"), 0);
}

Test(my_getnbr, long_and_not_int)
{
    cr_assert_eq(my_getnbr("112321323134645"), 0);
}

Test(my_int_getnbr, telltale_test)
{
    cr_assert_eq(my_int_getnbr("12", 0), 12);
}

Test(my_int_getnbr, neg_nb)
{
    cr_assert_eq(my_int_getnbr("-12", 0), -12);
}

Test(my_int_getnbr, spaces_before_nb)
{
    cr_assert_eq(my_int_getnbr("    -12", 0), -12);
}

Test(my_int_getnbr, alphanumerics_behind_nb_test)
{
    cr_assert_eq(my_int_getnbr("12aeae", 0), 12);
}

Test(my_int_getnbr, alphanumerics_before_nb)
{
    cr_assert_eq(my_int_getnbr("abcd-12", 0), -12);
}

Test(my_int_getnbr, no_nb)
{
    cr_assert_eq(my_int_getnbr("abcd", 0), 0);
}

Test(my_int_getnbr, long_and_not_int)
{
    cr_assert_eq(my_int_getnbr("112321323134645", 0), 0);
}

Test(decrypt, telltale_test, .exit_code = 0)
{
    decrypt("28291 30905 17447 18667 20470 15207 22447 26210 21083 30306 33837 21282 29276 32767 20788 7590 11155 11270", "dora");
}

Test(decrypt, remaining_zeros, .exit_code = 0)
{
    decrypt("28291 30905 17447 18667 20470 15207 22447 26210 21083 30306 33837 21282 29276 32767 20788", "dora");
}

Test(utils_sec, print_if_secure_with_no_c)
{
    print_if_secure('\0');
}