#include <stdio.h>
#include <stdlib.h>
#include "gnl.h"

int	main()
{
  char	*s;

  while (s = get_next_line(0))
    {
      printf("Line : [%s]\n", s);
      free(s);
    }
  return (0);
}
