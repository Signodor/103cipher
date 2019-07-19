/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** compt_int_len
*/

int compt_int_len(int x)
{
    if (x == 0)
        return (1);
    int j = 0;
    for (; x > 0; j++)
        x = x / 10;
    return (j);
}