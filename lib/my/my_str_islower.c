/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** 
*/

#include <unistd.h>

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            i++;
        else
            return (0);
    }
    return (1);
}
