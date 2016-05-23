/*
** env_function.c for  in /home/stanislas/PSU_2015_minishell2/src
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 29 11:18:28 2016 CUENAT
** Last update Tue Apr 12 12:05:01 2016 CUENAT
*/

#include "include.h"

char	**my_str_to_word_tab(char **bin_path, char *path)
{
  int	i;
  int	j;
  int	k;

  i = 5;
  k = 0;
  while (path[i])
    {
      j = i;
      while (path[i] && path[i] != ':')
	i++;
      bin_path[k] = ft_itoj_strcpy(j, i, path);
      (path[i] != '\0') ? (i++) : 0;
      k++;
    }
  bin_path[k++] = my_strdup(".");
  bin_path[k] = NULL;
  i = 0;
  return (bin_path);
}

char	**ft_get_bin_path(char *path)
{
  char	**bin_path;
  int	i;
  int	j;

  j = 0;
  i = 2;
  while (path[j])
    {
      if (path[j] == ':')
	i++;
      j++;
    }
  if ((bin_path = malloc(sizeof(char *) * (i + 1))) == NULL)
    exit(EXIT_FAILURE);
  bin_path = my_str_to_word_tab(bin_path, path);
  return (bin_path);
}

int	ft_find_in_env(char *env, char *cmp)
{
  int	i;

  i = 0;
  while (env[i] && cmp[i])
    {
      if (env[i] != cmp[i])
	return (-1);
      i++;
    }
  return (0);
}

char	**ft_find_bin_path(char **env)
{
  int	i;
  char	**bin_path;

  i = 0;
  while (ft_find_in_env(env[i], "PATH=") == -1 && env[i])
    i++;
  if (env[i] != NULL)
    bin_path = ft_get_bin_path(env[i]);
  return (bin_path);
}

char	**ft_copy_env(char **environ)
{
  char	**env;
  int	i;

  i = 0;
  if ((env = malloc(sizeof(char *) * (my_strlen_tab(environ) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (environ[i] != NULL)
    {
      env[i] = my_strdup(environ[i]);
      i++;
    }
  env[i] = NULL;
  return (env);
}
