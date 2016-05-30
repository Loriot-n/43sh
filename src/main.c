/*
** main.c for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 18 15:48:14 2016 CUENAT
** Last update Thu May 26 14:28:40 2016 CUENAT
*/

#include "shell.h"

int		main(int ac, char **av, char **environ)
{
  t_shell	*shell;
  int		i;

  (void)(ac);
  (void)(av);
  // char **tab = split_no_const(strdup("echo \"ls -al | grep Makefile\""), " |");
  // printf("echo \"ls -al | grep Makefile\"\n");
  // for (int i = 0; tab[i]; i++)
  //   printf("%s\n", tab[i]);
  // return (0);
  shell = ft_init_struct();
  ft_fill_env(environ, shell);
  parse_options(shell, ".42shrc");
  write(2, "$> ", 3);
  ft_launch_shell(shell);
  ft_free_tab(shell->env);
  free_alias(shell->alias);
  (shell->res_exec == 0) ? (i = 0) : (i = 1);
  ft_free_struct(shell);
  putchar(10);
  return (i);
}
