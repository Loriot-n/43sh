/*
** utils_1.c for  in /home/stanislas/PSU_2015_minishell2/utils
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 29 11:17:26 2016 CUENAT
** Last update Wed Mar 30 14:39:32 2016 CUENAT
*/

#include "include.h"

void	ft_free_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	{
	  free(tab[i]);
	  i++;
	}
    }
}

int	my_strlen_tab(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    i++;
  return (i);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*my_strdup(char *str)
{
  char	*res;
  int	i;

  i = 0;
  if ((res = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  res[i] = '\0';
  return (res);
}
