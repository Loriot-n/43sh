/*
** utils_3.c for  in /home/stanislas/PSU_2015_minishell2
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Thu Mar 31 15:49:41 2016 CUENAT
** Last update Fri Apr  8 16:25:40 2016 CUENAT
*/

#include "include.h"

char	**ft_add_on_env(t_shell *shell)
{
  char	**res;
  int	i;
  int	j;

  j = 0;
  i = 0;
  if ((res = malloc(sizeof(char *) * (my_strlen_tab(shell->env) + 2))) == NULL)
    exit(EXIT_FAILURE);
  while (shell->env[i])
    res[j++] = shell->env[i++];
  if (shell->cmd[2] != NULL)
   res[j] = ft_strcat(shell->cmd[1], shell->cmd[2]);
  else
    res[j] = my_strdup(shell->cmd[1]);
  j++;
  res[j] = '\0';
  return (res);
}

char	*ft_strcat(char *str1, char *str2)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((res = malloc(sizeof(char) *
		    (my_strlen(str1) + my_strlen(str2) + 2))) == NULL)
    exit(EXIT_FAILURE);
  while (str1[i])
    res[j++] = str1[i++];
  i = 0;
  res[j++] = '=';
  while (str2[i])
    res[j++] = str2[i++];
  res[j] = '\0';
  return (res);
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  if (my_strlen(str1) != my_strlen(str2))
    return (-1);
  while (str1[i])
    {
      if (str1[i] != str2[i])
	return (-1);
      i++;
    }
  return (1);
}

char	*ft_get_path(char *bin_path, char *cmd)
{
  char	*tmp;
  int	i;
  int	j;

  if ((tmp = malloc(sizeof(char) *
		    (my_strlen(bin_path) + my_strlen(cmd) + 2))) == NULL)
    exit(EXIT_FAILURE);
  i = 0;
  j = 0;
  while (bin_path[i])
      tmp[j++] = bin_path[i++];
  tmp[j] = '/';
  j++;
  i = 0;
  while (cmd[i])
    tmp[j++] = cmd[i++];
  tmp[j] = '\0';
  if (access(tmp, X_OK) != 0)
    {
      free(tmp);
      return (NULL);
    }
  return (tmp);
}

char	**ft_add_cmd_tab(char *path, char *cut_instr, int start)
{
  int	i;
  int	j;
  int	k;
  char	**res;

  j = start - 1;
  i = 2;
  k = 1;
  while (cut_instr[j] && (((cut_instr[j++] == ' ') && i++) || 1));
  if ((res = malloc(sizeof(char *) * (i + 2))) == NULL)
    exit(EXIT_FAILURE);
  (start - 1 != my_strlen(cut_instr)) ? (i = start) : (i = start - 1);
  res[0] = my_strdup(path);
  while (cut_instr[j = i])
    {
      while (cut_instr[i] && cut_instr[i] != ' ')
	i++;
      res[k++] = ft_itoj_strcpy(j, i, cut_instr);
      (cut_instr[i] != '\0') ? (i++) : 0;
    }
  res[k] = NULL;
  return (res);
}
