/*
** EPITECH PROJECT, 2020
** my compute square root lib
** File description:
** 
*/

#include<unistd.h>

void my_putchar(char c);

int my_compute_square_root(int nb)
{
    int i = 0;

    while (i * i != nb) {
        if (i * i > nb)
            return (0);
        else
            i++;
    }
    return (i);
}
