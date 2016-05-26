/*
** cmd_history.c for history in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Wed May 25 13:27:52 2016 Nicolas Loriot
** Last update Thu May 26 17:10:46 2016 Nicolas Loriot
*/

#include "shell.h"

int		get_fd_history()
{
  int		fd;
  static int	passed = 0;

  if (passed == 1)
    return (-1);
  if ((fd = open(".42sh_history", O_CREAT | O_RDWR, 0666)) == -1)
    {
      passed = 1;
      printf("42sh_history : %s", strerror(errno));
      return (-1);
    }
  return (fd);
}

void		append_history(char *value)
{
  int		id;
  int		fd;

  id = 0;
  if ((fd = get_fd_history()) == -1)
    return ;
  while (get_next_line(fd))
    ++id;
  dprintf(fd, "%d %s\n", id, value);
}
