/*
** choose_type_execution.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 25 14:33:14 2016 CUENAT
** Last update Fri May 27 16:05:55 2016 CUENAT
*/

#include "shell.h"

int	ft_is_a_build_in(char *cmd)
{
  char	*check[7];
  int	i;

  i = 0;
  check[0] = "exit";
  check[1] = "echo";
  check[2] = "unsetenv";
  check[3] = "setenv";
  check[4] = "cd";
  check[5] = "env";
  check[6] = NULL;
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
  if (ft_execute_instr_no_fork(shell, tkn) != 2)
      ft_execute_instr_fork(shell, tkn, end);
  return (0);
}
