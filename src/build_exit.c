/*
** build_exit.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 25 15:19:23 2016 CUENAT
** Last update Wed May 25 15:25:29 2016 CUENAT
*/

#include "shell.h"

void	ft_exit(t_shell *shell, char *tkn, int end)
{
  (void)(tkn);
  (void)(end);
  printf("exit\n");
  if (shell->cur_instr[1] != NULL)
    exit(my_getnbr(shell->cur_instr[1]));
  else
    exit(0);
}
