/*
** execute_pipe.c for  in /home/stanislas/clone/PSU_2015_42sh/src
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Sat Jun  4 19:35:31 2016 CUENAT
** Last update Sun Jun  5 16:09:21 2016 CUENAT
*/

#include "shell.h"

int	ft_final_exec_pipe(t_shell *shell,
			   int pid,
			   int tube[2],
			   char *tkn)
{
  if ((pid = fork()) == -1)
    exit(EXIT_FAILURE);
  else if (pid == 0)
    {
      dup2(shell->fd_in, 0);
      close(tube[0]);
      ft_redirect_or_pipe(shell, tkn, shell->fd_in);
      close(tube[1]);
      exit(EXIT_FAILURE);
    }
  else
    {
      shell->nb_fork += 1;
      close(shell->fd_in);
      shell->fd_in = dup(tube[0]);
      close(tube[0]);
      close(tube[1]);
    }
  return (0);
}

void	ft_execute_instr_fork_pipe(t_shell *shell, int tube[2])
{
  shell->nb_fork += 1;
  close(shell->fd_in);
  shell->fd_in = dup(tube[0]);
  close(tube[0]);
  close(tube[1]);
}
