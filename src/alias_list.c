/*
** alias_list.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "shell.h"

t_alias		*new_alias(char **cmd, char *alias)
{
  t_alias	*elem;
  char		*new_cmd;
  int		len;
  int		i;

  if (!(elem = malloc(sizeof(t_alias))))
    exit(EXIT_FAILURE);
  len = 0;
  if (!(new_cmd = calloc(1, 1)))
    exit(EXIT_FAILURE);
  cmd[tab_len(cmd) - 1] = NULL;
  i = 0;
  while (cmd[i])
    {
      len += strlen(cmd[i]);
      if (!(new_cmd = realloc(new_cmd, len + 2)))
	exit(EXIT_FAILURE);
      new_cmd = strcat(new_cmd, cmd[i]);
      new_cmd = add_char(new_cmd, ' ');
      i++;
    }
  elem->cmd = epur(new_cmd);
  free(new_cmd);
  elem->alias = strdup(alias);
  elem->next = NULL;
  return (elem);
}

t_alias			*insert_alias(char **cmd, char *alias, t_alias **head,
				      int whatdo)
{
  t_alias		*newnode;
  t_alias		*tmp;

  tmp = *head;
  newnode = new_alias(cmd, alias);
  newnode->whatdo = whatdo;
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
