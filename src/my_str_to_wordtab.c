/*
** my_str_to_wordtab.c for str to word tab in /home/loriot_n/rendu/Piscine_C_J08/ex_04
**
** Made by nicolas loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Fri Oct  9 11:43:20 2015 nicolas loriot
** Last update Wed May 18 17:48:14 2016 CUENAT
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
