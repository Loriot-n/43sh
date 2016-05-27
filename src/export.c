/*
** export.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "shell.h"

char	**add_export(t_shell *shell, int fd)
{
  char	*one;
  char	**tab;
  char	*tmp[4];
  int	i;

  while ((one = get_next_line(fd)))
    {
      tab = split(one, " ='\"");
      if (tab[0] && strcmp(tab[0], "export") == 0 && tab_len(tab) == 6)
	{
	  tmp[0] = "";
	  tmp[1] = tab[1];
	  tmp[2] = tab[4];
	  tmp[3] = NULL;
	  printf("ok %s %s\n", tab[1], tab[4]);
	  if (st_check(shell, tmp) == -1)
	    continue ;
	  i = 0;
	  while (shell->env[i] && (strncmp(shell->env[i], tab[1],
		strlen(tab[1])) != 0 || shell->env[i][strlen(tab[1])] != '='))
	    i++;
	  if (shell->env[i])
	    modify_env(shell, tmp, i);
	  else
	    add_env(shell, tmp);
	}
    }
  return (shell->env);
}
