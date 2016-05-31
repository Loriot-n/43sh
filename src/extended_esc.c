/*
** extended_esc.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src/
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Mon May 30 21:48:19 2016 Nicolas Loriot
** Last update Tue May 31 17:45:23 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

int		delete_key(t_raw *raw, char *ch, int *enter, int *move)
{
  (void)enter;
  return (del_char(raw));
}

int		home_key(t_raw *raw, char *ch, int *enter, int *move)
{
  (void)enter;
  raw->line->cursor = 0;
  *move = 0;
  return (SUCCESS);
}

int		end_key(t_raw *raw, char *ch, int *enter, int *move)
{
  (void)enter;
  raw->line->cursor = raw->line->input->len;
  *move = 0;
  return (SUCCESS);
}

int		get_extended_escape(t_raw *raw, char *ch, char prev_seq, int *move)
{
  int	*enter;
  int	(*f[6])(t_raw *raw, char *ch, int *enter, int *move);
  char	*val;
  int	i;

  enter = raw_alloc(sizeof(int));
  *enter = 0;
  i = 0;
  val = "\063\061\064\103\104";
  f[0] = &delete_key;
  f[1] = &home_key;
  f[2] = &end_key;
  f[3] = &right_arrow;
  f[4] = &left_arrow;
  f[5] = NULL;
  if (ch[3] == '~')
    {
      while (val[i] && val[i] != ch[2])
	i++;
      if (i < 5)
	return (f[i](raw, ch, enter, move));
    }
  return (BELL);
}
