/*
** launch_shell.c for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 18 18:24:09 2016 CUENAT
** Last update Mon May 23 18:38:16 2016 CUENAT
*/

#include "shell.h"

char	**ft_fill_tab_for_exec(char **f_exec, char **exec_cmd, int *i)
{
  int	j;

  j = 0;
  while (exec_cmd[*i] && exec_cmd[*i][0] != '|' && exec_cmd[*i][0] != '<'
	 &&  exec_cmd[*i][0] != '>')
    {
      if ((f_exec = realloc(f_exec, sizeof(char *) * (j + 2))) == NULL)
	exit(EXIT_FAILURE);
      f_exec[j] = strdup(exec_cmd[*i]);
      *i += 1;
      j += 1;
    }
  f_exec[j] = NULL;
  return (f_exec);
}

int	ft_create_exec_function(t_shell *shell, t_sub_list *tmp)
{
  int	i;
  char	**f_exec;

  i = 0;
  while (tmp->exec_cmd[i] != NULL)
    {
      if ((f_exec = malloc(sizeof(char *) * 1)) == NULL)
	exit(EXIT_FAILURE);
      f_exec = ft_fill_tab_for_exec(f_exec, tmp->exec_cmd, &i);

      ft_free_tab(f_exec);
      (tmp->exec_cmd[i] != NULL) ? (i += 1) : 0;
    }
  return (0);
}

int		ft_start_exec(t_shell *shell)
{
  t_list	*tmp_list;
  t_sub_list	*tmp_sub;

  tmp_list = shell->exec_list;
  while (tmp_list != NULL)
    {
      tmp_sub = tmp_list->sub_list;
      while (tmp_sub != NULL)
	{
	  ft_create_exec_function(shell, tmp_sub);
	  tmp_sub = tmp_sub->next;
	}
      tmp_list = tmp_list->next;
    }
  return (0);
}

int	ft_launch_shell(t_shell *shell)
{
  char	*line;

  (void)(shell);
  while ((line = get_next_line(0)) != NULL)
    {
      shell->path = ft_fill_bin_path(shell->env);
      shell->res_exec = 0;
      line = epur(line);
      if (ft_check_input(line) == 0)
	{
	  ft_create_list(shell, line);
	  ft_create_sub_list(shell);
	  ft_start_exec(shell);
	  ft_free_struct(shell);
	}
      ft_free_tab(shell->path);
      free(line);
    }
  return (0);
}
