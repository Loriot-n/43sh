/*
** input_signals.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Mon May 30 19:16:31 2016 Nicolas Loriot
** Last update Tue May 31 16:08:05 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

int		end_of_text(t_raw *raw, char *ch, int *enter, int *move)
{
  *enter = 1;
  return (SUCCESS);
}

int		end_of_file(t_raw *raw, char *ch, int *enter, int *move)
{
  read_mode(raw, 0);
  printf("exit");
  putchar(10);
  exit(0);
  return (SUCCESS);
}

int		tabulation(t_raw *raw, char *ch, int *enter, int *move)
{
  char		*line;
  char		**pros;
  char		*tmp;

  line = strdup(raw->line->input->buffer);
  tmp = strdup(get_env(g_shell, "PATH"));
  if (!tmp)
    tmp = strdup("/bin");
  pros = autocomplete(line, tmp, DT_REG);
  *move = 0;
  if (!pros || !pros[0])
    return (BELL);
  free(tmp);
  set_line(raw, pros[0], strlen(pros[0]));
  tmp = raw->line->input->buffer;
  raw->line->input->buffer = strdup(pros[0]);
  free(tmp);
  return (BELL);
}

int		carriage_ret(t_raw *raw, char *ch, int *enter, int *move)
{
  *enter = 1;
  return (SUCCESS);
}

int		backspace(t_raw *raw, char *ch, int *enter, int *move)
{
  *move = 0;
  return (backspace_char(raw));
}
