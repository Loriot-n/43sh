/*
** alias.h for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/inc/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update Fri Jun  3 10:53:47 2016 Sanchez Loris
*/

#ifndef ALIAS_H_
# define ALIAS_H_
# include "shell_struct.h"

typedef struct 		s_alias
{
  char			*cmd;
  char			*alias;
  int			whatdo;
  struct s_alias	*next;
}			t_alias;

/*
** START ----- ALIAS ----- START
*/
/*
** alias_list.c
*/
t_alias		*get_aliases(t_shell *shell, char **tab);
t_alias		*insert_alias(char *replace, char *remplace_by, t_alias **head,
			      int whatdo);
char		*replace_alias(t_alias *alias_list, char *cmd);
void		free_alias(t_alias *alias);

#endif /* !ALIAS_H_ */
