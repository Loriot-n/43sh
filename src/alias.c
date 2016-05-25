/*
** alias.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/Bonus/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
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
      printf("%s=: bad assignment\n", lexed[1]);
      return (-1);
    }
  if (!lexed[1] || strcmp(lexed[2], "=") != 0 ||
      ((*lexed[3] + *lexed[tab_len(lexed) - 1]) != 2 * '\'' &&
       (*lexed[3] + *lexed[tab_len(lexed) - 1]) != 2 * '"'))
    {
      printf("Bad assignment\n");
      return (-1);
    }
  return (1);
}

t_alias		*get_aliases(int fd)
{
  char		*one;
  char		**lexed;
  char		*tmp;
  t_alias	*list_alias;

  list_alias = NULL;
  while ((one = get_next_line(fd)))
    {
      tmp = epur(one);
      lexed = split(tmp, " =\"'");
      if (strcmp(lexed[0], "alias") == 0 && check_alias(lexed) == 1)
	insert_alias(&lexed[4], lexed[1], &list_alias);
      empty(tmp, one, lexed);
    }
  return (list_alias);
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
