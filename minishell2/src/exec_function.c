/*
** exec_function.c for  in /home/stanislas/PSU_2015_minishell2/src
**
** Made by CUENAT
** Login   <stanislas@epitech.net>
**
** Started on  Wed Mar 30 13:19:58 2016 CUENAT
** Last update Mon May 23 16:54:51 2016 CUENAT
*/

#include "include.h"

int	ft_launch_instr(char **instr, t_shell *shell)
{
  int	i;
  int	old_fd;

  i = 0;
  old_fd = 0;
  while (instr[i] != NULL)
    {
      instr[i] = ft_epur_str(instr[i]);
      printf("%s\n",instr[i]);
      shell->cmd = ft_cmd_tab(instr[i], shell->bin_path);
      if (ft_exec_build(shell) == -1)
	old_fd = ft_exec_pipe(shell, old_fd, i, instr);
      (instr[i + 1] != NULL) ? (i += 2) : (i++);
    }
  ft_free_tab(shell->cmd);
  return (0);
}

char	**ft_instr_to_tab_2(char *str, int *i, int k, char **tab_instr)
{
  if (str[*i] == '|')
    {
      (!(tab_instr[k] = malloc(sizeof(char) * 2))) ? (exit(-1)) : 0;
      tab_instr[k][0] = '|';
      tab_instr[k][1] = '\0';
    }
  else if ((str[*i] == '<' && str[*i + 1] == '<')
	   || (str[*i] == '>' && str[*i + 1] == '>'))
    {
      (!(tab_instr[k] = malloc(sizeof(char) * 3))) ? (exit(-1)) : 0;
      tab_instr[k][0] = str[*i];
      tab_instr[k][1] = str[*i];
      tab_instr[k][2] = '\0';
      (*i)++;
    }
  else
    {
      (!(tab_instr[k] = malloc(sizeof(char) * 2))) ? (exit(-1)) : 0;
      tab_instr[k][0] = str[*i];
      tab_instr[k][1] = '\0';
    }
  (*i)++;
  return (tab_instr);
}

char	**ft_instr_to_tab(char *str)
{
  char	**tab_instr;
  int	i;
  int	j;
  int	k;

  i = 0;
  k = 0;
  tab_instr = ft_malloc_tab_instr(str);
  while (str[i])
    {
      if (str[i] == '|' || str[i] == '<' || str[i] == '>')
	tab_instr = ft_instr_to_tab_2(str, &i, k, tab_instr);
      else
	{
	  j = i;
	  while (str[i] != '|' && str[i] != '<' && str[i] != '>' && str[i])
	    i++;
	  tab_instr[k] = ft_itoj_strcpy(j, i, str);
	}
      k++;
    }
  tab_instr[k] = NULL;
  return (tab_instr);
}

void	ft_exec(t_shell *shell, t_list *list)
{
  char	**instr;

  while (list != NULL)
    {
      instr = ft_instr_to_tab(list->binary);
      ft_launch_instr(instr, shell);
      ft_free_tab(instr);
      list = list->next;
    }
}
