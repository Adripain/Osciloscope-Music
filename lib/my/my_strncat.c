/*
** EPITECH PROJECT, 2020
** my strncat
** File description:
** do a copy of a string at the end of another, taking only n chars
*/

#include <unistd.h>
#include "my_strlen.c"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = my_strlen(dest);

    while (i < nb && src[i] != '\0') {
        dest[j] = src[i];
        i+=1;
        j+=1;
    }
    dest[i + j] = '\0';
    return (dest);
}
