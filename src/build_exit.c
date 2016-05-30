/*
** build_exit.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 25 15:19:23 2016 CUENAT
** Last update Wed May 25 15:37:33 2016 CUENAT
*/

#include "shell.h"

void	ft_exit(t_shell *shell)
{
  printf("exit\n");
  if (shell->cur_exec[1] != NULL)
    exit(my_getnbr(shell->cur_exec[1]));
  else
    exit(0);
}
