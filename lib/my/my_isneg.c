/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** 
*/

void my_putchar(char c);

int my_isneg(int nb)
{
	if(nb < 0)
	{
		my_putchar('N');
		return (1);
	}
	else
	{
		my_putchar('P');
		return (0);
	}
}
