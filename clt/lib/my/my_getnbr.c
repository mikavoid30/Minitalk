/*
** my_getnbr.c for my_getnbr in /home/boulat_m/rendu/Piscine_C_J04
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Oct  2 11:46:04 2014 Mickael BOULAT
** Last update Wed Oct  8 10:39:22 2014 Mickael BOULAT
*/
#include <string.h>

int	my_getnbr(char *str)
{
  long	result;
  int	multiplier;
  int	counter;
  char	*precedent;
  char	stop;
  char	after;

  result = 0;
  after = 0;
  stop = 0;
  precedent = NULL;
  counter = 0;
  multiplier = 1;
  while ((*str != '\0') && (stop == 0))
    {
      if ((*str > 48) && (*str < 57) && (*str != 0))
	{
	  after = 1;
	  precedent = str - 1;
	  if (*precedent == '-')
	    multiplier = -1;
	  result = (*str - 48) + (result * 10);
	}
      else
	{
	  if (after == 1)
	    {
	      stop = 1;
	    }
	}
      str = str + 1;
    }
  result = multiplier * result;
  if ((result < -2147483648) || (result > 2147483647))
    {
      result = 0;
    }
  return ((int)result);
}
