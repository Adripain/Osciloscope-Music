/*
** EPITECH PROJECT, 2020
** lib my compute power
** File description:
** 
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    else if (p < 0 || nb > (2147483647 / p))
        return 0;
    else
        return (nb * (my_compute_power_rec(nb, p - 1)));
}
