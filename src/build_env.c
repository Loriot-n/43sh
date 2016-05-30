/*
** build_env.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "shell.h"

void	ft_env(t_shell *shell)
{
  int	i;

  i = 0;
  while (shell->env && shell->env[i])
    printf("%s\n", shell->env[i++]);
  return ;
}
