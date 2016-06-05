/*
** check_input.c for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Thu May 19 10:38:57 2016 CUENAT
** Last update Sun Jun  5 16:39:53 2016 CUENAT
*/

#include "shell.h"

int	ft_check_input_in_loop(char ** tab, int i, int check, char *bad_tkn)
{
  if ((check = is_const_string(tab[i], check) == 1) &&
      (ft_look_bad_tkn(tab[i], bad_tkn) == -1 || ft_look_and(tab, i) == -1
       || ft_look_or(tab, i) == -1 || ft_look_dot(tab, i) == -1))
    {
      dprintf(2, "Unmatched %s\n", tab[i]);
      return (1);
    }
  if (ft_check_redirect(tab, i) == -1)
    {
      dprintf(2, "Ambiguous output redirect.\n");
      return (1);
    }
  if (ft_check_input_redirect(tab, i) == -1)
    {
      dprintf(2, "Ambiguous input redirect.\n");
      return (1);
    }
  return (0);
}
