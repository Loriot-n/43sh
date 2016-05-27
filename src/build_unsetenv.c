/*
** build_unsetenv.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "shell.h"

void	delete_env(t_shell *shell)
{
  if (!(shell->env = realloc(shell->env, sizeof(char *) * 1)))
    exit(EXIT_FAILURE);
  shell->env[0] = NULL;
  return ;
}

static int	check(t_shell *shell)
{
  if (!shell->cur_exec[1])
    {
      dprintf(2, "unsetenv: Too few arguments.\n");
      return (-1);
    }
  if (strcmp(shell->cur_exec[1], "*") == 0)
    {
      delete_env(shell);
      return (-1);
    }
  return (1);
}

void	ft_unsetenv(t_shell *shell)
{
  int	i;
  int	j;

  if ((i = 1) && check(shell) == -1)
    return ;
  while (shell->cur_exec[i])
    {
      j = 0;
      while (shell->env[j] && (strncmp(shell->env[j], shell->cur_exec[i],
		strlen(shell->cur_exec[i])) != 0 ||
		shell->env[j][strlen(shell->cur_exec[i])] != '='))
	j++;
      if (shell->env[j] != NULL)
	{
	  free(shell->env[j]);
	  while (j == 0 || shell->env[j - 1])
	    {
	      shell->env[j] = shell->env[j + 1];
	      j++;
	    }
	}
      i++;
    }
}
