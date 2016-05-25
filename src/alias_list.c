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
