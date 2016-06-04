/*
** alias.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/Bonus/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Sat Jun  4 16:07:16 2016 Sanchez Loris
*/

#include "shell.h"

void	empty(char *tmp, char *one, char **lexed)
{
  ft_free_tab(lexed);
  free(tmp);
  free(one);
}

int	check_alias(char **lexed)
{
  if (tab_len(lexed) < 2)
    {
      printf("%s=: Bad assignment\n", lexed[1]);
      return (-1);
    }
  return (1);
}

char	*replace_alias(t_alias *alias_list, char *cmd)
{
  char	**tmp;
  char	*one;

  if (!cmd || !cmd[0])
    return (cmd);
  tmp = split(cmd, " ;&|><");
  while (alias_list)
    {
      if (strcmp(alias_list->alias, tmp[0]) == 0)
	{
	  one = strdup(alias_list->cmd);
	  if (!(one = realloc(one, strlen(cmd) + strlen(alias_list->cmd) + 2)))
	    exit(EXIT_FAILURE);
	  one = strcat(one, &cmd[strlen(alias_list->alias)]);
	  one = epur(one);
	  free(cmd);
	  ft_free_tab(tmp);
	  return (one);
	}
      alias_list = alias_list->next;
    }
  ft_free_tab(tmp);
  return (cmd);
}
