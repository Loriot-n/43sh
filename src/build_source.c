/*
** build_source.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "shell.h"

void	ft_source(t_shell *shell)
{
  if (!shell->cur_exec[1])
    {
      dprintf(2, "%s\n", "source: not enough arguments");
      return ;
    }
  if (access(shell->cur_exec[1], F_OK | R_OK) != 0)
    {
      dprintf(2, "source: aucun fichier ou dossier de ce type: %s\n",
	      shell->cur_exec[1]);
      return ;
    }
  parse_options(shell, shell->cur_exec[1]);
  return ;
}
