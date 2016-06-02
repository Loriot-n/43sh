/*
** arrows.h for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/inc
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Thu May 26 17:19:15 2016 Nicolas Loriot
** Last update Thu Jun 02 12:27:51 2016 Nicolas Loriot
*/

#ifndef ARROWS_H_
# define ARROWS_H_

# include <ncurses.h>
# include <stropts.h>
# include <sys/ioctl.h>
# include <term.h>
# undef tab
# include <termios.h>
# include <assert.h>

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
  int			nb_line;
  struct termios	origin;
  struct winsize	ws;
}			t_term;

typedef struct		s_hist
{
  char			**tab;
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
  char			*rd;
  int			safe;
  unsigned int		complete;
  char			*beg;
}			t_raw;

typedef enum		s_status
{
  SUCCESS,
  ERROR,
  BELL
}			t_status;

# define C_BELL			"\x7"
# define C_LN_CLEAR_LINE	"\x1b[%dK"
# define C_LN_CLEAR_DISP	"\x1b[%dJ"
# define C_CUR_MOVE_UP		"\x1b[%dA"
# define C_CUR_MOVE_DOWN	"\x1b[%dB"
# define C_CUR_MOVE_FORWARD	"\x1b[%dC"
# define C_CUR_MOVE_BACK	"\x1b[%dD"

char		*get_line(t_raw *raw, char *prompt);
t_raw		*init_raw(char *to_send);
void		get_raw_input(t_raw *raw, t_hist *hist);
void		read_mode(t_raw *raw, int state);
void		input_error(int err);
void		raw_free(t_raw *raw);

/*
** Raw Functions
*/

void		*raw_alloc(size_t size);
void		*raw_realloc(void *oldptr, size_t size);
void		*raw_calloc(size_t nmemb, size_t size);
char		*raw_strdup(char *src);
int		raw_strchr(char *str, char ch);
void		raw_memmove(void *src, void *dest, size_t size);

/*
** Line Editing
*/

void		redraw(t_raw *raw, int change, int arrow);
void		set_line(t_raw *raw, char *str, int cursor);
int		insert_char(t_raw *raw, char ch);
int		del_char(t_raw *raw);
int		backspace_char(t_raw *raw);

/*
**  Pointeurs sur fonctions
*/

int		end_of_text(t_raw *raw, char *ch, int *enter, int *move);
int		end_of_file(t_raw *raw, char *ch, int *enter, int *move);
int		tabulation(t_raw *raw, char *ch, int *enter, int *move);
int		carriage_ret(t_raw *raw, char *ch, int *enter, int *move);
int		backspace(t_raw *raw, char *ch, int *enter, int *move);
int		get_escape(t_raw *raw, char *ch, int *enter, int *move);

/*
** Escape sequence
*/

int		left_arrow(t_raw *raw, char *ch, int *enter, int *move);
int		right_arrow(t_raw *raw, char *ch, int *enter, int *move);
int		down_arrow(t_raw *raw, char *ch, int *enter, int *move);
int		up_arrow(t_raw *raw, char *ch, int *enter, int *move);

/*
** Extended escape sequence
*/

int		get_extended_escape(t_raw *raw, char *ch, char prev_seq, int *move);
int		delete_key(t_raw *raw, char *ch, int *enter, int *move);
int		home_key(t_raw *raw, char *ch, int *enter, int *move);
int		end_key(t_raw *raw, char *ch, int *enter, int *move);

/*
** HISTORY
*/

t_hist		*new_hist(int size);
int		set_hist(t_raw *raw, int set, int size);
int		raw_hist_move(t_raw *raw, int move);
void		hist_add_str(t_raw *raw, char *str);
char		*hist_to_serial(t_raw *raw);
void		free_hist(t_hist *hist);

#endif /* !ARROWS_H_  */
