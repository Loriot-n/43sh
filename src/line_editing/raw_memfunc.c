/*
** raw_memfunc.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Tue May 31 19:52:48 2016 Nicolas Loriot
** Last update Fri Jun 03 17:31:29 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

void		raw_memmove(void *dest, void *src, size_t size)
{
  void		*tmp;
  tmp = raw_alloc(size);
  memcpy(tmp, src, size);
  memcpy(dest, tmp, size);
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

