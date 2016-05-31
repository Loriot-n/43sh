/*
** raw_char.c for 42sf in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Mon May 30 16:39:02 2016 Nicolas Loriot
** Last update Tue May 31 15:18:05 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

int		get_std_escape(t_raw *raw, char *ch, int *enter, int *move)
{
  int		err;
  int		(*f[8])(t_raw *raw, char *ch, int *enter, int *move);
  char		*val;
  int		i;

  i = 0;
  err = 0;
  val = "\003\004\011\015\010\177\033\000";
  f[0] = &end_of_text;
  f[1] = &end_of_file;
  f[2] = &tabulation;
  f[3] = &carriage_ret;
  f[4] = &backspace;
  f[5] = &backspace;
  f[6] = &get_escape;
  f[7] = NULL;
  while (val[i] && val[i] != ch[0])
    i++;
  if (i < 7)
    return (f[i](raw, ch, enter, move));
  else
    return (BELL);
}

void		get_raw_input(t_raw *raw)
{
  int		*enter;
  int		err;
  int		*move;

  enter = raw_alloc(sizeof(int));
  move = raw_alloc(sizeof(int));
  *move = 0;
  read_mode(raw, 1);
  *enter = 0;
  while (!*enter)
    {
      raw->rd = raw_alloc(sizeof(char) * 10);
      raw->line->oldcursor = raw->line->cursor;
      if (read(raw->term->fd, raw->rd, 10) < 0)
	continue ;
      /* for (int j = 0; raw->d[j]; j++) */
	/* fprintf(stderr, "%o", raw->rd[j]); */
      if (raw->rd[0] > 31 && raw->rd[0] < 127)
	err = insert_char(raw, raw->rd[0]);
      else
	err = get_std_escape(raw, raw->rd, enter, move);
      (err != SUCCESS) ? (input_error(err)) : (0);
      redraw(raw, *move);
      free(raw->rd);
    }
  read_mode(raw, 0);
}