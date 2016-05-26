/*
** free_struct.c for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Thu May 19 16:30:52 2016 CUENAT
** Last update Thu May 26 14:06:15 2016 CUENAT
*/

#include "shell.h"

void		free_alias(t_alias *alias)
{
  t_alias	*tmp;

  while (alias)
    {
      tmp = alias;
      free(alias->cmd);
      free(alias->alias);
      alias = alias->next;
      free(tmp);
    }
}

void	ft_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab != NULL && tab[i])
    {
      free(tab[i]);
      i += 1;
    }
  free(tab);
}

void	ft_free_struct(t_shell *shell)
{
  t_list	*tmp;
  t_sub_list	*tmp_sub;

  while (shell->exec_list != NULL)
    {
      while (shell->exec_list->sub_list != NULL)
	{
	  tmp_sub = shell->exec_list->sub_list;
	  shell->exec_list->sub_list = shell->exec_list->sub_list->next;
	  free(tmp_sub->cmd);
	  ft_free_tab(tmp_sub->exec_cmd);
	  free(tmp_sub);
	}
      tmp = shell->exec_list;
      shell->exec_list = shell->exec_list->next;
      free(tmp);
    }
}
