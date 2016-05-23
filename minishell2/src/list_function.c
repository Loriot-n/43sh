/*
** list_function.c for  in /home/stanislas/PSU_2015_minishell2/src
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 29 16:58:39 2016 CUENAT
** Last update Wed Mar 30 13:07:11 2016 CUENAT
*/

#include "include.h"

t_list		*ft_free_list(t_list *list)
{
  t_list	*tmp;

  if (list == NULL)
    return (NULL);
  else
    {
      tmp = list->next;
      free(list->binary);
      free(list);
      tmp = ft_free_list(tmp);
      return (tmp);
    }

}

t_list	*ft_add_at_end_list(char *str_tmp, t_list *list)
{
  t_list	*new;
  t_list	*tmp;

  if ((new = malloc(sizeof(t_list) * 1)) == NULL)
    exit(EXIT_FAILURE);
  new->binary = my_strdup(str_tmp);
  new->next = NULL;
  if (list == NULL)
    return (new);
  else
    {
      tmp = list;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
      return (list);
    }
}

char	*ft_itoj_strcpy(int i, int j, char *instr)
{
  char	*tmp;
  int	k;

  k = 0;
  if ((tmp = malloc(sizeof(char) * (j - i + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (i != j)
    tmp[k++] = instr[i++];
  tmp[k] = '\0';
  return (tmp);
}

t_list	*ft_parse_instr(t_list *list, char *instr)
{
  char	*tmp;
  char	*epur_instr;
  int	i;
  int	j;

  epur_instr = ft_epur_str(instr);
  i = 0;
  while (epur_instr[i])
    {
      j = i;
      while (epur_instr[i] != ';' && epur_instr[i])
	i++;
      tmp = ft_itoj_strcpy(j, i, epur_instr);
      if (tmp[0] != '\0')
	list = ft_add_at_end_list(tmp, list);
      free(tmp);
      if (epur_instr[i] != '\0')
	i++;
    }
  return (list);
}
