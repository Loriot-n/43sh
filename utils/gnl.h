/*
** get_next_line - Aymeric - Avril 2016
** 
** char *get_next_line(int fd);
** fd : file descriptor to read (max : 64 fd)
** return values : buffer with only one line. NULL if nothing to read or error
**
** just for testing only
** project with this get_next_line => -42
**
*/

#ifndef		__GNL_AF__
#define		__GNL_AF__

char *get_next_line(int fd);

#endif
