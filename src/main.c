/*
** main.c for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 18 15:48:14 2016 CUENAT
** Last update Mon May 30 15:16:04 2016 Sanchez Loris
*/

#include "shell.h"

int		main(int ac, char **av, char **environ)
{
  t_shell	*shell;
  int		i;

  (void)(ac);
  (void)(av);
  shell = ft_init_struct();
  ft_fill_env(environ, shell);
  if (ac != 1)
    {
      check_options(ac, av, shell);
    }
  write(1, "$> ", 3);
  parse_options(shell, ".42shrc");
  ft_launch_shell(shell);
  ft_free_tab(shell->env);
  free_alias(shell->alias);
  (shell->res_exec == 0) ? (i = 0) : (i = 1);
  ft_free_struct(shell);
  putchar(10);
  return (i);
}
