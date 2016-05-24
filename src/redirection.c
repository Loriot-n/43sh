/*
** redirection.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue May 24 13:59:30 2016 CUENAT
** Last update Tue May 24 15:52:51 2016 CUENAT
*/

#include "shell.h"

void    ft_rewrite(char *file, int fd_in)
{
  int   fd;
  char  buf[512];
  int   oct;

  if ((fd = open(file , O_CREAT | O_RDWR, S_IRWXU)) == -1)
    exit(EXIT_FAILURE);
  while ((oct = read(fd_in, buf, sizeof(buf))) != 0)
    write(fd, buf, oct);
  close(fd);
}

void    ft_write_at_end(char *file, int fd_in)
{
  int   fd;
  char  buf[512];
  int   oct;

  if ((fd = open(file, O_CREAT | O_APPEND | O_RDWR, S_IRWXU)) == -1)
    exit(EXIT_FAILURE);
  while ((oct = read(fd_in, buf, sizeof(buf))) != 0)
    write(fd, buf, oct);
  close(fd);
}
