/*
** autocomplete.c for 42sh in /home/qwebify/rendu/PSU/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "shell.h"

char	**sort_autocomplet(char **tab)
{
  int	check;
  int	i;
  char	*tmp;

  check = 1;
  while (check >= 1)
    {
      i = 0;
      check = 0;
      while (tab && tab[i])
	{
	  if (tab[i + 1] && strlen(tab[i + 1]) < strlen(tab[i]))
	    {
	      check += 1;
	      tmp = tab[i + 1];
	      tab[i + 1] = tab[i];
	      tab[i] = tmp;
	    }
	  i++;
	}
    }
  return (tab);
}

char	**autocomplete(char *begin, char *path, int check)
{
  DIR 		*dir;
  t_dir		*ent;
  char		**one;
  char		**answer;
  int		j;

  j = 0;
  answer = NULL;
  one = split(path, ":");
  while (one && one[j] && (dir = opendir(one[j])))
    {
      while ((ent = readdir(dir)) != NULL)
	{
	  if (strncmp(begin, ent->d_name, strlen(begin)) == 0 &&
	      ent->d_type == check)
	    answer = add_string(answer, ent->d_name);
	}
      j = (one[j + 1]) ? 2 : 1;
      closedir(dir);
    }
  ft_free_tab(one);
  answer = sort_autocomplet(answer);
  return (answer);
}

/*
DT_BLK      This is a block device.

DT_CHR      This is a character device.

DT_DIR      This is a directory.

DT_FIFO     This is a named pipe (FIFO).

DT_LNK      This is a symbolic link.

DT_REG      This is a regular file.

DT_SOCK     This is a UNIX domain socket.

DT_UNKNOWN  The file type could not be determined.
*/
