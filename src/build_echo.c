/*
** build_echo.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 25 15:52:42 2016 CUENAT
** Last update Thu Jun  2 18:17:14 2016 CUENAT
*/

#include "shell.h"

int	ft_check_token_start(char *tkn, char str)
{
  int	i;

  i = 0;
  while (tkn[i])
    {
      if (tkn[i] == str)
	return (0);
      i += 1;
    }
  return(1);
}

int	ft_check_token_end(char tkn, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == tkn)
	return (0);
      i += 1;
    }
  return(1);
}

int	ft_check_full_tkn(char **cur_exec, char *tkn)
{
  int	i;

  i = 0;
  while(cur_exec[i])
    {
      if (ft_check_token_start(tkn, cur_exec[i][0]) == 0)
	{
	  if (ft_check_token_end(cur_exec[i][0], &cur_exec[i][1]) == 1)
	    {
	      printf("Unmatched %c.", cur_exec[i][0]);
	      return (-1);
	    }
	}
      i += 1;
    }
  return (0);
}

void	ft_print_echo(t_shell *shell, int i)
{
  if (ft_check_token_start("'\"`", shell->cur_exec[i][0]) == 0)
    {
      write(shell->fd_in, &shell->cur_exec[i][1],
	    strlen(&shell->cur_exec[i][1]));
    }
  else
    write(1, shell->cur_exec[i], strlen(shell->cur_exec[i]));
  if (shell->cur_exec[i + 1] != NULL)
    write(1, " ", 1);
}

int	ft_echo(t_shell *shell)
{
  int	i;
  int	n;

  i = 1;
  n = 0;
  if (shell->cur_exec[1] != NULL && strcmp(shell->cur_exec[1], "-n") == 0)
    {
      n = 1;
      i = 2;
    }
  if (shell->cur_exec[1] == NULL)
    printf("\n");
  else
    {
      if (ft_check_full_tkn(shell->cur_exec, "\"'`") == 0)
	{
	  while (shell->cur_exec[i])
	    {
	      ft_print_echo(shell, i);
	      i += 1;
	    }
	}
      (n == 0) ? (write(1, "\n", 1)) : 0;
    }
  return (0);
}
