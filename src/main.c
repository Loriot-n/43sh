/*
** main.c for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 18 15:48:14 2016 CUENAT
** Last update Wed May 25 15:28:32 2016 CUENAT
*/

#include "shell.h"

int		main(int ac, char **av, char **environ)
{
  t_shell	*shell;

  (void)(ac);
  (void)(av);
  shell = ft_init_struct();
  parse_options(shell, ".42shrc");
  ft_fill_env(environ, shell);
  //write(1, "$> ", 2);
  ft_launch_shell(shell);
  ft_free_tab(shell->env);
  putchar(10);
  return (0);
}
