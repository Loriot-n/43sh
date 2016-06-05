/*
** execute_instruction.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue May 24 11:53:50 2016 CUENAT
** Last update Sun Jun  5 16:16:25 2016 CUENAT
*/

#include "shell.h"

int	ft_redirect_or_pipe(t_shell *shell, char *tkn, int fd_in)
{
  if (tkn != NULL)
    {
      if (strcmp(tkn, ">") == 0)
	ft_rewrite(shell->file);
      else if (strcmp(tkn, ">>") == 0)
	ft_write_at_end(shell->file);
      else if (strcmp(tkn, "<") == 0)
	ft_inredirect(shell->file, fd_in);
      else if (strcmp(tkn, "<<") == 0)
	ft_double_inredirect(shell->file);
    }
  if (ft_execute_instr_no_fork(shell, tkn) == -1)
    {
      if (execve(shell->cur_exec[0], shell->cur_exec, shell->env) < 0)
	{
	  if (errno == ENOENT)
	    dprintf(2, "%s: Command not found.\n", shell->cur_exec[0]);
	  else
	    dprintf(2, "%s: %s\n", shell->cur_exec[0], strerror(errno));
	  shell->res_exec = 1;
	  return (-1);
	}
    }
  return (0);
}

void	ft_execute_instr_fork_2(t_shell *shell)
{
  int	status;
  int	i;

  i = 0;
  while (i < shell->nb_fork)
    {
      status = 0;
      wait(&status);
      sig_handler(status);
      shell->res_exec = status % 255;
      i += 1;
    }
}

int		ft_final_exec(t_shell *shell, char *tkn)
{
  int		tube[2];
  pid_t		pid;

  pid = 0;
  if (pipe(tube) == -1)
    return (-1);
  if (ft_is_a_build_in(shell->cur_exec[0]) == -1)
    ft_final_exec_pipe(shell, pid, tube, tkn);
  else
    {
      close(tube[0]);
      close(tube[1]);
      close(shell->fd_in);
      ft_execute_instr_no_fork(shell, tkn);
    }
  return (0);
}

int		ft_execute_instr_fork(t_shell *shell, char *tkn, int end)
{
  int		tube[2];
  pid_t		pid;

  if (end == 0)
    {
      if (pipe(tube) == -1)
	return (-1);
      if ((pid = fork()) == -1)
	exit(EXIT_FAILURE);
      else if (pid == 0)
	{
	  dup2(shell->fd_in, 0);
	  close(tube[0]);
	  if (end == 0)
	    dup2(tube[1], 1);
	  close(tube[1]);
	  exit(ft_redirect_or_pipe(shell, tkn, shell->fd_in));
	}
      else
	ft_execute_instr_fork_pipe(shell, tube);
    }
  else
    ft_final_exec(shell, tkn);
  return (0);
}

int    	ft_execute_instr_no_fork(t_shell *shell, char *tkn)
{
  int	(*ptr[10])(t_shell *shell);
  int	i;
  int	k;

  ptr[0] = &ft_exit;
  ptr[1] = &ft_echo;
  ptr[2] = &ft_unsetenv;
  ptr[3] = &ft_setenv;
  ptr[4] = &ft_cd;
  ptr[5] = &ft_env;
  ptr[6] = &ft_source;
  ptr[7] = &ft_alias;
  ptr[8] = &ft_unalias;
  ptr[9] = NULL;
  if ((i = ft_is_a_build_in(shell->cur_exec[0])) != -1)
    k = (ptr[i])(shell);
  else
    return (-1);
  (void)(tkn);
  if (i == 0)
    return (2);
  if (k != 0)
    shell->res_exec = 1;
  return (0);
}
