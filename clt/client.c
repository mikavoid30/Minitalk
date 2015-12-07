/*
** client.c for client minitalk in /home/boulat_m/rendu/Projets/PSU_2014_minitalk
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Nov 10 13:47:30 2014 Mickael BOULAT
** Last update Wed Nov 12 08:45:43 2014 Mickael BOULAT
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "include/my.h"

int		main(int argc, char **argv)
{
  int	i;
  int	pid;
  int	c;

  c = 0;
  if (argc > 2)
    {
      pid = my_getnbr(argv[1]);
      while (argv[2][c] != '\0')
	{
	  i = 0;
	  while (i < argv[2][c])
	    {
	      kill(pid, SIGUSR1);
	      usleep(TIME);
	      i++;
	    }
	  if (i == argv[2][c])
	    {
	      kill(pid, SIGUSR2);
	    }
	  c++;
	}
    }
  return (0);
}
