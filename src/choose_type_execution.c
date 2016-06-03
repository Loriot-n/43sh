/*
** choose_type_execution.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 25 14:33:14 2016 CUENAT
** Last update Fri Jun  3 09:44:08 2016 Sanchez Loris
*/

#include "shell.h"

int	ft_is_a_build_in(char *cmd)
{
  char	*check[9];
  int	i;

  i = 0;
  check[0] = "exit";
  check[1] = "echo";
  check[2] = "unsetenv";
  check[3] = "setenv";
  check[4] = "cd";
  check[5] = "env";
  check[6] = "source";
  check[7] = "alias";
  check[8] = NULL;
  while (cmd && check[i])
    {
      if (strcmp(check[i], cmd) == 0)
	return (i);
      i += 1;
    }
  return (-1);
}

int	ft_choose_type_execution(t_shell *shell, char *tkn, int end)
{
  /*if (ft_execute_instr_no_fork(shell, tkn) != 2)*/
  if (ft_is_a_build_in(shell->cur_exec[0]) == 0)
    ft_execute_instr_no_fork(shell, tkn);
  else
    ft_execute_instr_fork(shell, tkn, end);
  return (0);
}
