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

int	ft_check_token(char *line, char *tkn)
{

  return (0);
}

int	ft_echo_with_return_line(t_shell *shell)
{
  int	i;
  int	pb;

  i = 1;
  while (shell->cur_exec[i])
    {
      if ((pb = ft_check_token(shell->cur_exec[i], "'\"")) != 0)
	{
	  printf("unmatched %c\n", shell->cur_exec[i][pb]);
	  return (-1);
	}
      i += 1;
    }
  printf("\n");
  return (0);
}

int	ft_echo_without_return_line(t_shell *shell)
{
  int	i;
  int	pb;

  i = 1;
  while (shell->cur_exec[i])
    {
      if ((pb = ft_check_token(shell->cur_exec[i], "'\"")) != 0)
	{
	  printf("unmatched %c\n", shell->cur_exec[i][pb]);
	  return (-1);
	}
      i += 1;
    }
  return (0);
}


int	ft_echo(t_shell *shell)
{

  if (shell->cur_exec[1] == NULL)
    printf("\n");
  /*if (shell->cur_exec[1] != NULL && strcmp(shell->cur_exec[1], "-n") == 0)
    ft_echo_without_return_line(shell);
  else
  ft_echo_with_return_line(shell);*/
  /*for (int i = 1; shell->cur_exec[i]; i++)
    {
      printf("%s", shell->cur_exec[i]);
      if (shell->cur_exec[i + 1] != NULL)
	printf(" ");
	}*/
  printf("\n");
  return (0);
}
