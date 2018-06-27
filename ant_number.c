#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"

int is_comment(char *c)
{
  // retur 0 if is false
  if(ft_strlen(c) == 0)
      return (1);
  if(c[0] == '#' && c[1] == '\0' )
      return (1);
  if(c[0] == '#' && c[1] == '#' && c[2] == '\0' )
      return (1);
  if(c[0] == '#' && c[1] == '#' && c[2] == '#' )
      return (1);
  c = ft_strtrim(c);
  if(!ft_strcmp(c ,"##start") || !ft_strcmp("##end", c))
  {
    ft_printf("Here commands are not permited %s\n", c);
    exit(0);
  }
  if(c[0] == '#' )
      return (1);
  return 0;
}

int check_patern(char *str)
{
  int len = ft_strlen(str);
  int i = 0;
  while ((str[i] == ' ' || str[i] == '\t') && (i <= len)){
    i++;
  }
  if(i == len)
  {
    return 0;
  }
  while (str[i] != '\0' && !(str[i] == ' ' || str[i] == '\t') &&  i <= len) {
      if (ft_isdigit(str[i])) {
        }
        else
        {
          if(str[i] == '\0')
            return (1);
          ft_printf("The DOOM %s\n", str);
          exit(0);
        }
        if(str[i] == '\0')
          return (1);
        i++;
        }
        return 1;
}

int get_the_ant_number()
{
    int NUMBER = 0;
    char *temp;

    while (get_next_line(0, &temp) == 1)
    {
      if (!is_comment(temp)) {
        /* code */
        ft_printf("%s&&&&&\n",temp );
        if(check_patern(temp))
        {
          NUMBER = ft_atoi(temp);
          return NUMBER;
        }
        else
        {
          ft_printf("DOOM Return fail");
          exit(0);
        }
      }
    }
    ft_printf("DOOM Exit\n");
    exit(0);
}
