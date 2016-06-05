/*
** build_alias.c for  in /home/sanche_k/rendu/42sh/PSU_2015_42sh/src
** 
** Made by Sanchez Loris
** Login   <sanche_k@epitech.net>
** 
** Started on  Fri Jun  3 09:40:49 2016 Sanchez Loris
** Last update Sun Jun  5 16:13:27 2016 Sanchez Loris
** Last update Sat Jun 04 19:14:22 2016 Nicolas Loriot
*/

#include "shell.h"

void		print_alias(t_alias *alias)
{
  t_alias	*tmp;

  tmp = alias;
  while (tmp)
    {
      printf("%s %s\n", tmp->alias, tmp->cmd);
      tmp = tmp->next;
    }
}

void		show_this_alias(char *search, t_alias *alias)
{
  t_alias	*tmp;

  tmp = alias;
  while (tmp)
    {
      if (strcmp(search, tmp->alias) == 0)
	printf("%s\n", tmp->cmd);
      tmp = tmp->next;
    }
}

int		ft_alias(t_shell *shell)
{
  char		**tab;
  char		*str;

  if (strcmp(shell->exec_list->cmd, "alias") == 0)
    {
      print_alias(shell->alias);
      return (0);
    }
  tab = split(strdup(&(shell->exec_list->cmd[6])), " ");
  if (tab[1] == NULL)
    show_this_alias(tab[0], shell->alias);
  str = epur(tab_join(' ', &tab[1]));
  if (tab[1])
    insert_alias(tab[0], str, &shell->alias, 0);
  return (0);
}

void		ft_norme_unalias(t_alias *tmp, char **tab)
{
  if (strcmp(tab[1], tmp->next->alias) == 0)
    {
      free(tmp->next->cmd);
      free(tmp->next->alias);
      tmp->next = tmp->next->next;
    }
  else
    tmp = tmp->next;  
}

int		ft_unalias(t_shell *shell)
{
  t_alias	*tmp;
  char		**tab;

  tmp = shell->alias;
  tab = split(strdup(&(shell->exec_list->cmd[6])), " ");
  if (tab == NULL || shell->alias == NULL)
    return (0);
  if (tab[1] == NULL || !strcmp(tab[1], "unalias"))
    {
      printf("unalias: Too few arguments.\n");
      return (1);
    }
  if (tab[1] && tmp->alias && strcmp(tab[1], tmp->alias) == 0)
    {
      free(tmp->cmd);
      free(tmp->alias);
      shell->alias = shell->alias->next;
      return (0);
    }
  while (tmp->next)
    ft_norme_unalias(tmp, tab);
  return (0);
}
