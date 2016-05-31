/*
** extended_escape.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src/
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Mon May 30 21:27:30 2016 Nicolas Loriot
** Last update Tue May 31 14:17:56 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

int		left_arrow(t_raw *raw, char *ch, int *enter, int *move)
{
  int		new;

  new = raw->line->cursor - 1;
  if (new < 0 || new > raw->line->input->len)
    return (BELL);
  raw->line->cursor--;
  return (SUCCESS);
}

int		right_arrow(t_raw *raw, char *ch, int *enter, int *move)
{
  int		new;

  new = raw->line->cursor + 1;
  if (new < 0 || new > raw->line->input->len)
    return (BELL);
  raw->line->cursor++;
  return (SUCCESS);
}

int		down_arrow(t_raw *raw, char *ch, int *enter, int *move)
{
  return (BELL);
}

int		up_arrow(t_raw *raw, char *ch, int *enter, int *move)
{
  return (BELL);
}

int		get_escape(t_raw *raw, char *ch, int *enter, int *move)
{
  char		seq[2];
  int		(*f[6])(t_raw *raw, char *ch, int *enter, int *move);
  char		*val;
  int		i;

  i = 0;
  val = "\104\103\101\102\106\110\061\062\063\064\065\066";
  f[0] = &left_arrow;
  f[1] = &right_arrow;
  f[2] = &up_arrow;
  f[3] = &down_arrow;
  f[4] = &end_key;
  f[5] = &home_key;
  f[6] = NULL;
  while (val[i] && val[i] != ch[2])
    i++;
  if (i < 6)
    return (f[i](raw, ch, enter, move));
  else if (i >= 6)
    return (get_extended_escape(raw, ch, ch[2], move));
  else
    return (BELL);
}
