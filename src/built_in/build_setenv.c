/*
** build_setenv.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Sun Jun  5 16:29:33 2016 CUENAT
*/

#include "shell.h"

void	modify_env(t_shell *shell, char **cmd, int pos)
{
  char	*new;

  new = strdup(cmd[1]);
  new = join(2, '=', cmd[1], cmd[2]);
  free(shell->env[pos]);
  shell->env[pos] = new;
}

void	add_env(t_shell *shell, char **cmd)
{
  char	*new;
  int	len;

  len = tab_len(shell->env);
  if (!(shell->env = realloc(shell->env, sizeof(char *) * (len + 2))))
    exit(EXIT_FAILURE);
  new = join(2, '=', cmd[1], cmd[2]);
  shell->env[len] = new;
  shell->env[len + 1] = NULL;
}

int	is_alphanum(char *str)
{
  int	i;

  i = 0;
  if ((str[0] < 'a' || str[0] > 'z') && (str[0] < 'A' || str[0] > 'Z'))
    {
      dprintf(2, "setenv: Variable name must begin with a letter.\n");
      return (-1);
    }
  while (str[i])
    {
      if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') &&
	  (str[i] < '0' || str[i] > '9') && str[i] != '_')
	{
	  dprintf(2, "setenv: Variable name must contain");
	  dprintf(2, " alphanumeric characters.\n");
	  return (-1);
	}
      i++;
    }
  return (1);
}

int	st_check(t_shell *shell, char **cur_exec)
{
  if (tab_len(cur_exec) > 3)
    {
      dprintf(2, "setenv: Too many arguments.\n");
      return (-1);
    }
  if (!cur_exec[1])
    {
      ft_env(shell);
      return (-1);
    }
  if (is_alphanum(cur_exec[1]) == -1)
    return (-1);
  return (1);
}

int 	ft_setenv(t_shell *shell)
{
  int	i;

  if (st_check(shell, shell->cur_exec) == -1)
    return (-1);
  i = 0;
  while (shell->env[i] && (strncmp(shell->env[i], shell->cur_exec[1],
				  strlen(shell->cur_exec[1])) != 0 ||
	 shell->env[i][strlen(shell->cur_exec[1])] != '='))
    i++;
  if (!shell->env[i])
    add_env(shell, shell->cur_exec);
  else
    modify_env(shell, shell->cur_exec, i);
  return (0);
}
