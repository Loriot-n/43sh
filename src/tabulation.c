/*
** tabulation.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "shell.h"

char	*get_autoc_path(t_shell *shell, char *beg)
{
  char	*tmp;
  char	**tab;

  tab = split(beg, " ");
  if (!tab[1] || !tab[1][0])
    tmp = get_env(g_shell, "PATH");
  else
    tmp = strdup(".");
  if (!tmp)
    return (strdup("/bin"));
  printf("tmp:%s\n", tmp);
  return (strdup(tmp));
}

char	*get_beg(char *line)
{
  char	**tmp;
  char	*one;

  tmp = split(line, " ");
  if (!tmp[1])
    {
      ft_free_tab(tmp);
      return (line);
    }
  one = strdup(tmp[tab_len(tmp) - 1]);
  ft_free_tab(tmp);
  return (one);
}
