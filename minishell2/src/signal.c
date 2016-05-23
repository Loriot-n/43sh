/*
** main.c for  in /home/stanislas/PSU_2015_minishell2/src
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 29 10:16:40 2016 CUENAT
** Last update Wed Apr 13 10:06:37 2016 CUENAT
*/

#include "include.h"
void	segfault(int sig)
{
  (void)(sig);
  my_putstr("segmentation fault \n$> ");
  exit(EXIT_FAILURE);
}

void	ctrl(int sig)
{
  (void)(sig);
  my_putstr("\n$> ");
}
