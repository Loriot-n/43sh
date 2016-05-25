#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#define READ_SIZE 5

typedef struct 		s_alias
{
  char			*cmd;
  char			*alias;
  struct s_alias	*next;
}			t_alias;


char	*epur_str(char *str);
char **clean_split(char **tab, char *save, int j, char *str);
char	*copy_line(char *tab, char *str, int i);
void	*raoul(char *oldptr, int size);
char	*add_char(char *str, char new);
char	**split(char *str, char *tokens);
char	*get_next_line(const int fd);
t_alias	*get_aliases(char *path);
char	*epur(char *str);
size_t		tab_len(char **tab);
