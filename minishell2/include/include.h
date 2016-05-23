
/*
** include.h for  in /home/stanislas/PSU_2015_minishell2/include
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Tue Mar 29 10:19:29 2016 CUENAT
** Last update Fri Apr  8 15:10:59 2016 CUENAT
*/

#ifndef INCLUDE_H_
# define INCLUDE_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <limits.h>

 #ifndef PROMPT
 # define PROMPT "$>"
 #endif

typedef struct	s_shell
{
  char		**env;
  char		**bin_path;
  char		**cmd;
}		t_shell;

typedef struct	s_list
{
  char		*binary;
  struct s_list	*next;
}		t_list;

/*
** utils/utils_1.c
*/
int	my_strlen(char *str);
int	my_strlen_tab(char **str);
char	*my_strdup(char *str);
void	ft_free_tab(char **tab);

/*
** utils/utils_2.c
*/
char	**ft_malloc_tab_instr(char *str);
char	*ft_malloc_epur(char *str);
char	*ft_epur_str(char *str);
char	**ft_cmd_tab(char *cut_instr, char **bin_path);
void	my_putstr(char *str);

/*
** utils/utils_3.c
*/
char	*ft_get_path(char *bin_path, char *cmd);
char	**ft_add_cmd_tab(char *path, char *cut_instr, int start);
char	**ft_add_on_env(t_shell *shell);
int	my_strcmp(char *str1, char *str2);
char	*ft_strcat(char *str1, char *str2);

/*
** utils/get_next_line.c
*/
int	mlen(char *str);
char	*cpy(char *tmp, char *ret);
char	*my_realloc(char *ret, int oct);
char	*get_next_line(int fd);

/*
** utils/my_getnbr.c
*/
int	my_getnbr(char *str);

/*
** src/env_function.c
*/
char	**my_str_to_word_tab(char **tab, char *str);
char	**ft_find_bin_path(char **env);
char	**ft_get_bin_path(char *env);
char	**ft_copy_env(char **environ);
int	ft_find_in_env(char *env, char *cmp);

/*
** src/main.c
*/
void	ft_free_all(t_shell *shell);
t_shell	*ft_init_shell(char **environ);
void	ft_getch_instr(t_shell *shell);
void	ctrl(int sig);
/*
** src/list_function.c
*/
t_list	*ft_parse_instr(t_list *list, char *instr);
t_list	*ft_add_at_end_list(char *str, t_list *list);
t_list	*ft_free_list(t_list *list);
char	*ft_itoj_strcpy(int i, int j, char *str);

/*
** src/exec_build_in.c
*/
void	ft_exit(t_shell *shell);
void	ft_cd(t_shell *shell);
void	ft_env(t_shell *shell);
void	ft_setenv(t_shell *shell);
void	ft_unsetenv(t_shell *shell);
/*
** src/exec_function.c
*/
char	**ft_instr_to_tab(char *str);
void	ft_exec(t_shell *shell, t_list *list);

/*
** src/exec_and_redirect.c
*/
int     ft_exec_pipe(t_shell *shell, int old_fd, int i, char **instr);
void    ft_exec_or_redirect(t_shell *shell,
			    char **instr,
			    int i,
			    int old_fd);
void    ft_write_at_end(char **instr,
			int i,
			int old_fd);
void    ft_rewrite(char **instr,
		   int i,
		   int old_fd);
int     ft_exec_build(t_shell *shell);


/*
** src/check_input.c
*/
int	ft_check_syntax_errors(char *str);
int	ft_check_syntax_errors_1(char *str, int i, int bol);
int	ft_check_syntax_errors_2(char *str, int i, int bol);

/*
** src/signal.c
*/
void	ctrl(int sig);
void	segfault(int sig);

/*
** src/exec_cd.c
*/
int	ft_simple_cd(t_shell *shell);
int	ft_cd_oldpwd(char *oldpwd);
int	ft_cd_at_home(t_shell *shell);
void	ft_cd(t_shell *shell);

#endif
