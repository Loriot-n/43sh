/*
** signal.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue May 24 17:09:20 2016 CUENAT
** Last update Wed May 25 16:19:51 2016 CUENAT
*/

#include "shell.h"

void	sig_handler(int sig)
{
  if (WIFEXITED(sig))
    return;
  else if (WIFSIGNALED(sig))
    {
      if (WTERMSIG(sig) == SIGSEGV)
	dprintf(2, "%s %s\n", "Segmentation fault", ((WCOREDUMP(sig) ?
						"(core dumped)" : "\0")));
	else if (WTERMSIG(sig) == SIGFPE)
	  dprintf(2, "%s %s \n", "Floating exception", ((WCOREDUMP(sig) ?
  						"(core dumped)" : "\0")));
      }
}

void	ctrl(int sig)
{
  (void)(sig);
  write(1, "\n$> ", 4);
}
