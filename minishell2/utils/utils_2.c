/*
** utils_2.c for  in /home/stanislas/PSU_2015_minishell2
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Thu Apr  7 18:37:01 2016 CUENAT
** Last update Thu Apr  7 18:38:16 2016 CUENAT
*/

#include "include.h"

char	**ft_cmd_tab(char *cut_instr, char **bin_path)
{
  char	*cmd;
  char	**cmd_exec;
  int	i;
  int	j;

  i = 0;
  while (cut_instr[i] && cut_instr[i] != ' ')
    i++;
  cmd = ft_itoj_strcpy(0, i, cut_instr);
  j = i + 1;
  i = 0;
  while (bin_path[i] != NULL && (ft_get_path(bin_path[i], cmd) == NULL))
      i++;
  if (bin_path[i] != NULL)
    cmd_exec = ft_add_cmd_tab(ft_get_path(bin_path[i], cmd), cut_instr, j);
  else
    cmd_exec = ft_add_cmd_tab(cmd, cut_instr, j);
  return (cmd_exec);
}

char	**ft_malloc_tab_instr(char *str)
{
  char  **tab_instr;
  int   tab_y;
  int   i;

  i = 0;
  tab_y = 2;
  while (str[i])
    {
      if (str[i] == '|' || str[i] == '<' || str[i] == '>')
	tab_y += 2;
      i++;
    }
  if ((tab_instr = malloc(sizeof(char *) * (tab_y + 1))) == NULL)
    exit(EXIT_FAILURE);
  return (tab_instr);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      write(1, &str[i], 1);
      i++;
    }
}

char	*ft_malloc_epur(char *str)
{
  int	i;
  int	j;
  char	*epur;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while ((str[i + 1] == ' ' || str[i + 1] == '\t') && str[i])
	    {
	      i++;
	      j++;
	    }
	}
      i++;
    }
  if ((epur = malloc(sizeof(char) * (i - j + 1))) == NULL)
    exit(EXIT_FAILURE);
  return (epur);
}

char	*ft_epur_str(char *str)
{
  int	i;
  int	j;
  char	*epur;

  epur = ft_malloc_epur(str);
  j = 0;
  i = 0;
  while (str[i] && (str[i] == ' ' || str[i] == '\t'))
    i++;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t')
	{
	  while ((str[i + 1] == ' ' || str[i + 1] == '\t') && str[i + 1])
	    i++;
	  if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] == '\0')
	    i++;
	}
      if (str[i] != '\0')
	epur[j++] = str[i++];
    }
  epur[j] = '\0';
  free(str);
  return (epur);
}
