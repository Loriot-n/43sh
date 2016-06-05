/*
** cmd_history.c for history in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Wed May 25 13:27:52 2016 Nicolas Loriot
** Last update Sun Jun 05 14:22:24 2016 Nicolas Loriot
*/

#include "shell.h"

int		get_fd_history(t_shell *shell)
{
  int		fd;
  char		*path;
  static int	passed = 0;

  if (!(path = get_env(shell, "HOME")))
    return (-1);
  path = join(2, 0, path, "/.42sh_history");
  if (passed == 1)
    return (-1);
  if ((fd = open(path, O_CREAT | O_RDWR | O_APPEND, 0666)) == -1)
    {
      passed = 1;
      printf("42sh_history : %s", strerror(errno));
      return (-1);
    }
  return (fd);
}

int		get_hist_elem_id(int fd)
{
  int		id;
  char		*str;

  id = 0;
  while ((str = get_next_line(fd)))
    {
      free(str);
      id++;
    }
  return (id + 1);
}

void		append_history(char *value, t_shell *shell)
{
  int		id;
  int		fd;

  id = 0;
  if ((fd = get_fd_history(shell)) == -1)
    return ;
  id = get_hist_elem_id(fd);
  dprintf(fd, "%d %s\n", id, value);
  close(fd);
}
