/*
** launch_shell.c for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 18 18:24:09 2016 CUENAT
** Last update Tue May 24 16:08:46 2016 CUENAT
*/

#include "shell.h"

char	*ft_fill_path_for_execve(char *dest, char **path)
{
  char	*tmp;
  int	i;

  i = 0;
  while (path[i])
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
int	ft_create_exec_function(t_shell *shell, t_sub_list *tmp)
{
  int	i;
  char	*tkn;
  int	end;

  i = 0;
  shell->fd_in = 0;
  tkn = strdup("\0");
  while (tmp->exec_cmd[i])
    {
      shell->cur_exec = ft_fill_tab_for_execve(tmp->exec_cmd, &i);
      shell->cur_exec[0] =
	ft_fill_path_for_execve(shell->cur_exec[0], shell->path);
      (tmp->exec_cmd[i] != NULL) ? (end = 0) : (end = 1);
      ft_execute_instr(shell, tkn, end);
      free(tkn);
      if (tmp->exec_cmd[i] != NULL)
	tkn = strdup(tmp->exec_cmd[i]);
      ft_free_tab(shell->cur_exec);
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
      write(1, "$> ", 2);
    }
  return (0);
}
