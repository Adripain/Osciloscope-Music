/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** 
*/

#include <unistd.h>

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            i++;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            i++;
        else
            return (0);
    }
    return (1);
}
