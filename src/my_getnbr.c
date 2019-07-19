/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** Get number from string
*/

int my_getnbr(char const *str)
{
    int first = 0;
    long nbr = 0;
    char sign = 1;

    while ((str[first] < '0' || str[first] > '9') && str[first])
        first++;
    for (int i = 0; i < first; i++)
        if (str[i] == '-')
            sign *= -1;
    for (int i = first; str[i] >= '0' && str[i] <= '9'; i++) {
        nbr = nbr * 10 + sign * (str[i] - '0');
        if (nbr != (int)nbr)
            return (0);
    }
    return (nbr);
}
