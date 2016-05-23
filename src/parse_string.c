/*
** parse_string.c for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 18 16:49:11 2016 CUENAT
** Last update Wed May 18 17:28:00 2016 CUENAT
*/

#include "shell.h"

int	ft_find_line_env(char *env, char *cmp)
{
  int	i;

  i = 0;
  while (cmp[i])
    {
      if (cmp[i] != env[i])
	return (-1);
      i += 1;
    }
  return (0);
}

char	**ft_strdup_tab(char **cp)
{
  char	**res;
  int	i;

  if ((res = malloc(sizeof(char *) * (ft_tab_len(cp) + 1))) == NULL)
    exit(EXIT_FAILURE);
  i = 0;
  while (cp[i])
    {
      res[i] = ft_strdup(cp[i]);
      i++;
    }
  res[i] = NULL;
  return (res);
}

char	*ft_strdup(char *str)
{
  int	i;
  char	*res;

  i = 0;
  if ((res = malloc(sizeof(char) * (ft_strlen(str) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (str[i])
    {
      res[i] = str[i];
      i += 1;
    }
  res[i] = '\0';
  return (res);
}

int	ft_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}

int	ft_tab_len(char **str)
{
  int	i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}
