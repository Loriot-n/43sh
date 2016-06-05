/*
** globing.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
** yan typedef glob_t
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "shell.h"

int	to_glob(char *line)
{
  int	i;

  i = 0;
  if (line[0] == '"' || line[strlen(line) - 1] == '"')
    return (0);
  while (line[i])
    {
      if (line[i] == '*')
	return (1);
      i++;
    }
  return (0);
}

char		*replace_glob(char *line)
{
  int		i;
  int		ret;
  char		**tmp;
  glob_t	*results;
  int		glob_flags;

  tmp = split(line, " ");
  i = 0;
  glob_flags = GLOB_NOCHECK | GLOB_ERR | GLOB_TILDE;
  results = NULL;
  if (!(results = malloc(sizeof(glob_t) * 1)))
    exit(EXIT_FAILURE);
  while (tmp[i])
    {
      if (to_glob(tmp[i]) == 1 &&
	  (ret = glob(tmp[i], glob_flags, NULL, results)) == 0)
	{
	  tmp[i] = epur(tab_join(' ', results->gl_pathv));
	  globfree(results);
	}
      i++;
    }
  return (epur(tab_join(' ', tmp)));
}
