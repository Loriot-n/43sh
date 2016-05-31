/*
** build_cd.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Tue May 31 16:23:32 2016 CUENAT
*/

#include "shell.h"

char	*get_history(char **history, char *path)
{
  int	i;
  int	j;
  char	tmp[PATH_MAX];

  i = 0;
  while (path[i] && path[i] != '-')
    i++;
  if (!path[i + 1])
    return (history[1]);
  j = 0;
  while (history[j] && (j != path[i + 1] - 48 ||
			strcmp(history[j], getcwd(tmp, PATH_MAX)) == 0))
    j++;
  if (!(history[j]))
    dprintf(2, "cd: no such entry in dir stack\n");
  return (history[j]);
}

char	**fill_history(char **tab, char *path)
{
  int	i;

  i = 3;
  if (strcmp(tab[0], path) == 0)
    return (tab);
  while (i > 0)
    {
      tab[i] = tab[i - 1];
      i--;
    }
  if (path)
    tab[0] = strdup(path);
  return (tab);
}
char	**init_history(void)
{
  char	**history;
  char	tmp[PATH_MAX];

  if (!(history = malloc(sizeof(char *) * 5)))
    exit(EXIT_FAILURE);
  history[0] = strdup(getcwd(tmp, PATH_MAX));
  history[1] = NULL;
  history[2] = NULL;
  history[3] = NULL;
  history[4] = NULL;
  return (history);
}

static char	*get_home(t_shell *shell)
{
  char		*path;
  struct passwd	*info;

  if (!(path = get_env(shell, "$HOME")))
    {
      info = getpwuid(geteuid());
      path = ft_strcat("HOME=", info->pw_dir);
      path = &path[5];
    }
  return (path);
}

void		ft_cd(t_shell *shell)
{
  char		*path;
  static char	**history = NULL;
  char		tmp[PATH_MAX];

  if (!(history))
    history = init_history();
  if (!(path = shell->cur_exec[1]) || strcmp(shell->cur_exec[1], "~") == 0)
    path = get_home(shell);
  if (path[0] == '.' && strlen(path) > 2)
    path = join(2, '\0', getcwd(tmp, PATH_MAX), &path[1]);
  if (path[0] == '-')
    path = get_history(history, path);
  if (path && chdir(path) == -1)
    {
      dprintf(2, "%s: %s.\n", path, strerror(errno));
      shell->res_exec = 1;
      return ;
    }
  history = fill_history(history, getcwd(tmp, PATH_MAX));
}
