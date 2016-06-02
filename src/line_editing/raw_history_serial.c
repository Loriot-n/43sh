/*
** raw_history_serial.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Tue May 31 23:08:06 2016 Nicolas Loriot
** Last update Thu Jun 02 12:56:29 2016 Nicolas Loriot
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

int		hist_from_file(t_raw *raw, char *str)
{
  int		max;
  int		len;
  char		*tok;

  if (!str)
    return (-1);
  max = raw->history->max - 1;
  free_hist(raw->history);
  free(raw->history);
  len = raw_strchr(str, '\n');
  (len > max) ? (max = len) : (0);
  raw->history = new_hist(max);
  str = raw_strdup(str);
  tok = strtok(str, "\n");
  if (tok)
    {
      while (1)
	{
	  raw->history->index = -1;
	  hist_add_str(raw, tok);
	  if ((tok = strtok(NULL, "\n")) != NULL)
	    break;
	}
    }
  free(str);
  return (0);
}
