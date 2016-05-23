/*
** get_next_line.c for  in /home/cuenat_s/rendu/CPE_2015/line
**
** Made by stanislas cuenat
** Login   <cuenat_s@epitech.net>
**
** Started on  Thu Jan 14 17:57:16 2016 stanislas cuenat
** Last update Tue Mar  1 15:56:45 2016 CUENAT
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int	mlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*cpy(char *tmp, char *ret)
{
  int	i;

  i = 0;
  if ((tmp = malloc(mlen(ret) + 1)) == NULL)
    return (NULL);
  while (ret[i])
    {
      tmp[i] = ret[i];
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
}

char	*my_realloc(char *ret, int oct)
{
  char	*tmp;
  int	i;

  i = 0;
  if ((tmp = malloc(mlen(ret) + oct + 2)) == NULL)
    return (NULL);
  while (ret[i])
    {
      tmp[i] = ret[i];
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
}

char		*get_next_line(const int fd)
{
  static char	buf[READ_SIZE];
  static char	*ret = "\0";
  static int	cpt_r = 0;
  static int   	oct = 0;
  static int   	i = 0;
  static char  	*tmp;

  if (cpt_r == oct)
    {
      if ((oct = read(fd, buf, READ_SIZE)) <= 0 ||
	  ((ret = my_realloc(ret, oct)) == NULL))
	return (NULL);
      cpt_r = 0;
    }
  if (buf[cpt_r] == '\n' || buf[cpt_r] == '\0')
    {
      i = 0;
      cpt_r++;
      tmp = cpy(tmp, ret);
      ret[0] = '\0';
      return (tmp);
    }
  ret[i++] = buf[cpt_r++];
  ret[i] = '\0';
  return (get_next_line(fd));
}
