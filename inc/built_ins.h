/*
** built_ins.h for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/inc/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Wed Jun  1 13:17:57 2016 CUENAT
*/

#ifndef BUILT_INS_H_
# define BUILT_INS_H_
#include "shell.h"
/*
** build_exit.c
*/
int	ft_exit(t_shell *shell);

/*
** build_exit.c
*/
int	ft_echo(t_shell *shell);

/*
** build_setenv.c
*/
int	ft_setenv(t_shell *shell);
void	add_env(t_shell *shell, char **cmd);
void	modify_env(t_shell *shell, char **cmd, int pos);

/*
** build_unsetenv.c
*/
int	ft_unsetenv(t_shell *shell);

/*
** build_cd.c
*/
int	ft_cd(t_shell *shell);

/*
** build_env.c
*/
int	ft_env(t_shell *shell);

/*
** build_source.c
*/
int	ft_source(t_shell *shell);

#endif /* !BUILT_INS_H_ */
