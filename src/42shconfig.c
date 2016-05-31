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

  if (access(path, F_OK | R_OK) != 0)
    return (-1);
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
  char	**tmp;
  char	*one;
  int	i;

  if ((fd = get_fd(path)) == -1)
    return ;
  i = 0;
  if (!(tmp = malloc(sizeof(char *) * 1)))
    exit(EXIT_FAILURE);
  tmp[0] = NULL;
  while ((one = get_next_line(fd)) && i < 100)
    {
      if (!(tmp = realloc(tmp, sizeof(char *) * (tab_len(tmp) + 2))))
	exit(EXIT_FAILURE);
      exec_simple_cmd(epur(one), shell);
      free(one);
      i++;
    }
}
