/*
** raw_string.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Mon May 30 15:20:40 2016 Nicolas Loriot
** Last update Mon May 30 18:48:35 2016 Nicolas Loriot
*/

#include "shell.h"
#include "arrows.h"

char		*raw_strdup(char *src)
{
  int		len;
  char		*ret;

  if (!src)
    return (NULL);
  len = strlen(src);
  ret = raw_alloc(len + 1);
  memcpy(ret, src, len);
  ret[len] = 0;
  return (ret);
}

void		set_line(t_raw *raw, char *str, int cursor)
{
  int		len;

  len = strlen(str);
  raw->line->input->buffer = raw_realloc(raw->line->input->buffer, len + 1);
  memcpy(raw->line->input->buffer, str, len);
  raw->line->input->buffer[len] = 0;
  raw->line->input->len = len;
  raw->line->cursor = cursor;
  if (raw->line->cursor < 0 || raw->line->cursor > len)
    raw->line->cursor;
}

int		*insert_char(t_raw *raw, char ch)
{
  int		len;
  int		cur;
  char		*tmp;

  cur = raw->line->cursor;
  len = raw->line->input->len;
  raw->line->input->len++;
  tmp = raw_alloc(len + 1);
  memcpy(tmp, raw->line->input->buffer, cur);
  tmp[cur] = ch;
  memcpy(tmp + cur + 1, raw->line->input->buffer + cur, len - cur - 1);
  tmp[len] = 0;
  raw->line->input->buffer = raw_realloc(raw->line->input->buffer, len + 1);
  memcpy(raw->line->input->buffer, tmp, len + 1);
  free(tmp);
  raw->line->cursor++;
  return (SUCCESS);
}

int		del_char(t_raw *raw)
{
  int		cur;
  char		*cpy;
  int		len;

  if (raw->line->cursor >= raw->line->input->len && raw->line->cursor > 0)
    raw->line->cursor--;
  if (!raw->line->input->len || raw->line->cursor >= raw->line->input->len)
    return (BELL);
  raw->line->input->len--;
  cur = raw->line->cursor;
  len = raw->line->input->len;
  cpy = raw_alloc(len + 1);
  memcpy(cpy, raw->line->input->buffer, cur);
  memcpy(cpy + cur, raw->line->input->buffer + cur + 1, len - cur);
  cpy[len] = '\0';
  raw->line->input->buffer = raw_realloc(raw->line->input->buffer, len + 1);
  memcpy(raw->line->input->buffer, cpy, len + 1);
  free(cpy);
  if (raw->line->cursor > raw->line->input->len)
    raw->line->cursor = raw->line->input->len;
  return (SUCCESS);
}

int		backspace_char(t_raw *raw)
{
  if (!raw->line->input->len || raw->line->cursor < 1)
    return (BELL);
  raw->line->cursor--;
  return (del_char(raw));
}
