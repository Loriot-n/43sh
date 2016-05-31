/*
** globing.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "shell.h"

char		*replace_glob(char *line)
{
  int		i;
  int		ret;
  char		**tmp;
  glob_t	*results;
  int		glob_flags;

  tmp = split(line, " ");
  i = 0;
  glob_flags = 0;
  if (!(results = malloc(sizeof(glob_t) * 1)))
    exit(EXIT_FAILURE);
  if (!tmp[i])
    results = NULL;
  while (tmp[i])
    {
      (i > 1) ? glob_flags |= (GLOB_APPEND | GLOB_NOCHECK) : 0;
      if ((ret = glob(tmp[i], glob_flags, NULL, results)) == 0)
	tmp[i] = epur(tab_join(' ', results->gl_pathv));
      i++;
    }
  globfree(results);
  return (tab_join(' ', tmp));
}
