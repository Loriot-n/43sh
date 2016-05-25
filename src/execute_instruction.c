/*
** execute_instruction.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue May 24 11:53:50 2016 CUENAT
** Last update Wed May 25 16:47:58 2016 CUENAT
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
	      dprintf(2, "%s: Command not found.", shell->cur_exec[0]);
	      return (-1);
	    }
	}
    }
  return (0);
}

int		ft_execute_instr_fork(t_shell *shell, char *tkn, int end)
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
      shell->res_exec = ft_redirect_or_pipe(shell, tkn);
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

int    	ft_execute_instr_no_fork(t_shell *shell, char *tkn, int end)
{
  void	(*ptr[6])(t_shell *shell, char *tkn, int end);
  int  	i;
  int  	tube[2];

  ptr[0] = &ft_exit;
  ptr[1] = &ft_echo;
  ptr[2] = &ft_setenv;
  ptr[3] = &ft_unsetenv;
  ptr[4] = &ft_cd;
  ptr[5] = NULL;
  pipe(tube);
  dup2(shell->fd_in, 0);
  if (end == 0)
    dup2(tube[1], 1);
  close(tube[0]);
  if ((i = ft_is_a_build_in(shell->cur_exec[0])) != -1)
    (ptr[i])(shell, tkn, end);
  close(tube[1]);
    shell->fd_in = tube[0];
  return (0);
}
