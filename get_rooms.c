#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

char is_command(char *s)
{
    s = ft_strtrim(s);
    if (!ft_strcmp("##start", s ) ) {
      return 'S';
    }
    if (!ft_strcmp("##end", s ) ) {
      return 'E';
    }
      return 'N';
}

int is_comment_room(char *c)
{
  c = ft_strtrim(c);
  if(ft_strlen(c) == 0 || c[0] == '\n' || c[0] == '\0')
      return (1);
  if(c[0] == '#' && c[1] == '\0' )
      return (1);
  if(c[0] == '#' && c[1] == '#' && c[2] == '\0' )
      return (1);
  if(!ft_strcmp(c ,"##start") || !ft_strcmp("##end", c))
  {
    return (0);
  }
  if(c[0] == '#' )
      return (1);
  return (0);
}

int all_digits(char *str)
{
  int i;

  i = 0;
  if(str[0] == '-')
  i++;
  while (str[i] != '\0') {

    if (!ft_isdigit(str[i])) {

      return (0);
    }
    i++;
  }
  return (1);
}

int get_len(char **str)
{
  int i;

  i = 0;
  while (str[i] != NULL) {
    i++;
  }
  return (i);
}

int check_patern_links(char *str)
{
  char **array;

  array = ft_strsplit(str, '-');
  if (get_len(array) == 2 ) {
    if(!all_digits(array[1]) && !all_digits(array[0]))
    {
        return (1);

    }
  }
  return (0);
}

char check_patern_room(char *str)
{
  char **array;
  array = ft_strsplit(str, ' ');
  if(get_len(array) == 3)
  {
    if(array[0][0] == 'L' || array[0][0] == 'l')
    {
      ft_printf("THIS IS CATCHED  ROOM%s\n", str);
      exit(0);
    }
    if (all_digits(array[1]) && (all_digits(array[2]))) {

        return ('R');
    }
  }
  else{
    if(get_len(array) == 1)
    {
      if(check_patern_links(str))
        {
          return ('L');
        }
    }
  }
if(is_command(str) == 'E' || is_command(str) == 'S')
    return ('F');
if(is_comment_room(str))
  return ('C');
  return 'D';
}


s_room create_room(char *str)
{
  char **arg;
  arg = ft_strsplit(str, ' ');
  struct s_room *new_room;
      new_room = (s_room*)malloc(sizeof(s_room));
      new_room->name = (char*)malloc((sizeof(char) * (ft_strlen(arg[0])) + 1));

      new_room->name = arg[0];
      new_room->x  = ft_atoi(arg[1]);
      new_room->y = ft_atoi(arg[2]);
      new_room->setlink = 0;


  return *new_room;
}



void get_the_rooms()
{
    char *temp;
    struct s_room room[10000];
    struct s_link *link;
    link = (s_link*)malloc(sizeof(s_link) * 10000);

    int i = 0;
    char **arg;

    number_of_rooms = 0;
      number_of_links = 0;
    while (get_next_line(0, &temp) == 1)
    {
      if (!is_comment_room(temp)) {
        if(check_patern_room(temp) == 'R')
        {
          ft_printf("Save RoomS%s\n", temp);
          room[number_of_rooms] = create_room(temp);

          ft_printf("Name%s\n", room[number_of_rooms].name);
          ft_printf("X >>%d\n", room[number_of_rooms].x);
          ft_printf("Y >>%d\n", room[number_of_rooms].y);
          number_of_rooms++;
        }
        if(check_patern_room(temp) == 'L')
        {
          arg = ft_strsplit(ft_strtrim(temp),'-');
          link[i].name_s = (char*)malloc((sizeof(char) * (ft_strlen(arg[0])) + 1));
          link[i].name_d = (char*)malloc((sizeof(char) * (ft_strlen(arg[1])) + 1));
          link[i].name_s = ft_strcpy(link[i].name_s, arg[0]);
          link[i].name_d = ft_strcpy(link[i].name_d, arg[1]);
          number_of_links++;
          i++;
        }

        if(check_patern_room(temp) == 'D')
        {
            ft_printf("\n>>>>>%c>>>>>%s\n", check_patern_room(temp), temp);
            exit(0);
        }
      }

    }
     set_the_links(room, link);
}
