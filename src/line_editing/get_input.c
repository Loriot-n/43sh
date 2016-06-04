/*
** get_input.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Fri May 27 12:08:05 2016 Nicolas Loriot
** Last update Thu Jun 02 19:27:01 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

t_raw		*init_raw(t_shell *shell, char *to_send)
{
  t_raw		*new;

  new = raw_alloc(sizeof(t_raw));
  new->line = raw_alloc(sizeof(t_line));
  new->line->prompt = raw_alloc(sizeof(t_str));
  new->line->input = raw_alloc(sizeof(t_str));
  new->term = raw_alloc(sizeof(t_term));
  new->history = raw_alloc(sizeof(t_hist));
  new->shell = shell;
  new->line->input->buffer = raw_strdup("");
  new->line->input->len = 0;
  new->line->oldcursor = 0;
  new->line->cursor = 0;
  new->term->nb_line = 0;
  new->term->fd = STDIN_FILENO;
  new->term->mode = 0;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &new->term->ws);
  tcgetattr(0, &new->term->origin);
  new->complete = 0;
  new->beg = NULL;
  new->buffer = NULL;
  new->safe = 1;
  new->to_return = raw_strdup(to_send);
  return (new);
}

int		set_hist(t_raw *raw, int set, int size)
{
  if (size <= 0)
    return (-1);
  if (set)
    raw->history = new_hist(size);
  else
    {
      free_hist(raw->history);
      free(raw->history);
    }
  return (0);
}

t_hist		*init_hist(t_raw *raw)
{
  t_hist	*hist;
  int		i;

  i = 0;
  hist = new_hist(raw->history->max - 1);
  while (i < raw->history->len)
    {
      hist->tab[i] = raw_strdup(raw->history->tab[i]);
      i++;
    }
  hist->len = raw->history->len;
  return (hist);
}

char		*get_line(t_raw *raw, char *prompt)
{
  t_hist	*hist;

  set_line(raw, "", 0);
  raw->history->index = -1;
  raw->line->prompt->buffer = prompt;
  raw->line->prompt->len = strlen(raw->line->prompt->buffer);
  write(1, raw->line->prompt->buffer, strlen(prompt));
  hist = init_hist(raw);
  read_mode(raw, 1);
  get_raw_input(raw, hist);
  read_mode(raw, 0);
  write(1, "\n", 1);
  /* free_hist(raw->history); */
  /* free(raw->history); */
  raw->history = hist;
  raw->buffer = raw_strdup(raw->line->input->buffer);
  return (raw->buffer);
}

void		input_error(int err)
{
  if (err == BELL)
    write(2, "\a", 1);
}
