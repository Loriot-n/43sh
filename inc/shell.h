/*
** shell.h for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed May 18 15:32:47 2016 CUENAT
** Last update Thu May 26 19:36:47 2016 CUENAT
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
#include <stdarg.h>
#include "alias.h"
#include "shell_struct.h"
#include "get_next_line.h"
#include "built_ins.h"

#ifndef AND
# define AND 1
#endif

#ifndef OR
# define OR 2
#endif

#ifndef NO
# define NO 0
#endif

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
					int *sep);
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
** split.c
*/
char   	*my_strncpy(char *src, int n);
char	**split(char *str, char *tokens);
size_t	tab_len(char **str);

/*
** my_getnbr.c
*/
int	my_getnbr(char *str);
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
int	ft_create_exec_function(t_shell *shell, t_sub_list *tmp, char  *tkn);
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
int	ft_execute_instr_fork(t_shell *shell, char *tkn, int end);
int	ft_execute_instr_no_fork(t_shell *shell, char *tkn);
int	ft_redirect_or_pipe(t_shell *shell, char *tkn);

/*
** choose_type_execution.c
*/
int	ft_choose_type_execution(t_shell *shell, char *tkn, int end);
int	ft_is_a_build_in(char *cmd);

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
**42shconfig.c
*/
void	parse_options(t_shell *shell, char *file);

/*
** env_values.c
*/
char	*replace_env(t_shell *shell, char *line);
char	*get_env(char **env, char *var);

void	ft_env(t_shell *shell);

void	ft_source(t_shell *shell);
/*
** END ----- LAUNCH / CHECK/ SHELL ----- END
*/

/*
** join.c
*/
char	*join(int nb, char sep, ...);
char	*tab_join(char sep, char **tab);

/*
** export.c
*/
int	st_check(t_shell *shell, char **cur_exec);
char	**add_export(t_shell *shell, int fd);
void	sig_handler(int sig);

#endif /*!SHELL_H_*/
