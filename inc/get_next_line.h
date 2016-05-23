/*
** get_next_line.h for gnl in /home/nico/rendu/S01/ProgElem/CPE_2015_getnextline/
**
** Made by Nicolas Loriot
** Login   <loriot_n@epitech.net>
**
** Started on  Mon Jan  4 14:17:42 2016 Nicolas Loriot
** Last update Tue Apr 12 11:58:47 2016 Nicolas Loriot
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef READ_SIZE
#  define READ_SIZE (99)
# endif /* !READ_SIZE */

char	*get_next_line(const int fd);
int	my_strlen(char *str);
char	*my_strcpy(char *dest, char *src);
char	*my_realloc(char *buff, int ctr);
void	my_putstr(char *str);
void	my_putchar(char c);

#endif /* !GET_NEXT_LINE_H */
