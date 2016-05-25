/*
** my_getnbr.c for my_getnbr.c in /home/cuenat_s/rendu/Piscine_C_J04
** 
** Made by stanislas cuenat
** Login   <cuenat_s@epitech.net>
** 
** Started on  Thu Oct  1 21:53:43 2015 stanislas cuenat
** Last update Sun Jan 24 20:22:10 2016 stanislas cuenat
*/

void	my_verif(char *str, int i, long int *ret)
{
  if (i > 0 && str[i - 1] == '-' && str[i + 1] > 47 && str[i + 1] < 58)
    *ret = -*ret;
}

void	my_increment(long *ret, char *str, int i)
{
  if (*ret >= 0)
    *ret= *ret * 10 + (str[i] - 48);
  else
    *ret = *ret * 10 - (str[i] - 48);
}

int		my_getnbr(char *str)
{
  int		i;
  long  int	ret;
  int		chk;

  i = 0;
  ret = 0;
  chk = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 48 && str[i] <= 57)
	{
	  my_increment(&ret, str, i);
	  chk = chk + 1;
	  if (chk >= 11)
	    return (0);
	}
      my_verif(str, i, &ret);
      if (ret > 2147483647 || ret < (-2147483648))
        return (0);
      if (chk > 0 && (str[i] < 48 || str[i] > 57))
	  return (ret);
      i = i + 1;
    }
  return (ret);
}
