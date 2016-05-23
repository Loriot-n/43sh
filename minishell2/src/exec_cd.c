/*
** exec_cd.c for  in /home/stanislas/PSU_2015_minishell2/src
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Fri Apr  8 13:17:28 2016 CUENAT
** Last update Fri Apr  8 18:50:43 2016 CUENAT
*/

#include "include.h"

char	*ft_strcat_for_cd(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*res;

  i = 5;
  j = 0;
  if ((res = malloc(sizeof(char) *
		    (my_strlen(str1) + my_strlen(str2) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (str1[i])
    res[j++] = str1[i++];
  i = 1;
  while (str2[i])
    res[j++] = str2[i++];
  res[j] = '\0';
  return (res);
}

int	ft_cd_oldpwd(char *old_pwd)
{
  if (old_pwd != NULL)
    {
      if (chdir(old_pwd) == -1)
	return (-1);
    }
  return (0);
}

int	ft_simple_cd(t_shell *shell)
{
  char	*cur_dir;
  char	*new_dir;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((cur_dir = malloc(sizeof(char) * PATH_MAX)) == NULL)
    exit(EXIT_FAILURE);
  cur_dir = getcwd(cur_dir, PATH_MAX);
  if ((new_dir = malloc(sizeof(char) * my_strlen(cur_dir)
			+ my_strlen(shell->cmd[1]))) == NULL)
    exit(EXIT_FAILURE);
  while (cur_dir[i] && (new_dir[j++] = cur_dir[i++]));
  new_dir[j++] = '/';
  i = 0;
  while (shell->cmd[1][i] && (new_dir[j++] = shell->cmd[1][i++]));
  new_dir[j + 1] = '\0';
  if (chdir(new_dir) == -1)
    {
      my_putstr("cd: ");
      shell->cmd[1] != NULL ?  my_putstr(shell->cmd[1]) : 0;
      my_putstr(": No such file or directory\n");
    }
  return (0);
}

int	ft_cd_at_home(t_shell *shell)
{
  int	i;
  char	*tmp;

  i = 0;
  while (shell->env[i] && ft_find_in_env(shell->env[i], "HOME=") == -1)
    i++;
  if (shell->env[i] != NULL)
    {
      if (shell->cmd[1] != NULL)
	tmp = ft_strcat_for_cd(shell->env[i], shell->cmd[1]);
      else
	tmp = my_strdup(&shell->env[i][5]);
    }
  else
    my_putstr("No Home environement variable\n");
  if (chdir(tmp) == -1)
    {
      my_putstr("cd: ");
      shell->cmd[1] != NULL ?  my_putstr(shell->cmd[1]) : 0;
      my_putstr(": No such file or directory\n");
    }
  return (0);
}

void		ft_cd(t_shell *shell)
{
  static char	*old_pwd = NULL;
  char		*new_oldpwd;
  int		i;

  i = 0;
  if ((new_oldpwd = malloc(sizeof(char) * PATH_MAX)) == NULL)
    exit(EXIT_FAILURE);
  new_oldpwd = getcwd(new_oldpwd, 150);
  if (shell->cmd[1] == NULL || shell->cmd[1][0] == '~')
    ft_cd_at_home(shell);
  else if (my_strcmp(shell->cmd[1], "-") == 1)
    ft_cd_oldpwd(old_pwd);
  else
    ft_simple_cd(shell);
  while (shell->env[i] && ft_find_in_env(shell->env[i++], "OLDPWD=") == -1);
  (shell->env[i] != NULL) ?
    (shell->env[i - 1] = ft_strcat("OLDPWD", new_oldpwd)) : 0;
  old_pwd = my_strdup(new_oldpwd);
  free(new_oldpwd);
}
