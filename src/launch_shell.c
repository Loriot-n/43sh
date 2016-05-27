/*
** launch_shell.c for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 18 18:24:09 2016 CUENAT
** Last update Thu May 26 14:36:57 2016 CUENAT
*/

#include "shell.h"

char	*ft_fill_path_for_execve(char *dest, char **path)
{
  char	*tmp;
  int	i;

  i = 0;
  while (path != NULL && path[i])
    {
      if ((tmp = malloc(sizeof(char) *
			(strlen(dest) + strlen(path[i]) + 2))) == NULL)
	exit(EXIT_FAILURE);
      strcpy(tmp, path[i]);
      tmp[strlen(tmp) + 1] = '\0';
      tmp[strlen(tmp)] = '/';
      strcat(tmp, dest);
      if (access(tmp, X_OK) == 0)
	{
	  free(dest);
	  return (tmp);
	}
      free(tmp);
      i += 1;
    }
  return (dest);
}

char	**ft_fill_tab_for_execve(char **cmd, int *i)
{
  char	**res;
  int	j;

  j = 0;
  if ((res = malloc(sizeof(char *) * 2)) == NULL)
    exit(EXIT_FAILURE);
  while (cmd[*i] && cmd[*i][0] != '|' && cmd[*i][0] != '<'
	 && cmd[*i][0] != '>')
    {
      if ((res = realloc(res, sizeof(char *) * (j + 2))) == NULL)
	exit(EXIT_FAILURE);
      res[j] = strdup(cmd[*i]);
      j += 1;
      *i +=1;
    }
  res[j] = NULL;
  return (res);
}
int	ft_create_exec_function(t_shell *shell, t_sub_list *tmp, char *tkn)
{
  int	i;
  int	end;

  i = 0;
  signal(SIGSEGV, segfault);
  if (tmp->separator == NO || (tmp->separator == AND && shell->res_exec == 0)
      || (tmp->separator == OR && shell->res_exec == -1))
    {
      while (tmp->exec_cmd[i])
	{
	  shell->cur_exec = ft_fill_tab_for_execve(tmp->exec_cmd, &i);
	  if (ft_is_a_build_in(shell->cur_exec[0]) == -1)
	    shell->cur_exec[0] =
	      ft_fill_path_for_execve(shell->cur_exec[0], shell->path);
	  (tmp->exec_cmd[i] != NULL) ? (end = 0) : (end = 1);
	  ft_choose_type_execution(shell, tkn, end);
	  free(tkn);
	  if (tmp->exec_cmd[i] != NULL)
	    tkn = strdup(tmp->exec_cmd[i]);
	  ft_free_tab(shell->cur_exec);
	  (tmp->exec_cmd[i] != NULL) ? (i += 1) : 0;
	}
    }
  return (0);
}

int		ft_start_exec(t_shell *shell)
{
  t_list	*tmp_list;
  t_sub_list	*tmp_sub;
  char		*tkn;

  tmp_list = shell->exec_list;
  while (tmp_list != NULL)
    {
      tmp_sub = tmp_list->sub_list;
      while (tmp_sub != NULL)
	{
	  tkn = strdup("\0");
	  shell->fd_in = 0;
	  ft_create_exec_function(shell, tmp_sub, tkn);
	  tmp_sub = tmp_sub->next;
	}
      tmp_list = tmp_list->next;
    }
  return (0);
}

int	ft_launch_shell(t_shell *shell)
{
  char	*line;

  signal(SIGINT, ctrl);
  while ((line = get_next_line(0)) != NULL)
    {
      shell->path = ft_fill_bin_path(shell->env);
      line = replace_env(shell, line);
      line = epur(line);
      line = replace_alias(shell->alias, line);
      if (ft_check_input(line) == 0)
	{
	  ft_create_list(shell, line);
	  ft_create_sub_list(shell);
	  ft_start_exec(shell);
	  ft_free_struct(shell);
	}
      ft_free_tab(shell->path);
      free(line);
      write(2, "$> ", 3);
    }
  return (0);
}
