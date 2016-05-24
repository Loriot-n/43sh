#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#define READ_SIZE 5

char	*epur_str(char *str);
char **clean_split(char **tab, char *save, int j, char *str);
char	*copy_line(char *tab, char *str, int i);
void	*raoul(char *oldptr, int size);
char	*add_char(char *str, char new);
char	**split(char *str, char cut);
