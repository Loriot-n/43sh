/*
** arrows.h for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/inc
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Thu May 26 17:19:15 2016 Nicolas Loriot
** Last update Mon May 30 18:53:35 2016 Nicolas Loriot
*/

#ifndef ARROWS_H_
# define ARROWS_H_

# include <ncurses.h>
# include <stropts.h>
# include <sys/ioctl.h>
# include <term.h>
# undef tab
# include <termios.h>

typedef struct		s_str
{
  char			*buffer;
  int			len;
}			t_str;

typedef struct		s_line
{
  t_str			*input;
  t_str			*prompt;
  int			oldcursor;
  int			cursor;
}			t_line;

typedef struct		s_term
{
  int			fd;
  int			mode;
  struct termios	origin;
}			t_term;

typedef struct		s_hist
{
  char			**history;
  char			*original;
  char			*buffer;
  int			len;
  int			max;
  int			index;
}			t_hist;

typedef struct		s_raw
{
  t_line		*line;
  t_term		*term;
  t_hist		*history;
  char			*to_return;
  char			*buffer;
}			t_raw;

typedef enum		s_status
{
  SUCCESS,
  ERROR,
  BELL
}			t_status;

# define C_BELL			"\x7"
# define C_LN_CLEAR_END		"\x1b[0K"
# define C_CUR_MOVE_FORWARD	"\x1b[%dC"
# define C_CUR_MOVE_BACK	"\x1b[%dD"

void		read_mode(t_raw *raw, int state);
void		*raw_alloc(size_t size);
void		*raw_realloc(void *oldptr, size_t size);
char		*raw_strdup(char *src);
void		set_line(t_raw *raw, char *str, int cursor);
int		*insert_char(t_raw *raw, char ch);

/*
** CASE_HANDLING, merci la norme epitech <3
*/

void		end_of_text(t_raw *raw, int *err, int *enter);
void		end_of_file(t_raw *raw, int *err, int *enter);

#endif /* !ARROWS_H_  */
