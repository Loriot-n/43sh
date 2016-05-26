/*
** build_cd.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "shell.h"

char	**init_history(void)
{
  char	**history;

  if (!(history = malloc(sizeof(char *) * 3)))
    exit(EXIT_FAILURE);
  history[0] = NULL;
  history[1] = NULL;
  history[2] = NULL;
  return (history);
}

void		ft_cd(t_shell *shell, char *tkn, int end)
{
  static char	**history = NULL;

  if (!(history))
    history = init_history();
  (void)(shell);
  (void)(tkn);
  (void)(end);
}
