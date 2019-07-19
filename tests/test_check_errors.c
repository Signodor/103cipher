/*
** EPITECH PROJECT, 2019
** 103cipher_2018
** File description:
** test_check_errors
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "prototypes.h"

Test(hard_check_decrypt, exit_code, .exit_code = 84)
{
    hard_check_decrypt("Coucou les amis");
}

Test(hard_check_decrypt, telltale_test)
{
    hard_check_decrypt("12");
}

Test(hard_check_decrypt, exit_code_2, .exit_code = 84)
{
    hard_check_decrypt("12 13 | 14");
}

Test(check_errors, telltale_test)
{
    char *argv[3];
    argv[1] = "0";
    argv[2] = "1";
    argv[1] = "2";

    check_errors(argv);
}

Test(check_errors, exit_code_1, .exit_code = 84)
{
    char *argv[3];
    argv[1] = "0";
    argv[2] = "";
    argv[1] = "2";

    check_errors(argv);
}

Test(check_errors, exit_code_2, .exit_code = 84)
{
    char *argv[3];
    argv[1] = "0";
    argv[2] = "1";
    argv[1] = "";

    check_errors(argv);
}

Test(compt_int_len, x_equal_zero)
{
    cr_assert_eq(compt_int_len(0), 1);
}

Test(compt_int_len, x_is_sup_than_zero)
{
    cr_assert_eq(compt_int_len(123), 3);
}