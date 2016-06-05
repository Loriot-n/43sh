/*
** shell.h for  in /home/stanislas/PSU_2015_42sh
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
** yan typedef size_t
** Started on  Wed May 18 15:32:47 2016 CUENAT
** Last update Sun Jun 05 14:10:25 2016 Nicolas Loriot
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
#include <sys/stat.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <errno.h>
#include <stdarg.h>
#include <dirent.h>
#include <glob.h>
#include <ncurses.h>
#include "shell_struct.h"
#include "alias.h"
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

typedef struct dirent t_dir;

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
** launch_main_shell.c
*/
int	ft_launch_shell(t_shell *shell);
int	ft_start_exec(t_shell *shell);

/*
** launch_shell.c
*/
int	ft_create_exec_function(t_shell *shell, t_sub_list *tmp, char  *tkn);
char	**ft_fill_tab_for_execve(char **cmd, int *i);
char	*ft_fill_path_for_execve(char *dest, char **path);
char	*ft_fill_null_path(char *dest);

/*
** signal.c
*/
void	ctrl(int sig);

/*
** execute_instruction.c
*/
int	ft_execute_instr_fork(t_shell *shell, char *tkn, int end);
int	ft_execute_instr_no_fork(t_shell *shell, char *tkn);
int	ft_redirect_or_pipe(t_shell *shell, char *tkn, int fd_in);
void	ft_execute_instr_fork_2(t_shell *shell);

/*
** execute_pipe.c
*/
int	ft_final_exec_pipe(t_shell *shell,
			   int pid,
			   int tube[2],
			   char *tkn);
void	ft_execute_instr_fork_pipe(t_shell *shell, int tube[2]);

/*
** choose_type_execution.c
*/
int	ft_choose_type_execution(t_shell *shell, char *tkn, int end);
int	ft_is_a_build_in(char *cmd);

/*
** redirection.c
*/
void	ft_write_at_end(char *file);
void	ft_rewrite(char *file);
void	ft_inredirect(char *file, int fd_in);
void	ft_double_inredirect(char *file);

/*
** check_input.c
*/
int	ft_check_input(char *line);
int	ft_look_dot(char **tab, int i);
int	ft_look_and(char **tab, int i);
int	ft_look_or(char **tab, int i);
int	ft_look_bad_tkn(char *word, char *tkn);

/*
** check_input2.c
*/
int	ft_check_redirect(char **tab, int i);
int	ft_check_input_redirect(char **tab, int i);


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
char	*get_env(t_shell *shell, char *var);

/*
** END ----- LAUNCH / CHECK/ SHELL ----- END
*/

/*
** check_options.c
*/
void	check_options(int ac, char **av, t_shell *shell);
void	exec_simple_cmd(char *line, t_shell *shell);
void	print_usage();

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
int	is_const_string(char *line, int check);
char	**epur_tab(char **tab);
char	**split_no_const(char *line, char *tokens);
int	is_in_const(char *line, int pos);
char 	**add_string(char **tab, char *str);
char	*replace_glob(char *line);

/*
** build_alias
*/

int	ft_alias(t_shell *shell);
void	print_alias(t_alias *alias);
int	check_alias(char **lexed);
void    show_this_alias(char *search, t_alias *alias);
int	ft_unalias(t_shell *shell);
void	ft_norme_unalias(t_alias *tmp, char **tab);

/*
** START ------ HISTORY -------- END
*/

void	append_history(char *value, t_shell *shell);

/*
** END ------- HISTORY --------- END
*/

char	**autocomplete(char *begin, char *path, int check);
int	is_sep(char *sep);

#endif /*!SHELL_H_*/
