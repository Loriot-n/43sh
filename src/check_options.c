/*
** check_options.c for  in /home/sanche_k/rendu/42sh/PSU_2015_42sh/src
**
** Made by Sanchez Loris
** Login   <sanche_k@epitech.net>
**
** Started on  Thu May 26 14:29:09 2016 Sanchez Loris
** Last update Thu May 26 16:49:15 2016 Sanchez Loris
*/

#include "shell.h"

void		check_options(int ac, char **av, t_shell *shell)
{
  if (strcmp(av[1], "-c") == 0)
    {
      if (ac == 3)
	{
	  exec_simple_cmd(av[2], shell);
	  exit(shell->res_exec);
	}
      else
	exit(0);
    }
  else if (strcmp(av[1], "-h") == 0)
    {
      if (ac == 2)
	{
	  printf("\033[4m\nUsage options :\n"
	       "\n  -h : List the program options\n"
	       "\n  -c : Launch the command then quit the program\n\033[0m");
	  printf("\n  Usage : $>./42sh -c \"ls -la\"\n\n");
	  exit(0);
	}
      else
	exit(0);
    }
  else
    print_usage();
}

void		print_usage()
{
  printf("\033[31m\nPlease launch the binary with the -h\n"
	 "Option to know the list of options\n"
	 "\nBy the way, launch the binary without argument"
	 "\nIf you want to use it basically\n\n\033[0m");
  exit(0);
}

void		exec_simple_cmd(char *line, t_shell *shell)
{
  shell->path = ft_fill_bin_path(shell->env);
  line = replace_env(shell, line);
  line = epur(line);
  line = replace_alias(shell->alias, line);
  //line = replace_glob(line);
  if (ft_check_input(line) == 0)
    {
      ft_create_list(shell, line);
      ft_create_sub_list(shell);
      ft_start_exec(shell);
      ft_free_struct(shell);
    }
}
