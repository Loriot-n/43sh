/*
** raw_history.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Mon May 30 17:13:04 2016 Nicolas Loriot
** Last update Sun Jun 05 14:10:29 2016 Nicolas Loriot
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
  new->tab = raw_calloc(new->max, sizeof(char *) * new->max);
  new->buffer = NULL;
  new->original = NULL;
  return (new);
}

void		free_hist(t_hist *hist)
{
  int		i;

  i = 0;
  while (i < hist->len)
    free(hist->tab[i++]);
  free(hist->tab);
  free(hist->buffer);
  free(hist->original);
  hist->len = 0;
  hist->max = 0;
}

void		hist_add_str(t_raw *raw, char *str, t_shell *shell)
{
  int		index;

  append_history(str, shell);
  index = 0;
  if (raw->history->index > -1)
    index = raw->history->index;
  if (index < raw->history->len && !strcmp(raw->history->tab[index], str))
    return ;
  if (raw->history->index < 0)
    {
      if (raw->history->len >= raw->history->max)
	free(raw->history->tab[raw->history->max - 1]);
      raw_memmove(raw->history->tab + 1, raw->history->tab, sizeof(char *) *
		  (raw->history->max - 1));
      raw->history->index = 0;
      raw->history->len++;
      if (raw->history->len > raw->history->max)
	raw->history->len = raw->history->max;
      raw->history->tab[0] = NULL;
    }
  if (raw->history->index > -1)
    free(raw->history->tab[raw->history->index]);
  raw->history->tab[raw->history->index] = raw_strdup(str);
}

int		raw_hist_move(t_raw *raw, int move)
{
  if (raw->history->index + move < -1 ||
      raw->history->index + move >= raw->history->len)
    return (BELL);
  if (raw->history->index < 0)
    {
      free(raw->history->original);
      raw->history->original = raw_strdup(raw->line->input->buffer);
    }
  free(raw->line->input->buffer);
  raw->history->index += move;
  if (raw->history->index < 0)
    raw->line->input->buffer = raw_strdup(raw->history->original);
  else
    raw->line->input->buffer =
      raw_strdup(raw->history->tab[raw->history->index]);
  raw->line->input->len = strlen(raw->line->input->buffer);
  return (SUCCESS);
  }
