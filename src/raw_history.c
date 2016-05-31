/*
** raw_history.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Mon May 30 17:13:04 2016 Nicolas Loriot
** Last update Tue May 31 16:04:35 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

t_hist		*new_hist(int size)
{
  t_hist	*new;

  new = raw_alloc(sizeof(t_hist));
  new->max = size + 1;
  new->index = -1;
  new->len = 0;
  new->history = raw_alloc(sizeof(char *) * new->max);
  memset(new->history, 0, sizeof(char *) * new->max);
  new->buffer = NULL;
  new->original = NULL;
  return (new);
}

void		free_hist(t_hist *hist)
{
  int		i;

  i = 0;
  while (hist->history[i])
    free(hist->history[i++]);
  free(hist->history);
  free(hist->buffer);
  free(hist->original);
  hist->len = 0;
  hist->max = 0;
}

int		hist(t_raw *raw, int set, int size)
{
  return (-1);
}

t_hist		*hist_cpy(t_raw *raw)
{
  return (NULL);
}
