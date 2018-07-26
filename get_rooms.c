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

void mark_the_path(s_room *room)
{
  int k;
  k = 0;
ft_printf("Calea %s  ||| %d %dtype %c :: %c\n",room->name, room->level,room->setlink, room->type, room->ispassed);
  while (k < room->setlink)
  {
    if (room->type == 'E') {

      ft_printf("URA  %s  ||| %d\n",room->name, room->level);
      break;
    }
    if (room->array_of_rooms[k]->ispassed == 'D' && room->level + 1 == room->array_of_rooms[k]->level) {
      ft_printf(">>%d\n",k);
      mark_the_path(room->array_of_rooms[k]);
    break;
    }
    k++;
  }
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
int	ft_contain(char *str, char c)
{
	char *s;

	s = (char *)str;
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
		return (0);
}


int check_patern_links(char *str)
{
  char **array;
  char a;

  str = ft_strtrim(str);
;
  a = str[ft_strlen(str) - 1];
  if(ft_contain(str,'-') && (str[0] != '-') && (a != '-'))
      return (1);
  else
      return (0);

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

  if(is_command(str) == 'E' || is_command(str) == 'S')
      return ('F');
  if(is_comment_room(str))
    return ('C');
    if(ft_contain(str, ' ') )
{
  array = ft_strsplit(str, ' ');
    ft_printf("THIS IS CATCHED  ROOM%s\n", str);
  if(get_len(array) == 3)
  {
      ft_printf("THIS IS error%s\n", str);
    if(array[0][0] == 'L' || array[0][0] == 'l')
    {
      ft_printf("THIS IS CATCHED  ROOM%s\n", str);
      exit(0);
    }
    if (all_digits(array[1]) && (all_digits(array[2]))) {

        return ('R');
    }
  }
}
  else{

      if(check_patern_links(str))
        {
          return ('L');
        }

  }
  return 'D';
}


s_room create_room(char *str, char type)
{
  char **arg;
  arg = ft_strsplit(str, ' ');
  struct s_room *new_room;
      new_room = (s_room*)malloc(sizeof(s_room));
      new_room->name = (char*)malloc((sizeof(char) * (ft_strlen(arg[0])) + 1));

      new_room->name = arg[0];
      new_room->x = ft_atoi(arg[1]);
      new_room->y = ft_atoi(arg[2]);
      new_room->setlink = 0;
      new_room->type = type;
      new_room->ispassed = 'N';
      new_room->level = 0;



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
    char type = 'N';

      number_of_rooms = 0;
      number_of_links = 0;
    while (get_next_line(0, &temp) == 1)
    {

      if (!is_comment_room(temp)) {

        if(check_patern_room(temp) == 'R')
        {
          ft_printf("Save RoomS%s\n", temp);
          room[number_of_rooms] = create_room(temp, type);

          ft_printf("Name%s\n", room[number_of_rooms].name);
          ft_printf("X >>%d\n", room[number_of_rooms].x);
          ft_printf("Y >>%d\n", room[number_of_rooms].y);
          number_of_rooms++;
        }
          type = is_command(temp);
        if(check_patern_room(temp) == 'L')
        {

            /* code */

          arg = ft_strsplit(ft_strtrim(temp),'-');
            if (ft_strcmp(arg[0], arg[1])) {
          link[i].name_s = (char*)malloc((sizeof(char) * (ft_strlen(arg[0])) + 1));
          link[i].name_d = (char*)malloc((sizeof(char) * (ft_strlen(arg[1])) + 1));
          link[i].name_s = ft_strcpy(link[i].name_s, arg[0]);
          link[i].name_d = ft_strcpy(link[i].name_d, arg[1]);
          number_of_links++;
          i++;
        }
        }

        if(check_patern_room(temp) == 'D')
        {
            ft_printf("\n>>>>>%c>>>>>%s\n", check_patern_room(temp), temp);
            exit(0);
        }
      }

    }
    //  set_the_links(room, link);
     s_room *ro = set_the_links(room, link);
    int *arr;

     arr = count_links_per_state(ro, link);
     //print_rooms(ro, arr);

    set_level(ro);
    // mark_the_path(&ro[0]);
     ft_printf("Save RoomS\n");

     print_rooms(ro, arr);
}
