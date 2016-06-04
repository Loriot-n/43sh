/*
** check_input.c for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Thu May 19 10:38:57 2016 CUENAT
** Last update Sat Jun  4 16:03:02 2016 CUENAT
*/

#include "shell.h"

int	ft_look_dot(char **tab, int i)
{
  if (tab[i][0] ==  ';')
    {
      if (i == 0)
	return (-1);
      if (strchr(tab[i - 1], '&') != NULL
	       || strchr(tab[i - 1], '|') != NULL)
	return (-1);
    }
  return (0);
}

int	ft_look_and(char **tab, int i)
{
  if (tab[i][0] ==  '&')
    {
      if (tab[i + 1] == NULL && tab_len(tab) > 1)
	return (-1);
      else if (i != 0 && (strchr(tab[i - 1], '&') != NULL
	       || strchr(tab[i - 1], '|') != NULL
			  || strchr(tab[i - 1], ';') != NULL))
	return (-1);
    }
  return (0);
}

int	ft_look_or(char **tab, int i)
{
  if (tab[i][0] ==  '|')
    {
      if (strlen(tab[i]) > 2 || i == 0 || tab[i + 1] == NULL)
	return (-1);
      else if (strchr(tab[i - 1], '&') != NULL
	       || strchr(tab[i - 1], '|') != NULL
	       || strchr(tab[i - 1], ';') != NULL)
	return (-1);
    }
  return (0);
}

int	ft_look_bad_tkn(char *word, char *tkn)
{
  int	i;
  int	j;

  i = 0;
  while (word[i])
    {
      j = 0;
      while (tkn[j])
	{
	  if (word[i] == tkn[j])
	    return (-1);
	  j += 1;
	}
      i += 1;
    }
  return (0);
}

int	ft_check_input(char *line)
{
  char	*tkn;
  char	*bad_tkn;
  char	**tab;
  int	i;
  int	check;

  i = 0;
  tkn = "|&; ><";
  bad_tkn = "{}^!,";
  tab = split(line, tkn);
  check = 1;
  while (tab && tab[i])
    {
      if ((check = is_const_string(tab[i], check)) == 1 &&
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
      i += 1;
    }
  ft_free_tab(tab);
  return (0);
}
