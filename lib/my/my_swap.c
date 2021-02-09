/*
** EPITECH PROJECT, 2020
** my swap
** File description:
** simple rogram who swap two integers
*/

#include <unistd.h>

void my_putchar(char c);

void my_swap(int *a, int *b)
{
    int i = *a;
    *a = *b;
    *b = i;
}
