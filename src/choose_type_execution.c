/*
** choose_type_execution.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 25 14:33:14 2016 CUENAT
** Last update Wed May 25 15:12:50 2016 CUENAT
*/

#include "shell.h"

int	ft_is_a_build_in(char *cmd)
{
  char	**check;
  int	i;

  i = 0;
  if ((check = malloc(sizeof(char * ) * 6)) == NULL)
    exit(EXIT_FAILURE);
  check[0] = "cd";
  check[1] = "echo";
  check[2] = "exit";
  check[3] = "setenv";
  check[4] = "unsetenv";
  check[5] = NULL;
  while (check[i])
    {
      if (strcmp(check[i], cmd) == 0)
	return (i);
      i += 1;
    }
  return (-1);
}

int	ft_choose_type_execution(t_shell *shell, char *tkn, int end)
{
  if (ft_is_a_build_in(shell->cur_exec[0]) != -1)
    ft_execute_instr_no_fork(shell, tkn, end);
  else
    ft_execute_instr_fork(shell, tkn, end);
  return (0);
}
