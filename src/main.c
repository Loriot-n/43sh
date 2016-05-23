/*
** main.c for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 18 15:48:14 2016 CUENAT
** Last update Mon May 23 15:16:55 2016 CUENAT
*/

#include "shell.h"

int		main(int ac, char **av, char **environ)
{
  t_shell	*shell;

  (void)(ac);
  (void)(av);
  shell = ft_init_struct();
  ft_fill_env(environ, shell);
  ft_launch_shell(shell);
  ft_free_tab(shell->env);
  return (0);
}
