/*
** alias_list.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Sun Jun  5 17:01:11 2016 Sanchez Loris
*/

#include "shell.h"

t_alias		*new_alias(char *replace, char *replace_by)
{
  t_alias	*elem;

  if ((elem = malloc(sizeof(t_alias))) == NULL)
    exit(EXIT_FAILURE);
  elem->alias = strdup(replace);
  elem->cmd = strdup(replace_by);
  elem->next = NULL;
  return (elem);
}

t_alias			*insert_alias(char *replace, char *replace_by, t_alias **head,
				      int whatdo)
{
  t_alias		*newnode;
  t_alias		*tmp;

  tmp = *head;
  newnode = new_alias(replace, replace_by);
  newnode->whatdo = whatdo;
  if (!(*head))
    {
      *head = newnode;
      return (*head);
    }
  while (tmp->next != NULL && strcmp(tmp->alias, replace))
    tmp = tmp->next;
  if (tmp->next)
    {
      tmp->cmd = replace_by;
      return (tmp);
    }
  tmp->next = newnode;
  return (newnode);
}
