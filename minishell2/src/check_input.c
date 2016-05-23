/*
** exec_function.c for  in /home/stanislas/PSU_2015_minishell2/src
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed Mar 30 13:19:58 2016 CUENAT
** Last update Tue Apr  5 11:22:47 2016 CUENAT
*/

#include "include.h"

int	ft_check_syntax_errors_2(char *str, int i, int bol)
{
  if (i == 0 && (str[i] == '|' || str[i] == '<' || str[i] == '>'))
    bol = 1;
  else if (i == my_strlen(str) &&
	   (str[i] == '|' || str[i] == '<' || str[i] == '>'))
    bol = 1;
  return (bol);
}

int	ft_check_syntax_errors_1(char *str, int i, int bol)
{
  if (str[i] == '|' && str[i + 1] == '|')
    bol = 2;
  else  if (str[i] == '<' && ((str[i + 1] == '<' && str[i + 2] == '<')
			      || (str[i + 1] == '>')))
    bol = 1;
  else if (str[i] == '>' && ((str[i + 1] == '>' && str[i + 2] == '>')
			     || (str[i + 1] == '<')))
    bol = 1;
  return (bol);
}

int	ft_check_syntax_errors(char *str)
{
  int	bol;
  int	i;

  i = 0;
  bol = -1;
  while (str[i])
    {
     bol = ft_check_syntax_errors_1(str, i, bol);
     bol = ft_check_syntax_errors_2(str, i, bol);
     i++;
     if (bol == 1)
       my_putstr("Invalid null command.\n");
     if (bol == 2)
       my_putstr("Missing name for redirect.\n");
     if (bol != -1)
       return (-1);
    }
  return (0);
}
