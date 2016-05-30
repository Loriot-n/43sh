/*
** raw_char.c for 42sf in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Mon May 30 16:39:02 2016 Nicolas Loriot
** Last update Mon May 30 18:55:26 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

int		*get_std_escape(t_raw *raw, char ch, int *enter)
{
  int		*err;
  void		(*f[7])(t_raw *raw, int *err, int *enter);
  char		*val;

  val = "\003\004\011\015\010\033\000";
  f[0] = &end_of_text;
  return (err);
}

int		get_raw_input(t_raw *raw)
{
  int		*enter;
  int		*err;
  int		move;
  char		ch;

  enter = 0;
  err = SUCCESS;
  read_mode(raw, 1);
  while (!enter)
    {
      raw->line->oldcursor = raw->line->cursor;
      if (read(raw->term->fd, &ch, 1) < 0)
	continue ;
      if (ch > 31 && ch < 127)
	err = insert_char(raw, ch);
      else
	err = get_std_escape(raw, ch, enter);
    }
}
