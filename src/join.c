/*
** join.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "shell.h"

char		*join(int nb, char sep, ...)
{
  va_list	ap;
  int		i;
  char		*joined;
  char		*tmp;

  i = 0;
  va_start(ap, sep);
  if (!(joined = calloc(1, 1)))
    exit(EXIT_FAILURE);
  while (i < nb)
    {
      tmp = va_arg(ap, char *);
      if (tmp)
	{
	  if (!(joined = realloc(joined, strlen(joined) + strlen(tmp) + 2)))
	    exit(EXIT_FAILURE);
	  joined = strcat(joined, tmp);
	}
      if (++i != nb && sep)
	joined = add_char(joined, sep);
    }
  va_end(ap);
  return (joined);
}

char	*tab_join(char sep, char **tab)
{
  int	i;
  char	*answer;

  i = 1;
  if (!(answer = calloc(1, 1)))
    exit(EXIT_FAILURE);
  while (tab[i])
    {
      answer = join(2, sep, answer, tab[i]);
      i++;
    }
  return (answer);
}

char **	add_string(char **tab, char *str)
{
  int	len;

  if (tab)
    len = tab_len(tab);
  else
    len = 0;
  if (!(tab = realloc(tab, sizeof(char *) * (len + 2))))
    exit(EXIT_FAILURE);
  tab[len] = strdup(str);
  tab[len + 1] = NULL;
  return (tab);
}
