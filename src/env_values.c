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

char	*get_env(t_shell *shell, char *var)
{
  int	i;
  char	*tmp;
  char	**env;
  char	one[15];

  i = 0;
  env = shell->env;
  if (var && strcmp(var, "?") == 0)
    {
      sprintf(one, "%d", shell->res_exec);
      return (strdup(one));
    }
  while (env[i] && ft_find_line_env(env[i], var) == -1)
    i += 1;
  if (!env[i] || !var)
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
  if (!(answer = realloc(answer, strlen(answer) + strlen(value) + 2)))
    exit(EXIT_FAILURE);
  answer = add_char(strcat(answer, value), ' ');
  i += 2;
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
  char	**tmp;
  int	i;
  char	*val;

  if (check(line) == -1)
    return (line);
  tab = split(line, " $");
  i = 0;
  while (tab[i] && strcmp(tab[i], "$") != 0)
    i++;
  if (!tab[i] || !tab[i + 1])
    return (line);
  tmp = split(tab[i + 1], "/");
  if (!(val = get_env(shell, tmp[0])))
    {
      dprintf(2, "%s: Undefined variable\n", tmp[0]);
      return (line);
    }
  val = join(2, 0, val, tab_join(0, &tmp[1]));
  free(line);
  ft_free_tab(tmp);
  return (concat(tab, val, i));
}
