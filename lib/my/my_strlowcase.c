/*
** EPITECH PROJECT, 2020
** my str lowcase
** File description:
** convert a string to itself in lowercase
*/

#include <unistd.h>

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        else
            return (NULL);
        i++;
    }
    return (str);
}
