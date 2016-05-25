/*
** shell.h for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 18 15:32:47 2016 CUENAT
** Last update Wed May 25 12:07:06 2016 CUENAT
*/

#ifndef SHELL_H_
# define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <errno.h>
#include "get_next_line.h"

#ifndef AND
# define AND 1
#endif

#ifndef OR
# define OR 2
#endif

#ifndef NO
# define NO 0
#endif

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

typedef struct 		s_alias
{
  char			*cmd;
  char			*alias;
  struct s_alias	*next;
}			t_alias;

typedef struct		s_shell
{
  char			**env;
  char			**path;
  int			fd_in;
  char			**cur_exec;
  int			res_exec;
  t_alias		*alias;
  t_list		*exec_list;
}			t_shell;


/*
** START ----- FILL STRUCT ----- START
*/
/*
** fill_struct.c
*/
t_shell	*ft_init_struct();
int	ft_fill_env(char **env, t_shell *shell);
char	**ft_create_env();
char	**ft_fill_bin_path(char **env);
/*
** fill_list.c
*/
t_sub_list	*ft_add_sub_list_at_end(t_sub_list *list,
					char *tmp_c,
					int *sep,
					t_shell *shell);
int	ft_create_list(t_shell *shell, char *line);
t_list	*ft_add_at_end(t_list *exec_list, char *val);
int	ft_create_sub_list(t_shell *shell);

/*
** free_struct.c
*/
void	ft_free_struct(t_shell *shell);
void	ft_free_tab(char **tab);
/*
** END ----- FILL STRUCT ----- END
*/

/*
** START ----- PARSE / UTILS STRING ----- START
*/
/*
** parse_string.c
*/
int	ft_find_line_env(char *env, char *cmp);
char	*ft_strdup(char *str);
char	**ft_strdup_tab(char **cp);
int	ft_strlen(char *str);
int 	ft_tab_len(char **str);

/*
** string_utils.c
*/
char	*ft_strcat(char *str1, char *str2);

/*
** epur_str.c
*/
char	*epur(char *str);
char	*add_char(char *str, char new);
void	*raoul(char *oldptr, int size);
int	next_char(char *str, int i);

/*
** my_str_to_word_tab.c
*/
char   	*my_strncpy(char *src, int n);
char	**split(char *str, char *tokens);
size_t	tab_len(char **tab);

/*
** get_next_line.c
*/
char	*get_next_line(int fd);
char	*go_to_next(char *line, int *i, int *len);
char	*my_realloc(char *buf, int ctr);
int	my_strlen(char *str);
/*
** END ----- PARSE / UTILS STRING ----- END
*/

/*
** START ----- LAUNCH / CHECK / SHELL ----- START
*/
/*
** launch_shell.c
*/
int	ft_launch_shell(t_shell *shell);
int	ft_start_exec(t_shell *shell);
int	ft_create_exec_function(t_shell *shell, t_sub_list *tmp);
char	**ft_fill_tab_for_execve(char **cmd, int *i);
char	*ft_fill_path_for_execve(char *dest, char **path);

/*
** signal.c
*/
void	segfault(int sig);
void	ctrl(int sig);

/*
** execute_instruction.c
*/
int	ft_execute_instr(t_shell *shell, char *tkn, int end);
int	ft_redirect_or_pipe(t_shell *shell, char *tkn);

/*
** redirection.c
*/
void	ft_write_at_end(char *file, int fd_in);
void	ft_rewrite(char *file, int fd_in);
/*
** check_input.c
*/
int	ft_check_input(char *line);
int	ft_look_dot(char **tab, int i);
int	ft_look_and(char **tab, int i);
int	ft_look_or(char **tab, int i);
int	ft_look_bad_tkn(char *word, char *tkn);

/*
** END ----- PARSE / UTILS STRING ----- END
*/

/*
** START ----- ALIAS ----- START
*/
/*
** alias_list.c
*/
t_alias		*get_aliases(int fd);
t_alias		*insert_alias(char **cmd, char *alias, t_alias **head);
char		*replace_alias(t_alias *alias_list, char *cmd);

/*
**42shconfig.c
*/
void	parse_options(t_shell *shell, char *path);

/*
** END ----- ALIAS ----- END
*/

#endif /*!SHELL_H_*/
