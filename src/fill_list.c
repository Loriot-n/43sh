/*
** fill_list.c for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Thu May 19 11:25:16 2016 CUENAT
** Last update Tue May 24 16:47:08 2016 CUENAT
*/

#include "shell.h"

t_sub_list	*ft_add_sub_list_at_end(t_sub_list *list,
					char *tmp_c,
					int *sep,
					t_shell *shell)
{
  t_sub_list	*tmp;
  t_sub_list	*new;

  if ((new = malloc(sizeof(t_sub_list))) == NULL)
    exit(EXIT_FAILURE);
  new->cmd = strdup(epur(tmp_c));
  new->exec_cmd = split(new->cmd, " |");
  new->separator = *sep;
  new->next = NULL;
  if (list == NULL)
    return (new);
  else
    {
      tmp = list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }
  return (list);
}

void	ft_parse_string_sub_list(t_list *tmp, int *sep, t_shell *shell)
{
  int  	i;
  int  	j;
  char 	*tmp_c;

  i = 0;
  while (tmp->cmd[i])
    {
      j = i;
      while (tmp->cmd[i])
	{
	  if ((tmp->cmd[i] == '&' && tmp->cmd[i + 1] == '&')
	      || (tmp->cmd[i] == '|' && tmp->cmd[i + 1] == '|'))
	    break;
	  i += 1;
	}
      if (j != i)
	{
	  if ((tmp_c = malloc(sizeof(char) * (i - j + 1))) == NULL)
	      exit(EXIT_FAILURE);
	  strncpy(tmp_c, &tmp->cmd[j], (i - j));
	  tmp_c[i - j] = '\0';
	  tmp->sub_list = ft_add_sub_list_at_end(tmp->sub_list, tmp_c, sep,
						 shell);
	  *sep = NO;
	  (tmp->cmd[i] != '\0' && tmp->cmd[i + 1] == '&') ? (*sep = AND) : 0;
	  (tmp->cmd[i] != '\0' && tmp->cmd[i + 1] == '|') ? (*sep = OR) : 0;
	}
      (tmp->cmd[i] != '\0') ? (i += 2) : (i);
    }
}

int		ft_create_sub_list(t_shell *shell)
{
  t_list	*tmp;
  int		separator;

  tmp = shell->exec_list;
  while (tmp != NULL)
    {
      separator = NO;
      ft_parse_string_sub_list(tmp, &separator, shell);
      tmp = tmp->next;
    }
  return (0);
}

t_list		*ft_add_at_end(t_list *exec_list, char *val)
{
  t_list	*new;
  t_list	*tmp;

  if ((new = malloc(sizeof(t_list))) == NULL)
    exit(EXIT_FAILURE);
  new->cmd = strdup(epur(val));
  new->sub_list = NULL;
  new->next = NULL;
  if (exec_list == NULL)
    return (new);
  else
    {
      tmp = exec_list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }
  return (exec_list);
}

int	ft_create_list(t_shell *shell, char *line)
{
  int	i;
  int	j;
  char	*tmp;

  i = 0;
  while (line[i])
    {
      j = i;
      while (line[i] && line[i] != ';')
	i += 1;
      if ((tmp = malloc(sizeof(char) * (i - j + 1))) == NULL)
	exit(EXIT_FAILURE);
      strncpy(tmp, &line[j], (i - j));
      tmp[i - j] = '\0';
      if (tmp != NULL || tmp[0] != '\0')
	shell->exec_list = ft_add_at_end(shell->exec_list, tmp);
      i = (line[i]) ? i + 1 : i;
      free(tmp);
    }
  return (0);
}
