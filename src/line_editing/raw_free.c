/*
** raw_free.c for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/src
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Tue May 31 21:01:57 2016 Nicolas Loriot
** Last update Tue May 31 21:05:16 2016 Nicolas Loriot
*/

#include "arrows.h"
#include "shell.h"

void		raw_free(t_raw *raw)
{
  free(raw->line->input->buffer);
  free(raw->line->input);
  free(raw->line->prompt);
  free(raw->line);
  free(raw->term);
  free(raw->buffer);
  free(raw->to_return);
  raw->safe = 0;
  free(raw);
}
