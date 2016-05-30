/*
** arrows.h for 42sh in /home/nico/rendu/S02/Unix/PSU_2015_42sh/inc
** 
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
** 
** Started on  Thu May 26 17:19:15 2016 Nicolas Loriot
** Last update Fri May 27 13:02:11 2016 Nicolas Loriot
*/

#ifndef ARROWS_H_
# define ARROWS_H_

#include <ncurses.h>
#include <stropts.h>
#include <sys/ioctl.h>

typedef struct		s_curs
{
  int			x;
  int			y;
}			t_curs;

typedef struct		s_win
{
  WINDOW		*cur;
  t_curs		pos;
}			t_win;

#endif /* !ARROWS_H_  */
