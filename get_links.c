#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

int is_repeated(s_room rooms, char *str)
{
  int i;

  i = 0;
  while(rooms.array_of_rooms[i] != '\0')
  {
      ft_printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
    if(ft_strcmp(str, rooms.array_of_rooms[i]->name) == 0)
    {
      ft_printf("this is is_repeated\n");
        return (0);
    }
    i++;
  }
  ft_printf("ok -- exit\n");
  return (1);
}




int* count_links_per_state(s_room *rooms, s_link *links)
{
  int *arr = (int*)malloc(sizeof(int) * number_of_rooms);
  int i = 0;
  int j = 0;


  while(i < number_of_rooms)
  {

    arr[i] = 0;
    j = 0;
    while(j < number_of_links)
    {

      if(ft_strcmp(rooms[i].name, links[j].name_d) == 0 || ft_strcmp(rooms[i].name, links[j].name_s) == 0)
      {
        ft_printf(">>>>%s <<%s  || %s  numar %d\n",rooms[i].name ,links[j].name_s,  links[j].name_d , i + 1);
        arr[i]++;
      }
      j++;
    }
    i++;
  }
  return arr;
}

int get_the_rooms_by_name(s_room *rooms, char *name)
{
      int i;

      i = 0;
      while (i < number_of_rooms)
      {
          if(ft_strcmp(rooms[i].name, name) == 0)
          return (i);
          i++;
      }
      ft_printf("DOOM\n");
      exit(0);

}


void print_rooms(s_room *rooms)
{
  int i;
  int j;

  i = 0;
  while(i < number_of_rooms)
  {
    ft_printf("--------------------------\n");
    ft_printf("the name %s | %d\n", rooms[i].name, rooms[i].setlink);
    j = 0;
    while (rooms[i].array_of_rooms[j] != '\0' && rooms[i].setlink > j) {
      /* code */
     ft_printf("***%s\n", rooms[i].array_of_rooms[j]->name);
      j++;
    }
    i++;
  }
}

  s_room* set_the_links(s_room *rooms, s_link *links)
  {

    int i = 0;
    int j = 0;
    int *arr;

    arr = count_links_per_state(rooms, links);

    while (i < number_of_rooms) {
      ft_printf(">>>>>>%d\n", arr[i]);

      i++;
    }
    i =0;
    while(i  < number_of_rooms)
    {

      rooms[i].ord = i;
      rooms[i].array_of_rooms = (s_room**)malloc(sizeof(s_room*) * arr[i]);

      i++;
    }
      j = 0;
      int a = 0;
      int b = 0;
    while (j < number_of_links)
    {
        a = get_the_rooms_by_name(rooms, links[j].name_s);
        b = get_the_rooms_by_name(rooms, links[j].name_d);

if (is_repeated(rooms[a], rooms[b].name))
 {
  rooms[a].array_of_rooms[rooms[a].setlink] = &rooms[b];
  rooms[b].array_of_rooms[rooms[b].setlink] = &rooms[a];
  rooms[a].setlink = rooms[a].setlink + 1;
  rooms[b].setlink = rooms[b].setlink + 1;

  }
    j++;

    ft_printf("%d , %d \n", a + 1 , b + 1);
    }
    print_rooms(rooms);
    return rooms;
  }
