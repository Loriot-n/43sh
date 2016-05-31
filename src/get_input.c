/*
** get_input.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Fri May 27 12:08:05 2016 Nicolas Loriot
** Last update Tue May 31 15:34:15 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

t_raw		*init_raw(char *to_send)
{
  t_raw		*new;

  new = raw_alloc(sizeof(t_raw));
  new->line = raw_alloc(sizeof(t_line));
  new->line->prompt = raw_alloc(sizeof(t_str));
  new->line->input = raw_alloc(sizeof(t_str));
  new->term = raw_alloc(sizeof(t_term));
  new->history = raw_alloc(sizeof(t_hist));
  new->line->input->buffer = raw_strdup("");
  new->line->input->len = 0;
  new->line->oldcursor = 0;
  new->line->cursor = 0;
  new->term->fd = STDOUT_FILENO;
  new->term->mode = 0;
  tcgetattr(0, &new->term->origin);
  new->buffer = NULL;
  new->safe = 1;
  new->to_return = raw_strdup(to_send);
  return (new);
}

char		*get_line(t_raw *raw, char *prompt)
{
  set_line(raw, "", 0);
  raw->line->prompt->buffer = prompt;
  raw->line->prompt->len = strlen(raw->line->prompt->buffer);
  write(raw->term->fd, raw->line->prompt->buffer, strlen(prompt));
  get_raw_input(raw);
  read_mode(raw, 0);
  write(1, "\n", 1);
  raw->buffer = raw_strdup(raw->line->input->buffer);
  return (raw->buffer);
}

void		input_error(int err)
{
  if (err == BELL)
    dprintf(STDERR_FILENO, C_BELL);
  ioctl(STDERR_FILENO, I_FLUSH, FLUSHR);
}
