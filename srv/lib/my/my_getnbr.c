/*
** my_getnbr.c for my_getnbr in /home/boulat_m/rendu/Piscine_C_J04
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Thu Oct  2 11:46:04 2014 Mickael BOULAT
** Last update Tue Nov 11 14:46:44 2014 Mickael BOULAT
*/

char	*get_multiplier(char *str)
{
  if (str[0] == '-')
    return(&str[1]);
  else
    return (str);
}

int	my_getnbr(char *str)
{
  int	multiplier;
  int	size;
  int	res;
  int	j;

  res = 0;
  j = 0;
  multiplier = 1;
  if (my_strlen(str) > my_strlen(str = get_multiplier(str)))
    multiplier = -1;
  if (my_str_isnum(str) == 0)
    {
      size = my_strlen(str) - 1;
      while (size >= 0)
	{
	  res = res + (my_power_rec(10, size) * (str[j] - 48));
	  j++;
	  size--;
	}
    }
  return (multiplier * res);
}
