/*
** main.c for  in /home/stanislas/PSU_2015_minishell2/src
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 29 10:16:40 2016 CUENAT
** Last update Fri Apr  8 12:02:43 2016 CUENAT
*/

#include "include.h"

void	ft_free_all(t_shell *shell)
{
  ft_free_tab(shell->env);
  ft_free_tab(shell->bin_path);
  free(shell);
}

t_shell		*ft_init_shell(char **environ)
{
  t_shell	*shell;
  char		buf[150];

  if ((shell = malloc(sizeof(t_shell) * 1)) == NULL)
    exit(EXIT_FAILURE);
  if (environ[0] == NULL)
    {
      if ((shell->env = malloc(sizeof(char *) * 2)) == NULL)
	exit(EXIT_FAILURE);
      shell->env[0] = getcwd(buf, 150);
      shell->env[1] = NULL;
      if ((shell->bin_path = malloc(sizeof(char *) * 2)) == NULL)
       exit(EXIT_FAILURE);
       shell->bin_path[0] = ".\\";
       shell->bin_path[1] = NULL;
    }
  else
    {
      shell->env = ft_copy_env(environ);
      shell->bin_path = ft_find_bin_path(shell->env);
    }
  return (shell);
}

void		ft_getch_instr(t_shell *shell)
{
  char		*instr;
  t_list	*list;
  t_list	*tmp;

  signal(SIGINT, ctrl);
  my_putstr("$> ");
  while ((instr = get_next_line(0)))
    {
      if (ft_check_syntax_errors(instr) != -1)
	{
	  list = NULL;
	  list = ft_parse_instr(list, instr);
	  tmp = list;
	  ft_exec(shell, tmp);
	  list = ft_free_list(list);
	}
      my_putstr("$> ");
    }
}

int		main()
{
  extern char	**environ;
  t_shell	*shell;
  shell = ft_init_shell(environ);
  ft_getch_instr(shell);
  ft_free_all(shell);
  my_putstr("exit\n");
  return (0);
}
