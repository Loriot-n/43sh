/*
** my_str_to_wordtab.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "shell.h"

static inline int	is_separator(char *tokens, char c)
{
  while (*tokens)
    {
      if (*tokens == c)
	return (1);
      tokens++;
    }
  return (0);
}

size_t		tab_len(char **tab)
{
  size_t	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

char	**split(char *str, char *tokens)
{
  char	**tab;
  int	i;
  int	j;
  int	save;

  j = -1;
  i = 0;
  ((tab = malloc(sizeof(char *) * 1)) == NULL) ? exit(EXIT_FAILURE) : 0;
  (str) ? save = is_separator(tokens, *str) + 1 : 0;
  tab[0] = NULL;
  while (str && str[i])
    {
      if (is_separator(tokens, str[i]) != save || (save == 1 && tab[j][0] &&
		       str[i] != tab[j][0]))
	{
	  (j != -1 && !tab[j][0]) ? free(tab[j--]) : 0;
	  (!(tab = realloc(tab, sizeof(char *) * (tab_len(tab) + 2))) ||
	   !(tab[++j] = malloc(sizeof(char) * 1))) ? exit(EXIT_FAILURE) : 0;
	  tab[j][0] = 0;
	  save = is_separator(tokens, str[i]);
	  tab[j + 1] = NULL;
	}
      (str[i++] > 32) ? tab[j] = add_char(tab[j], str[i - 1]) : 0;
    }
  return (tab);
}
