/*
** raw_memfunc.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Tue May 31 19:52:48 2016 Nicolas Loriot
** Last update Wed Jun 01 12:17:19 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

void		raw_memmove(void *src, void *dest, size_t size)
{
  char		*tmp;
  char		*csrc;
  char		*cdest;
  int		i;

  i = 0;
  csrc = (char *)src;
  cdest = (char *)dest;
  tmp = raw_alloc(size);
  while (csrc[i])
    {
      tmp[i] = csrc[i];
      i++;
    }
  i = 0;
  while (tmp[i])
    {
      cdest[i] = tmp[i];
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

