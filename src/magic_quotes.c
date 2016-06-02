/*
** magic_quotes.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "shell.h"

char	*replace(char *line, char *one, int begin, int end)
{
  char	*answer;

  if (!(answer = malloc(sizeof(char) * (strlen(line) + strlen(one) + 2))))
    exit(EXIT_FAILURE);
  end = begin;
  while (line[end] && line[end] != '`')
    end++;
  end++;
  answer[0] = 0;
  answer = strncat(answer, line, begin);
  answer[begin - 1] = 0;
  strcat(answer, one);
  strcat(answer, &line[end]);
  return (answer);
}

char	*get_answer(t_shell *shell, char *tmp)
{
  int	p[2];
  int 	pid;
  char	*one;

  if (pipe(p) == -1 || (pid = fork()) == -1)
    exit(EXIT_FAILURE);
  if (pid != 0)
    {
      dup2(p[1], 1);
      close(p[0]);
      exec_simple_cmd(strdup(tmp), shell);
    }
  else
    {
      dup2(p[0], 0);
      close(p[1]);
      one = get_next_line(0);
      close(p[0]);
    }
  return (one);
}

char	*replace_quotes(t_shell *shell, char *line)
{
  int	i;
  int	j;
  char	*tmp;

  i = 0;
  while (line[i] && line[i] != '`')
    i++;
  if (!line[i])
    return (line);
  j = i + 1;
  tmp = strdup(&line[j]);
  j = 0;
  while (tmp[j] && tmp[j] != '`')
    j++;
  if (!tmp[j])
    {
      dprintf(2, "Unmatched `.\n");
      return (line);
    }
  tmp[j] = 0;
  return (replace(line, get_answer(shell, tmp), i + 1, 0));
}
