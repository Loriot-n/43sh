/*
** raw_memfunc.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Tue May 31 19:52:48 2016 Nicolas Loriot
** Last update Fri Jun 03 12:49:05 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

void		raw_memmove(char **dest, char **src, size_t size)
{
  char		**tmp;
  int		i;
  int		j;

  i = 0;
  tmp = NULL;
  while (src[i])
    {
      tmp = add_string(tmp, src[i]);
      i++;
    }
  i = 0;
  while (tmp)
    {
      dest = add_string(tmp, dest[i]);
      i++;
    }
  free(tmp);
}

void		*raw_alloc(size_t size)
{
  void		*ret;

  if (!(ret = malloc(size)))
    exit(EXIT_FAILURE);
  return (ret);
}

void		*raw_realloc(void *oldptr, size_t size)
{
  void		*ret;

  if (!(ret = realloc(oldptr, size)))
    exit(EXIT_FAILURE);
  return (ret);
}

void		*raw_calloc(size_t nmemb, size_t size)
{
  void		*ret;

  if (!(ret = calloc(nmemb, size)))
    exit(EXIT_FAILURE);
  return (ret);
}

