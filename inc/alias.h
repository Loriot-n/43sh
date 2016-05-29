/*
** alias.h for 42sh in /home/qwebify/rendu/PSU/PSU_2015_42sh/inc/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#ifndef ALIAS_H_
# define ALIAS_H_


typedef struct 		s_alias
{
  char			*cmd;
  char			*alias;
  struct s_alias	*next;
}			t_alias;

/*
** START ----- ALIAS ----- START
*/
/*
** alias_list.c
*/
t_alias		*get_aliases(int fd);
t_alias		*insert_alias(char **cmd, char *alias, t_alias **head);
char		*replace_alias(t_alias *alias_list, char *cmd);
void		free_alias(t_alias *alias);

#endif /* !ALIAS_H_ */
