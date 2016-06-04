/*
** build_echo.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 25 15:52:42 2016 CUENAT
** Last update Sat Jun  4 15:52:59 2016 CUENAT
*/

#include "shell.h"

int	ft_echo(t_shell *shell)
{
  char	**echo_tab;
  for (int i = 0; shell->cur_exec[i]; i++)
    printf("%s\n", shell->cur_exec[i]);
  /*if (shell->cur_exec[1] != NULL && strcmp(shell->cur_exec[1], "-n") == 0)
    ft_echo_without_return_line(shell);
  else
  ft_echo_with_return_line(shell);*/

}
