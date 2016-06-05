/*
** get_next_line.c for gnl in /home/nico/rendu/S01/CPE_2015/getnextline
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Last update Fri Apr 22 12:07:14 2016 Nicolas Loriot
** Started on  Thu Jan  7 11:33:34 2016 Nicolas Loriot
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*my_realloc(char *buf, int ctr)
{
  char	*buf2;
  int	i;

  i = 0;
  if (ctr == 0)
    {
      buf2 = malloc(sizeof(*buf) * (READ_SIZE + 1));
      if (buf2 == NULL)
	return (NULL);
    }
  else
    {
      buf2 = malloc(sizeof(*buf) * (my_strlen(buf) + READ_SIZE + 1));
      if (buf2 == NULL)
	return (NULL);
      while (buf[i] != '\0')
	{
	  buf2[i] = buf[i];
	  i++;
	}
      buf2[i] = 0;
      free(buf);
    }
  return (buf2);
}

char		*go_to_next(char *line, int *i, int *len)
{
  (*i) = 0;
  (*len)--;
  return (line);
}

char		*get_next_line(const int fd)
{
  static char	buf[READ_SIZE];
  static char	*line = NULL;
  static int	beg = 1;
  static int	len = 0;
  static int	ctr = 0;

  if (buf[my_strlen(buf) - len] == 0)
    {
      if ((len = read(fd, buf, READ_SIZE)) <= 0)
	return (line = (beg-- && buf[my_strlen(buf) - len - 1] != '\n') ?
		(line) : (NULL));
      buf[len] = 0;
    }
  if (!(line = my_realloc(line, ctr)))
    return (NULL);
  while (buf[my_strlen(buf) - len] != 0 && buf[my_strlen(buf) - len] != '\n')
    line[ctr++] = buf[my_strlen(buf) - len--];
  line[ctr] = 0;
  if (buf[my_strlen(buf) - len] == '\n')
    return (line = go_to_next(line, &ctr, &len));
  return (get_next_line(fd));
}
