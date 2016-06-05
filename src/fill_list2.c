/*
** fill_list.c for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Thu May 19 11:25:16 2016 CUENAT
** Last update Sun Jun  5 17:00:56 2016 CUENAT
*/

#include "shell.h"

void	ft_parse_string_sub_list_2(t_list *tmp, int i, int j, int *sep)
{
  char	*tmp_c;

  if ((tmp_c = malloc(sizeof(char) * (i - j + 1))) == NULL)
    exit(EXIT_FAILURE);
  strncpy(tmp_c, &tmp->cmd[j], (i - j));
  tmp_c[i - j] = '\0';
  tmp->sub_list = ft_add_sub_list_at_end(tmp->sub_list, tmp_c, sep);
  *sep = NO;
  (tmp->cmd[i] != '\0' && tmp->cmd[i + 1] == '&') ? (*sep = AND) : 0;
  (tmp->cmd[i] != '\0' && tmp->cmd[i + 1] == '|') ? (*sep = OR) : 0;
}
