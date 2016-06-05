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

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      write(1, &str[i], 1);
      i++;
    }
}

void	print_it_baby(char *line)
{
  int	i;
  char	tmp;
  char	*one;

  tmp = 0;
  if (!line)
    return ;
  if (line[0] != '"' && line[0] != '\'')
    return (my_putstr(line));
  one = NULL;
  tmp = line[0];
  i = 1;
  while (line[i] && line[i] != tmp)
    i++;
  if (line[i] != tmp)
    return ((void)dprintf(2, "Unmatched %c.\n", tmp));
  (!(one = malloc(sizeof(char) * i + 2))) ? exit(EXIT_FAILURE) : 0;
  strncpy(one, &line[1], i - 1);
  one[i - 1] = 0;
  my_putstr(one);
  print_it_baby(&line[i + 1]);
}

char	*eval_it(char *line)
{
  int	i;
  int	j;
  char	*answer;

  if (!(answer = malloc(sizeof(char) * strlen(line) + 1)))
    exit(EXIT_FAILURE);
  i = 0;
  j = 0;
  while (line[i])
    {
      if (line[i] == '\\' && line[i + 1] == 'n')
	{
	  answer[j] = 10;
	  i += 1;
	}
      else
	answer[j] = line[i];
      j++;
      i++;
    }
  free(line);
  answer[j] = 0;
  return (answer);
}

char	*remove_carreturn(char *line, int *check)
{
  if (!line || strlen(line) < 4 ||
      (line[strlen(line) - 1] != '"' && line[strlen(line) - 1]
		!= '\'') || line[strlen(line) - 2] != 10)
    return (line);
  *check = 1;
  line[strlen(line) - 2] = '"';
  line[strlen(line) - 1] = 0;
  return (line);
}

int	ft_echo(t_shell *shell)
{
  int	i;

  if (shell->cur_exec[1] == NULL)
    {
      printf("\n");
      return (0);
    }
  i = (strcmp(shell->cur_exec[1], "-n") == 0) ? 2 : 1;
  while (shell->cur_exec[i])
    {
      if (shell->cur_exec[i][0] == '\'' || shell->cur_exec[i][0] == '"')
	shell->cur_exec[i] = eval_it(shell->cur_exec[i]);
      print_it_baby(shell->cur_exec[i]);
      if (shell->cur_exec[i + 1])
	my_putstr(" ");
      i++;
    }
  if (strcmp(shell->cur_exec[1], "-n") != 0)
    putchar(10);
  return (0);
}
