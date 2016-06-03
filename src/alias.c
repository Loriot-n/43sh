/*
** alias.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/Bonus/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Fri Jun  3 11:47:05 2016 Sanchez Loris
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
  if (tab_len(lexed) < 6)
    {
      printf("%s=: Bad assignment\n", lexed[1]);
      return (-1);
    }
  if (strcmp(lexed[1], "=") != 0 ||
      ((*lexed[2] + *lexed[tab_len(lexed) - 1]) != 2 * '\'' &&
       (*lexed[2] + *lexed[tab_len(lexed) - 1]) != 2 * '"'))
    {
      printf("Bad assignment\n");
      return (-1);
    }
  return (1);
}

t_alias		*get_aliases(t_shell *shell, char **tab)
{
  int		i;
  char		**lexed;

  i = 0;
  while (tab[i])
    {
      lexed = split(tab[i], " =\"'");
      if (strcmp(lexed[0], "alias") == 0 && check_alias(lexed) == 1)
	insert_alias(&lexed[4], lexed[1], &(shell->alias), 0);
      ft_free_tab(lexed);
      i++;
    }
  return (shell->alias);
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
