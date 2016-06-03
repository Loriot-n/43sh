/*
** getch_read.c for dante in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Mon May 30 12:36:39 2016 Nicolas Loriot
** Last update Fri Jun 03 11:12:58 2016 Nicolas Loriot
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

int		draw_next_line(t_raw *raw, int multi, int enter)
{
  if (enter == 1 && multi == 0)
    return (0);
  if (multi >= 1 && raw->line->input->len < raw->term->ws.ws_col)
    return (multi);
  if ((raw->line->input->len < raw->term->ws.ws_col - raw->line->prompt->len))
    return (0);
  raw->line->cursor = 0;
  multi += 1;
  /* printf("%s\n", "okkk"); */
  write(1, "\n", 1);
  dprintf(raw->term->fd, C_LN_CLEAR_LINE, 0);
  dprintf(raw->term->fd, C_CUR_MOVE_DOWN, 1);
  dprintf(raw->term->fd, C_CUR_MOVE_BACK, raw->line->input->len - 1);
  /* dprintf(raw->term->fd, C_LN_CLEAR_LINE, 1); */
  return (multi);
  /* dprintf(raw->term->fd, "\n"); */
}

void		redraw(t_raw *raw, int change, int enter)
{
  static int	multi = 0;

  if (enter == 1)
    multi = 0;
  if (raw->line->oldcursor)
    dprintf(raw->term->fd, C_CUR_MOVE_BACK, raw->line->oldcursor);
  if (!change)
    {
      if ((multi = (draw_next_line(raw, multi, enter))))
	return ;
      dprintf(raw->term->fd, C_LN_CLEAR_LINE, 0);
      /* dprintf(raw->term->fd, "%s", raw->line->input->buffer); */
      print_raw_string(raw->line->input->buffer);
      if (raw->line->input->len)
	dprintf(raw->term->fd, C_CUR_MOVE_BACK, raw->line->input->len);
    }
  if (raw->line->cursor)
    dprintf(raw->term->fd, C_CUR_MOVE_FORWARD, raw->line->cursor);
  /* fsync(raw->term->fd); */
  /* ioctl(raw->term->fd, I_FLUSH, FLUSHR); */
}
