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
  char		**pros;
  char		**tmp;
  char		*path;

  if (!raw->line->input->buffer)
    return (BELL);
  tmp = split(raw->beg, " ;&|");
  path = strdup(".");
  if (tab_len(tmp) == 1)
    path = get_env(g_shell, "PATH");
  pros = autocomplete(tmp[tab_len(tmp) - 1], path, DT_REG);
  if (!pros)
    return (BELL);
  (raw->complete - 1 >=  tab_len(pros)) ? raw->complete = 1 : 0;
  tmp[tab_len(tmp) - 1] = strdup(pros[raw->complete - 1]);
  raw->line->input->buffer = epur(tab_join(' ', tmp));
  raw->line->input->len = strlen(raw->line->input->buffer);
  raw->line->cursor = strlen(raw->line->input->buffer);
  return (SUCCESS);
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
