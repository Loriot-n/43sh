/*
** fill_struct.c for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 18 16:08:26 2016 CUENAT
** Last update Thu May 26 15:32:52 2016 CUENAT
*/

#include "shell.h"

char	**ft_create_env()
{
  char	**tmp;
  char	*pwd;
  struct passwd	*info;

  info = getpwuid(geteuid());
  if ((tmp = malloc(sizeof(char *) * 6)) == NULL)
    exit(EXIT_FAILURE);
  if ((pwd = malloc(sizeof(char) * PATH_MAX)) == NULL)
    exit(EXIT_FAILURE);
  tmp[0] = ft_strcat("NAME=", info->pw_name);
  tmp[1] = ft_strcat("HOME=", info->pw_dir);
  tmp[2] = ft_strcat("OLDPWD=", getcwd(pwd, PATH_MAX));
  tmp[3] = strdup("PATH=/bin:/usr/bin");
  tmp[4] = ft_strcat("PWD=", getcwd(pwd, PATH_MAX));
  tmp[5] = NULL;
  free(pwd);
  return (tmp);
}

char	**ft_fill_bin_path(char **env)
{
  int	i;

  i = 0;
  while (env[i] && ft_find_line_env(env[i], "PATH=") == -1)
    i += 1;
  if (env[i] != NULL)
    return (split(&env[i][5], ":"));
  return (NULL);
}

int	ft_fill_env(char **env, t_shell *shell)
{
  if (env == NULL || ft_tab_len(env) < 2)
    shell->env = ft_create_env();
  else
    shell->env = ft_strdup_tab(env);
  return (0);
}
t_shell		*ft_init_struct()
{
  t_shell	*tmp;

  if ((tmp = malloc(sizeof(t_shell))) == NULL)
    exit(EXIT_FAILURE);
  tmp->env = NULL;
  tmp->path = NULL;
  tmp->exec_list = NULL;
  tmp->alias = NULL;
  tmp->res_exec = 0;
  return (tmp);
}
