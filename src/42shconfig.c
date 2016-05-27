/*
** 42shconfig.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "shell.h"

int	get_fd(char *path)
{
  int	fd;

  if ((fd = open(path, O_RDONLY)) < 0)
    {
      dprintf(2, "Error while opening %s: %s\n", path, strerror(errno));
      return (-1);
    }
  return (fd);
}

void	parse_options(t_shell *shell, char *path)
{
  int	fd;

  if (access(path, F_OK | R_OK) != 0)
    return ;
  if ((fd = get_fd(path)) == -1)
      return ;
  shell->alias = get_aliases(fd);
  if ((fd = get_fd(path)) == -1)
      return ;
  shell->env = add_export(shell, fd);
}
