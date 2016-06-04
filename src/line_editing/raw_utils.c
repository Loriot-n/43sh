/*
** getch_read.c for dante in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Mon May 30 12:36:39 2016 Nicolas Loriot
** Last update Sat Jun 04 14:39:54 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

void		print_raw_string(char *str)
{
  while (*str)
    write(1, &(*str++), 1);
}

int		raw_strchr(char *str, char ch)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == ch)
	return (i);
      i++;
    }
  return (0);
}

void		read_mode(t_raw *raw, int state)
{
  struct	termios newT;

  newT = raw->term->origin;
  if (state)
    {
      newT.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IUTF8);
      newT.c_oflag &= ~OPOST;
      newT.c_cflag |= CS8;
      newT.c_cflag |= ~CSIZE;
      newT.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
      newT.c_cc[VMIN] = 1;
      newT.c_cc[VTIME] = 0;
    }
  tcsetattr(0, TCSAFLUSH, &newT);
  raw->term->mode = state;
}

void		redraw(t_raw *raw, int change, int enter)
{
  if (raw->line->oldcursor)
    dprintf(raw->term->fd, C_CUR_MOVE_BACK, raw->line->oldcursor);
  if (!change)
    {
      dprintf(raw->term->fd, C_LN_CLEAR_LINE, 0);
      print_raw_string(raw->line->input->buffer);
      if (raw->line->input->len)
	dprintf(raw->term->fd, C_CUR_MOVE_BACK, raw->line->input->len);
    }
  if (raw->line->cursor)
    dprintf(raw->term->fd, C_CUR_MOVE_FORWARD, raw->line->cursor);
}
