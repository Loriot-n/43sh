/*
** raw_history_serial.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Tue May 31 23:08:06 2016 Nicolas Loriot
** Last update Sun Jun 05 15:09:23 2016 Nicolas Loriot
*/

#include "arrows.h"
#include "shell.h"

char		*hist_to_serial(t_raw *raw)
{
  char		*ret;
  int		i;
  int		len;
  int		itemlen;

  ret = NULL;
  i = len = itemlen = 0;
  while (i < raw->history->len)
    {
      itemlen = strlen(raw->history->tab[i]) + 1;
      ret = raw_realloc(raw->history->tab[i], itemlen);
      strncpy(ret + len, raw->history->tab[i], itemlen);
      len += itemlen;
      ret[len - 1] = '\n';
    }
  if (!ret)
    return (NULL);
  ret[len - 1] = 0;
  return (ret);
}

int		get_hist_max_file(t_raw *raw)
{
  int		fd;
  int		id;

  fd = open("./42sh_history", O_RDWR);
  id = get_hist_elem_id(fd);
  close(fd);
  return (id);
}
