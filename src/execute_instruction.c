/*
** execute_instruction.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue May 24 11:53:50 2016 CUENAT
** Last update Fri May 27 16:13:32 2016 CUENAT
*/

#include "shell.h"

int	ft_redirect_or_pipe(t_shell *shell, char *tkn)
{
  if (ft_execute_instr_no_fork(shell, tkn) == -1)
    {
       if (tkn != NULL)
	    {
	  printf("%s\n", shell->cur_exec[0]);
	  if (strcmp(tkn, ">") == 0)
	    ft_rewrite(shell->cur_exec[0], shell->fd_in);
	  else if (strcmp(tkn, ">>") == 0)
	    ft_write_at_end(shell->cur_exec[0], shell->fd_in);
	  else if (strcmp(tkn, "<") == 0)
	    ft_inredirect(shell->cur_exec[0], shell->fd_in);
	  else if (strcmp(tkn, "<<") == 0)
		{}
	  else if (execve(shell->cur_exec[0], shell->cur_exec,shell->env) < 0)
	    {
	      dprintf(2, "%s: Command not found.\n", shell->cur_exec[0]);
	      return (-1);
	    }
	}
    }
  return (0);
}

void	ft_execute_instr_fork_2(t_shell *shell,
				int tube[2],
				int pid)
{
  int	status;

  waitpid(pid, &status, WUNTRACED);
  (WIFEXITED(status)) ?
    (shell->res_exec = WEXITSTATUS(status)) : (shell->res_exec = -1);
  close(tube[1]);
  shell->fd_in = tube[0];
}
int		ft_execute_instr_fork(t_shell *shell, char *tkn, int end)
{
  int		tube[2];
  pid_t		pid;

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
    ft_execute_instr_fork_2(shell, tube, pid);
  return (0);
}

int    	ft_execute_instr_no_fork(t_shell *shell, char *tkn)
{
  void	(*ptr[8])(t_shell *shell);
  int  	i;

  ptr[0] = &ft_exit;
  ptr[1] = &ft_echo;
  ptr[2] = &ft_unsetenv;
  ptr[3] = &ft_setenv;
  ptr[4] = &ft_cd;
  ptr[5] = &ft_env;
  ptr[6] = &ft_source;
  ptr[7] = NULL;
  if ((i = ft_is_a_build_in(shell->cur_exec[0])) != -1)
    (ptr[i])(shell);
  else
    return (-1);
  (void)(tkn);
  if (i == 0)
    return (2);
  return (0);
}
