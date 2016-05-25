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

t_alias			*new_alias(char *cmd, char *alias)
{
  t_alias		*elem;

  if (!(elem = malloc(sizeof(t_alias))))
    exit(EXIT_FAILURE);
  elem->cmd = cmd;
  elem->alias = alias;
  elem->next = NULL;
  return (elem);
}

t_alias			*insert_alias(char *cmd, char *alias, t_alias **head)
{
  t_alias		*newnode;
  t_alias		*tmp;

  tmp = *head;
  newnode = new_alias(cmd, alias);
  if (!(*head))
    {
      *head = newnode;
      return (*head);
    }
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = newnode;
  return (newnode);
}

void	empty(char *tmp, char *one, char **lexed)
{
  int	i;

  i = 0;
  while (lexed[i])
    free(lexed[i++]);
  free(lexed);
  free(tmp);
  free(one);
}

int	check_alias(char **lexed)
{
  int	right;

  right = -1;
  if (!lexed[1])
    {
      printf("Bad assignment\n");
      return (-1);
    }
  if (tab_len(lexed) != 6 && !(right += 1))
    {
      printf("%s=: bad assignment\n", lexed[1]);
      return (-1);
    }
  return (1);
}

t_alias		*get_aliases(char *path)
{
  char		*one;
  int		fd;
  char		**lexed;
  char		*tmp;
  t_alias	*list_alias;

  if (access(path, F_OK | R_OK) != 0 || (fd = open(path, O_RDONLY)) < 0)
    {
      printf("Error while opening %s: %s\n", path, strerror(errno));
      return (NULL);
    }
  list_alias = NULL;
  while ((one = get_next_line(fd)))
    {
      tmp = epur(one);
      lexed = split(tmp, " =\"'");
      if (strcmp(lexed[0], "alias") == 0 && check_alias(lexed) == 1)
	insert_alias(strdup(lexed[1]), strdup(lexed[4]), &list_alias);
      empty(tmp, one, lexed);
    }
  return (list_alias);
}

char	*replace_alias(t_alias *alias_list, char *cmd)
{
  while (alias_list)
    {
      if (strcmp(alias_list->cmd, cmd) == 0)
	return (strdup(alias_list->alias));
      alias_list = alias_list->next;
    }
  return (cmd);
}
