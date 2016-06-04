/*
** build_echo.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 25 15:52:42 2016 CUENAT
** Last update Sat Jun  4 17:38:37 2016 Sanchez Loris
*/

#include "shell.h"

void	print_it_baby(char *line)
{
  int	i;
  char	tmp;
  char	*one;

  tmp = 0;
  if (line[0] != '"' && line[0] != '\'')
    return ((void)printf("%s", line)) ;
  one = NULL;
  tmp = line[0];
  i = 1;
  while (line[i] && line[i] != tmp)
    i++;
  if (line[i]  != tmp)
    return ((void)dprintf(2, "Unmatched %c.\n", tmp));
  (!(one = malloc(sizeof(char) * i + 2))) ? exit(EXIT_FAILURE) : 0;
  strncpy(one, &line[1], i - 1);
  one[i - 1] = 0;
  printf("%s", one);
  print_it_baby(&line[i + 1]);
}

int	ft_echo(t_shell *shell)
{
  char	*cmd;
  int	i;

  if (shell->cur_exec[1] == NULL)
    {
      printf("\n");
      return (0);
    }
  cmd = shell->cur_exec[1];
  if (strcmp(shell->cur_exec[1], "-n") == 0)
    {
      cmd = strdup(shell->cur_exec[2]);
      cmd[strlen(cmd) - 1] = 0;
    }
  i = 1;
  while (shell->cur_exec[i])
    {
      print_it_baby(shell->cur_exec[i]);
      if (shell->cur_exec[i + 1])
	putchar(' ');
      i++;
    }
  putchar(10);
  return (0);
}
