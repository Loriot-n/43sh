/*
** signal.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue May 24 17:09:20 2016 CUENAT
** Last update Wed May 25 11:59:08 2016 CUENAT
*/

#include "shell.h"

void	segfault(int sig)
{
  (void)(sig);
  printf("segmentation fault\n$> ");
}

void	ctrl(int sig)
{
  (void)(sig);
  write(1, "\n$> ", 4);
}
