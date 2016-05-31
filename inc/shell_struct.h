/*
** shell_struct.h for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/inc/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#ifndef SHELL_STRUCT_H_
# define SHELL_STRUCT_H_

typedef struct 	s_alias t_alias;

typedef	struct		s_sub_list
{
  int			separator;
  char			*cmd;
  char			**exec_cmd;
  struct s_sub_list	*next;
}			t_sub_list;

typedef struct		s_list
{
  char			*cmd;
  t_sub_list		*sub_list;
  struct s_list		*next;
}			t_list;

typedef struct		s_shell
{
  char			**env;
  char			**path;
  t_list		*exec_list;
  t_alias		*alias;
  int			fd_in;
  char			**cur_exec;
  int			res_exec;
  int			exit;
}			t_shell;

#endif /* !SHELL_STRUCT_H_ */
