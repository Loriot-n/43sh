/*
** autocomplete.c for 42sh in /home/qwebify/rendu/PSU/
**
** Made by maire_q
** Login   <maire_q@epitech.eu>
**
** Started on  %cdate maire_q
** Last update %udate maire_q
*/

#include "include.h"
#define FORMAT "%s\n"

typedef struct dirent t_dir;
typedef struct stat t_stat;

char	**autocomplete(char *begin, char *path, int check)
{
  DIR 		*dir;
  t_dir		*ent;
  char		*one;
  char		**answer;
  int		j;

  j = 0;
  answer = NULL;
  while ((one = strsep(&path, ":")) && (dir = opendir(one)))
    {
	while ((ent = readdir(dir)) != NULL)
	{
	  if (strstr(ent->d_name, begin) && ent->d_type == check)
	  (answer = realloc(answer, j * sizeof(char *) + sizeof(char *) * 2)) ?
	      answer[j++] = strdup(ent->d_name) : exit(EXIT_FAILURE);
	}
      closedir (dir);
    }
  if (answer)
    answer[j] = NULL;
  return (answer);
}

char	**get_aliases(char *path)
{
  return (NULL);
}

int	main(int ac, char **av)
{
  char	**alias = get_aliases("42shrc");

  for (int i = 0; alias[i]; i++)
    {
      printf("%s\n", alias[i]);
      free(alias[i]);
    }
}


// int	main(int ac, char **argv)
// {
//   int	i = 0;
//   char **answer = autocomplete(argv[1], argv[2], DT_REG);
//   char	*toto = "%s\n";
//   #define str(s) #s
//
//   while (answer && answer[i])
//     {
//       printf("%s\n", answer[i]);
//       free(answer[i]);
//       i++;
//     }
//   free(answer);
//   (void)ac;
//   return (0);
// }
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
