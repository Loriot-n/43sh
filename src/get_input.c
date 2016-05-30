/*
** get_input.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Fri May 27 12:08:05 2016 Nicolas Loriot
** Last update Mon May 30 17:26:22 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

char		*insert_char(char catch, char *line, int offset)
{
  int		i;

  i = 0;
  if (!(line = realloc(line, 1)))
    exit(EXIT_FAILURE);
  if ((i = strlen(line)) == offset)
    {
      line[i] = catch;
      line[i + 1] = 0;
      return (line);
    }
  while (i > offset)
    {
      line[i + 1] = line[i];
      i--;
    }
  line[offset] = line[i];
  return (line);
}

t_raw		*init_raw(char *to_send)
{
  t_raw		*new;

  new = raw_alloc(sizeof(t_raw));
  new->line = raw_alloc(sizeof(t_line));
  new->term = raw_alloc(sizeof(t_term));
  new->history = raw_alloc(sizeof(t_hist));
  new->line->input->buffer = raw_strdup("");
  new->line->input->len = 0;
  new->line->prompt->buffer = raw_strdup("");
  new->line->prompt->len = 0;
  new->line->oldcursor = 0;
  new->line->cursor = 0;
  new->term->fd = STDOUT_FILENO;
  if (!isatty(new->term->fd))
  new->term->mode = 0;
  tcgetattr(0, &new->term->origin);
  new->buffer = NULL;
  new->to_return = raw_strdup(to_send);
  return (new);
}

char		*get_line(t_raw *raw, char *prompt)
{
  raw->line->prompt->buffer = prompt;
  raw->line->prompt->len = strlen(raw->line->prompt->buffer);
  fprintf(stdout, "%s ", raw->line->prompt->buffer);
}
