/*
** epur_str.c for rush marvin in /home/qwebify/rendu/CPE/marvin_maire_q/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Wed May 18 19:00:46 2016 CUENAT
*/

#include "shell.h"

int	next_char(char *str, int i)
{
  while (str && str[i] && (str[i] == ' ' || str[i] == '\t'))
    i++;
  return (i);
}

void	*raoul(char *oldptr, int size)
{
  char	*newptr;
  int	i;

  i = 0;
  if (!(newptr = malloc(sizeof(char) * size + 5)))
    exit(EXIT_FAILURE);
  if (!oldptr)
    return (newptr);
  while (i < size && oldptr[i])
    {
      newptr[i] = oldptr[i];
      i++;
    }
  newptr[i] = '\0';
  free(oldptr);
  return (newptr);
}

char	*add_char(char *str, char new)
{
  int	i;

  i = 0;
  if (str)
    {
      i = ft_strlen(str);
      !(str = realloc(str, ft_strlen(str) + 2)) ? exit(EXIT_FAILURE) : 0;

    }
  else
    !(str = malloc(sizeof(char) * 2)) ? exit(EXIT_FAILURE) : 0;
  str[i] = new;
  str[i + 1] = 0;
  return (str);
}

char	*epur(char *str)
{
  int	i;
  char	*answer;

  if (!str || !str[0])
    return (strdup("\0"));
  if ((answer = malloc(sizeof(char) * (ft_strlen(str)) + 2)) == NULL)
    exit(EXIT_FAILURE);
  i = 0;
  answer[0] = '\0';
  while (str[i])
    {
      i = next_char(str, i);
      while (str[i] && (str[i] != ' ' && str[i] != '\t'))
	{
	  answer = add_char(answer, str[i]);
	  i++;
	}
      if (str[next_char(str, i)])
	answer = add_char(answer, ' ');
      if (str[i])
	i++;
    }
  return (answer);
}
