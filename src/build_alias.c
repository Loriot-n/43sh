/*
** build_alias.c for  in /home/sanche_k/rendu/42sh/PSU_2015_42sh/src
** 
** Made by Sanchez Loris
** Login   <sanche_k@epitech.net>
** 
** Started on  Fri Jun  3 09:40:49 2016 Sanchez Loris
** Last update Fri Jun  3 12:16:09 2016 Sanchez Loris
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

int		ft_alias(t_shell *shell)
{
  char		**tab;
  char		*str;

 
  if (strcmp(shell->exec_list->cmd, "alias") == 0)
    {
      print_alias(shell->alias);
      return (0);
    }
  tab = split(strdup(&(shell->exec_list->cmd[6])), "\" =");
  if (check_alias(tab) == -1)
    return (-1);  
  tab[tab_len(tab) - 1] = NULL; 
  str = epur(tab_join(' ', &tab[3]));
  insert_alias(tab[0], str, &shell->alias, 0);
  return (0);
}
