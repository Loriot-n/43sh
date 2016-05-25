/*
** env_values.c for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/src/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "shell.h"

char	*get_env(char **env, char *var)
{
  int	i;
  char	*tmp;

  i = 0;
  while (env[i] && ft_find_line_env(env[i], var) == -1)
    i += 1;
  if (!env[i])
    return (NULL);
  tmp = env[i];
  return (&tmp[strlen(var) + 1]);
}

static int	check(char *line)
{
  int		i;

  i = 0;
  while (line[i] && line[i] != '$')
    i++;
  if (!line[i])
    return (-1);
  return (1);
}

char	*concat(char **lexed, char *value, int pos)
{
  char	*answer;
  int	i;

  answer = strdup("");
  i = 0;
  while (i != pos)
    {
      if (!(answer = realloc(answer, strlen(answer) + strlen(lexed[i]) + 2)))
	exit(EXIT_FAILURE);
      answer = add_char(strcat(answer, lexed[i]), ' ');
      i++;
    }
  i += 2;
  if (!(answer = realloc(answer, strlen(answer) + strlen(value) + 2)))
    exit(EXIT_FAILURE);
  answer = add_char(strcat(answer, value), ' ');
  while (lexed[i])
    {
      if (!(answer = realloc(answer, strlen(answer) + strlen(lexed[i]) + 2)))
	exit(EXIT_FAILURE);
      answer = add_char(strcat(answer, lexed[i]), ' ');
      i++;
    }
  ft_free_tab(lexed);
  return (answer);
}

char	*replace_env(t_shell *shell, char *line)
{
  char	**tab;
  int	i;
  char	*val;

  if (check(line) == -1)
    return (line);
  tab = split(line, "$");
  i = 0;
  while (tab[i] && strcmp(tab[i], "$") != 0)
    i++;
  if (!tab[i + 1])
    return (line);
  if (!(val = get_env(shell->env, tab[i + 1])))
    {
      dprintf(2, "%s: Undefined variable\n", tab[i + 1]);
      return (line);
    }
  free(line);
  return (concat(tab, val, i));
}
