/*
** EPITECH PROJECT, 2020
** my str os num with add and sub
** File description:
** test
*/

int my_str_isnum_with_add_and_sub(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] != 43 && str[i] != 45 && (str[i] < 48 || str[i] > 57))
            return (0);
    return (1);
}
