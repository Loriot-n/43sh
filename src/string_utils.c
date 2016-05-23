/*
** string_utils.c for  in /home/stanislas/PSU_2015_42sh/src
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 18 19:53:58 2016 CUENAT
** Last update Wed May 18 19:57:16 2016 CUENAT
*/

#include "shell.h"

char	*ft_strcat(char *str1, char *str2)
{
  char 	*res;
  int	i;
  int	j;

  j = 0;
  i = 0;
  if ((res = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1))) == NULL)
    exit(EXIT_FAILURE);
  while (str1[j])
    {
      res[i] = str1[j];
      i += 1;
      j +=1;
    }
  j = 0;
  while (str2[j])
    {
      res[i] = str2[j];
      i += 1;
      j +=1;
    }
  res[i] = '\0';
  return (res);
}
