/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** 
*/

#include <unistd.h>


int	my_getnbr(char *str)
{
  int	nb;
  int	isneg;
  int	i;

  isneg = 1;
  nb = 0;
  i = 0;

  while (str[i] != '\0')
    {

      if (str[i] >= '0' && str[i] <= '9' || str[i] <= '-')
	{
	  if(str[i] <= '-'){
		  isneg = 2;
	  }
	  if(str[i] >= '0' && str[i] <= '9'){
		  nb = nb * 10;
		  nb = nb + str[i] - '0';
	  }
	  i = i + 1;
	}
      else{
			if(isneg == 2){
			return (-nb);
			}
			return (nb);
		}
    }
  	if(isneg == 2){
		return (-nb);
	}
  return (nb * isneg);
}
