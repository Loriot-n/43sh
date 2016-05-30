/*
** signal.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue May 24 17:09:20 2016 CUENAT
** Last update Mon May 30 11:21:37 2016 CUENAT
*/

#include "shell.h"

void	ctrl(int sig)
{
  (void)(sig);
  write(1, "\n$> ", 4);
}
