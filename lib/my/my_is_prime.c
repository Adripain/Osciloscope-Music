/*
** EPITECH PROJECT, 2020
** my is prime
** File description:
** 
*/

#include<unistd.h>

void my_putchar(char c);

int my_is_prime(int nb)
{
    int i = 2;
    if (nb == 2)
        return (1);
    else if (nb < 2)
        return (0);
    while (i < nb) {
        if (i % 2 == 0)
            return (0);
        i+=1;
    }
    return (1);
}
