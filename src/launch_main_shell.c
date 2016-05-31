/*
** launch_main_shell.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Mon May 30 16:18:20 2016 CUENAT
** Last update Tue May 31 14:08:29 2016 CUENAT
*/


#include "shell.h"

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
	  if (ft_create_exec_function(shell, tmp_sub, tkn) == -1)
	    return (-1);
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
      //line = replace_glob(line);
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
  printf("exit");
  return (0);
}