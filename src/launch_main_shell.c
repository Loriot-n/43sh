/*
** launch_main_shell.c for  in /home/stanislas/clone/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Mon May 30 16:18:20 2016 CUENAT
** Last update Tue May 31 21:07:34 2016 Nicolas Loriot
*/

#include "arrows.h"
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
  t_raw	*raw;

  signal(SIGINT, ctrl);
  raw = init_raw("exit");
  while ((line = get_line(raw, "$> ")) != NULL)
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
      write(1, "$> ", 3);
    }
  raw_free(raw);
  printf("exit");
  return (0);
}
