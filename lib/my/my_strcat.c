/*
** EPITECH PROJECT, 2020
** my str cat
** File description:
** copy a string at the end of another
*/

#include <unistd.h>
#include "my_strlen.c"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = my_strlen(dest);

    while (src[i] != '\0') {
        dest[j] = src[i];
        i+=1;
        j+=1;
    }
    dest[i + j] = '\0';
    return (dest);
}
