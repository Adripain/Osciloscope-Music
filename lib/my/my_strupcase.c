/*
** EPITECH PROJECT, 2020
** my str upcase
** File description:
** convert a string to itself in lowercase
*/

#include <unistd.h>

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        else
            return (NULL);
        i++;
    }
    return (str);
}
