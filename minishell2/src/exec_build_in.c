/*
** build_function.c for  in /home/cuenat_s/rendu/PSU_2015/PSU_2015_minishell1
**
** Made by stanislas cuenat
** Login   <cuenat_s@epitech.net>
**
** Started on  Wed Jan 13 15:23:36 2016 stanislas cuenat
** Last update Fri Apr  8 13:08:27 2016 CUENAT
*/

#include "include.h"

void	ft_env(t_shell *shell)
{
  int	j;

  j = 0;
  while (shell->env[j])
    {
      my_putstr(shell->env[j]);
      j++;
    }
}

void	ft_setenv(t_shell *shell)
{
  int	i;

  i = 0;
  while (shell->env[i] && ft_find_in_env(shell->env[i], shell->cmd[1]) == -1)
    i++;
  if (shell->env[i] == NULL)
    shell->env = ft_add_on_env(shell);
  else
    {
      free(shell->env[i]);
      if (shell->cmd[2] != NULL)
	shell->env[i] = ft_strcat(shell->cmd[1], shell->cmd[2]);
      else
	shell->env[i] = my_strdup(shell->cmd[1]);
    }
}

void	ft_unsetenv(t_shell *shell)
{
  int	j;

  j = 0;
  if (shell->cmd[1] != NULL)
    {
      while (shell->env[j] && ft_find_in_env(shell->env[j], shell->cmd[1]) == -1)
	j++;
      if (shell->env[j] != NULL)
	{
	  shell->env[j][0] = '\0';
	}
    }
}

void	ft_exit(t_shell *shell)
{
  int	k;
  int	j;
  char	*nb;

  k = 0;
  j = 0;
  if (shell->cmd[1] != NULL)
    {
      if ((nb = malloc(sizeof(char) * (my_strlen(shell->cmd[1]) + 1))) == NULL)
	exit(EXIT_FAILURE);
      while (shell->cmd[1][k] && shell->cmd[1][k] >= '0'
	     && shell->cmd[1][k] <= '9')
	nb[j++] = shell->cmd[1][k++];
      nb[j] = '\0';
      my_putstr("exit\n");
      exit(my_getnbr(nb));
    }
  else
    exit(0);
}
