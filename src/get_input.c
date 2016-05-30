/*
** get_input.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Fri May 27 12:08:05 2016 Nicolas Loriot
** Last update Fri May 27 17:03:09 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

t_win		*init_window()
{
  t_win		*win;

  if (!(win = malloc(sizeof(t_win))))
    exit(EXIT_FAILURE);
  initscr();
  keypad(stdscr, TRUE);
  win->pos.x = 0;
  win->pos.y = 0;
  return (win);
}

t_win		*move_cursor(t_win *window, int catch, char *line)
{
  if (!strlen(line))
    return (NULL);
  if (catch == KEY_LEFT)
    {
      if (move(window->pos.y, window->pos.x - 1) != ERR)
	refresh();
    }
  else if (catch == KEY_RIGHT)
    {
      if (move(window->pos.y, window->pos.x + 1) != ERR)
	refresh();
    }
  return (window);
}

char		*get_line(t_win *window)
{
  char		*line;
  int		catch;
  int		i;

  i = 0;
  if (!(line = malloc(sizeof(char) * 2)))
    exit(EXIT_FAILURE);
  while ((catch = getch()) != KEY_ENTER)
    {
      if (catch == KEY_LEFT || catch == KEY_RIGHT)
	window = move_cursor(window, catch, line);
    }
}

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
  line[i + 1] = 0;
  while (line[i])
}
