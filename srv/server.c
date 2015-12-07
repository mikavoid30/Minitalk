/*
** server.c for server minitalk in /home/boulat_m/rendu/Projets/PSU_2014_minitalk
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Nov 10 13:48:39 2014 Mickael BOULAT
** Last update Tue Nov 11 09:19:20 2014 Mickael BOULAT
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "include/my.h"

static int	g_counter = 0;

void	my_handle(int	sig)
{
  g_counter++;
}

void	my_handle2(int	sig)
{
  my_putchar(g_counter);
  g_counter = 0;
}

int		main(void)
{
  signal(SIGUSR1, my_handle);
  signal(SIGUSR2, my_handle2);
  my_putstrn("Server");
  my_put_nbrn(getpid());
  while (1)
    {
    } 
  return (0);
}
