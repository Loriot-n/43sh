/*
** raw_history_serial.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Tue May 31 23:08:06 2016 Nicolas Loriot
** Last update Sat Jun 04 18:36:40 2016 Nicolas Loriot
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

int		hist_from_file(t_raw *raw)
{
  int		max;
  int		fd;
  char		*str;

  max = get_hist_max_file(raw);
  raw->history = new_hist(max);
  if ((fd = open(".42sh_history", O_RDWR)))
    printf("42sh_history : %s", strerror(errno));
  while ((str = get_next_line(fd)))
    {
      raw->history->len++;
      hist_add_str(raw, str);
    }
  close(fd);
  return (0);
}
