/*
** check_options.c for  in /home/sanche_k/rendu/42sh/PSU_2015_42sh/src
** 
** Made by Sanchez Loris
** Login   <sanche_k@epitech.net>
** 
** Started on  Thu May 26 14:29:09 2016 Sanchez Loris
** Last update Thu May 26 15:34:40 2016 Sanchez Loris
*/

#include "shell.h"

void		check_options(int ac, char **av, t_shell *shell)
{
  if (strcmp(av[1], "-c") == 0)
    {
      if (ac == 3)
	exec_simple_cmd(av[2], shell);
      else
	exit(0);
    }
  else if (strcmp(av[1], "-h") == 0)
    {
      if (ac == 2)
	printf("\033[4mHELP\n\033[0m");
      else
	exit(0);
    }
  else
    print_usage();
}

void		exec_simple_cmd(char *line, t_shell *shell)
{
  shell->path = ft_fill_bin_path(shell->env);
  shell->res_exec = 0;
  line = replace_env(shell, line);
  line = epur(line);
  line = replace_alias(shell->alias, line);
  if (ft_check_input(line) == 0)
    {
      ft_create_list(shell, line);
      ft_create_sub_list(shell);
      ft_start_exec(shell);
      ft_free_struct(shell);
    }
  ft_free_tab(shell->path);
  free(line);
  exit(shell->res_exec);
}
