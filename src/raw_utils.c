/*
** getch_read.c for dante in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Mon May 30 12:36:39 2016 Nicolas Loriot
** Last update Mon May 30 18:13:26 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

void		read_mode(t_raw *raw, int state)
{
  struct	termios newT;

  newT = raw->term->origin;
  if (state)
    {
      newT.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
      newT.c_oflag &= ~OPOST;
      newT.c_cflag |= CS8;
      newT.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
      newT.c_cc[VMIN] = 1;
      newT.c_cc[VTIME] = 0;
    }
  tcsetattr(0, TCSAFLUSH, &newT);
  raw->term->mode = state;
}

void		*raw_alloc(size_t size)
{
  void		*ret;

  if (!(ret = malloc(size)))
    exit(EXIT_FAILURE);
  return (ret);
}

void		*raw_realloc(void *oldptr, size_t size)
{
  void		*ret;
  if (!(ret = realloc(oldptr, size)))
    exit(EXIT_FAILURE);
  return (ret);
}

void		redraw(t_raw *raw, bool change)
{
  if (raw->line->oldcursor)
    printf(C_CUR_MOVE_BACK, raw->line->oldcursor);
  if (change)
    {
      printf(C_LN_CLEAR_END);
      printf("%s", raw->line->input->buffer);
      if (raw->line->input->len)
	printf(C_CUR_MOVE_BACK, raw->line->input->len);
    }
  if (raw->line->cursor)
    printf(C_CUR_MOVE_FORWARD, raw->line->cursor);
}
