/*
** execute_instruction.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue May 24 11:53:50 2016 CUENAT
** Last update Tue May 24 16:52:31 2016 CUENAT
*/

#include "shell.h"

int	ft_redirect_or_pipe(t_shell *shell, char *tkn)
{
  if (execve(shell->cur_exec[0], shell->cur_exec,shell->env) < 0)
    {
      if (tkn != NULL)
	{
	  if (strcmp(tkn, ">") == 0)
	    ft_rewrite(shell->cur_exec[0], shell->fd_in);
	  else if (strcmp(tkn, ">>") == 0)
	    ft_write_at_end(shell->cur_exec[0], shell->fd_in);
	  else if (strcmp(tkn, "<") == 0)
	    {}
	  else if (strcmp(tkn, "<<") == 0)
	    {}
	  else
	    {
	      dprintf(2,"%s : No such file or directory\n",
		      shell->cur_exec[0]);
	      return (-1);
	    }
	}
    }
  return (0);
}

int		ft_execute_instr(t_shell *shell, char *tkn, int end)
{
  int		tube[2];
  pid_t		pid;
  int		status;

  pipe(tube);
  if ((pid = fork()) == -1)
    exit(EXIT_FAILURE);
  else if (pid == 0)
    {
      dup2(shell->fd_in, 0);
      if (end == 0)
	dup2(tube[1], 1);
      close(tube[0]);
      ft_redirect_or_pipe(shell, tkn);
      exit(EXIT_FAILURE);
    }
  else
    {
      waitpid(pid, &status, WUNTRACED);
      close(tube[1]);
      shell->fd_in = tube[0];
    }
  return (0);
}
