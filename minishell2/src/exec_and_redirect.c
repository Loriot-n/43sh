/*
** exec_function.c for  in /home/stanislas/PSU_2015_minishell2/src
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed Mar 30 13:19:58 2016 CUENAT
** Last update Mon May 23 16:42:03 2016 CUENAT
*/

#include "include.h"

int	ft_exec_build(t_shell*shell)
{
  char	**build;
  void	(*build_ptr[5])(t_shell *shell);
  int	j;

  j = 0;
  (!(build = malloc(sizeof(char *) * 6))) ? (exit(-1)) : (0);
  build[0] = "cd";
  build[1] = "env";
  build[2] = "setenv";
  build[3] = "unsetenv";
  build[4] = "exit";
  build[5] = NULL;
  build_ptr[0] = &ft_cd;
  build_ptr[1] = &ft_env;
  build_ptr[2] = &ft_setenv;
  build_ptr[3] = &ft_unsetenv;
  build_ptr[4] = &ft_exit;
  while (build[j] && my_strcmp(build[j], shell->cmd[0]) == -1)
    j++;
  if (build[j] == NULL)
    return (-1);
  else
    (*build_ptr[j])(shell);
  return (0);
}
void	ft_rewrite(char **instr,
		   int i,
		   int old_fd)
{
  int	fd;
  char	buf[512];
  int	oct;
  instr[i] = ft_epur_str(instr[i]);
  if ((fd = open(my_strdup(instr[i]), O_CREAT | O_RDWR, S_IRWXU)) == -1)
    exit(EXIT_FAILURE);
  while ((oct = read(old_fd, buf, sizeof(buf))) != 0)
    write(fd, buf, oct);
  close(fd);
}

void	ft_write_at_end(char **instr,
			int i,
			int old_fd)
{
  int	fd;
  char	buf[512];
  int	oct;

  instr[i] = ft_epur_str(instr[i]);
  if ((fd = open(my_strdup(instr[i]), O_CREAT | O_APPEND | O_RDWR, S_IRWXU)) == -1)
    exit(EXIT_FAILURE);
  while ((oct = read(old_fd, buf, sizeof(buf))) != 0)
    write(fd, buf, oct);
  close(fd);
}

void	ft_exec_or_redirect(t_shell *shell,
			    char **instr,
			    int i,
			    int old_fd)
{
  if (execve(shell->cmd[0], shell->cmd, shell->env) == -1)
    {
      if (i != 0 && my_strcmp(instr[i - 1], ">") == 1)
	ft_rewrite(instr, i, old_fd);
      else if (i != 0 && my_strcmp(instr[i - 1], ">>") == 1)
	ft_write_at_end(instr, i, old_fd);
      else if (i != 0 && instr[i] != NULL && my_strcmp(instr[i + 1], "<") == 1)
	{
	}
      else if (i != 0 && instr[i] != NULL
	       && my_strcmp(instr[i + 1], "<<") == 1)
	{
	}
      else
	{
	  my_putstr(shell->cmd[0]);
	  my_putstr(" No such file or directory\n");
	}
    }
}

int	ft_exec_pipe(t_shell *shell, int old_fd, int i, char **instr)
{
  int	pipefd[2];
  int	status;
  int	pid;

  signal(SIGSEGV, segfault);
  if ((pipe(pipefd) == -1) || ((pid = fork()) == -1))
    exit(EXIT_FAILURE);
  if (pid == 0)
    {
      dup2(old_fd, 0);
      if (instr[i + 1] != NULL)
	dup2(pipefd[1], 1);
      close(pipefd[0]);
      ft_exec_or_redirect(shell, instr, i, old_fd);
      exit(EXIT_FAILURE);
    }
  else
    {
      waitpid(pid, &status, WUNTRACED);
      close(pipefd[1]);
      old_fd = pipefd[0];
    }
  return (old_fd);
}
