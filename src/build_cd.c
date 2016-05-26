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
  char		*path;
  struct passwd	*info;
  static char	**history = NULL;
  char		tmp[PATH_MAX];

  if (!(history))
    history = init_history();
  if (!(path = shell->cur_exec[1]) && !(path = get_env(shell->env, "$HOME")))
    {
      info = getpwuid(geteuid());
      path = get_home(info);
      path = &path[5];
    }
  if (path[0] == '.')
    path = join(2, '\0', getcwd(tmp, PATH_MAX), &path[1]);
  if (chdir(path) == -1)
    {
      dprintf(2, "%s: Aucun fichier ou dossier de ce type.\n", path);
      return ;
    }
  (void)(shell);
  (void)(tkn);
  (void)(end);
}
