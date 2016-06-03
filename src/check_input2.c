/*
** check_input2.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Fri Jun  3 17:04:59 2016 CUENAT
*/

#include "shell.h"

int	ft_check_input_redirect(char **tab, int i)
{
  if (strcmp(tab[i], "<") == 0 || strcmp(tab[i], "<<") == 0)
    {
      if (i - 2 >= 0  && (strcmp(tab[i - 2], "|") == 0
			  || strcmp(tab[i - 2], "<") == 0
			  || strcmp(tab[i - 1], "<<") == 0))
	return (-1);
      else if (tab[i + 1] == NULL)
	return (-1);
      if (tab[i + 1] != NULL && (strchr(tab[i + 1], '|') != NULL ||
				 strchr(tab[i + 1], '&') != NULL ||
				 strchr(tab[i + 1], ';') != NULL))
	return (-1);
    }
  return (0);
}

int	ft_check_redirect(char **tab, int i)
{
  if (strcmp(tab[i], ">") == 0 || strcmp(tab[i], ">>") == 0)
    {
      if (tab[i + 1] == NULL)
	return (-1);
      if (tab[i + 2] != NULL &&
	  (strcmp(tab[i + 2], ">") == 0 || strcmp(tab[i + 2], ">>") == 0))
	return (-1);
      if (tab[i + 1] != NULL && (strchr(tab[i + 1], '&') != NULL ||
				 strchr(tab[i + 1], '|') != NULL ||
				 strchr(tab[i + 1], ';') != NULL))
	return (-1);
    }
  return (0);
}

int	is_const_string(char *line, int check)
{
  if (!line)
    return (check);
  if (line[0] == '"' || line[strlen(line) - 1] == '"' || line[0] == '\'' ||
      line[strlen(line) - 1] == '\'')
    return ((check == 1) ? 0 : 1);
  return (check);
}

int	is_in_const(char *line, int pos)
{
  int	i;
  int	mark;

  i = 0;
  mark = 0;
  while (line[i] && i != pos)
    {
      if (line[i] == '\'' || line[i] == '"')
	mark++;
      if (mark % 2 == 0)
	mark = 0;
      i++;
    }
  return (mark);
}

char	**split_no_const(char *line, char *tokens)
{
  char	**answer;
  int	i;
  int	check;
  char	**tmp;

  answer = NULL;
  i = 0;
  check = 0;
  tmp = split(line, tokens);
  while (tmp[i])
    {
      if (check == 0)
	{
	  answer = add_string(answer, tmp[i]);
	  answer[tab_len(answer) - 1] =
	  add_char(answer[tab_len(answer) - 1], ' ');
	}
      else
	answer[tab_len(answer) - 1] =
      join(2, 0, answer[tab_len(answer) - 1], add_char(strdup(tmp[i]), ' '));
      check = is_const_string(tmp[i], check);
      i++;
    }
  ft_free_tab(tmp);
  return (epur_tab(answer));
}
