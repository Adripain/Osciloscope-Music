/*
** EPITECH PROJECT, 2020
** my str n copy
** File description:
** copy n chars from a strin g from a momory loc to another
*/

#include <unistd.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0') {
        if (i < n) {
            dest[i] = src[i];
        }
        i+=1;
    }
    if (n > i)
        dest[i] = '\0';
    return dest;
}
