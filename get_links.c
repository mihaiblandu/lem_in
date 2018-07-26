#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

int is_repeated(s_room room, char *str)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while(i < room.setlink)
  {
    if (ft_strcmp(room.array_of_rooms[i]->name , str) == 0) {
        j++;
      if(j == 2)
        return (1);

    }
    i++;
  }
  return (0);
}

s_room* delete_link(s_room *rooms)
{
int i;
int j;

i = 0;
while (i < number_of_rooms) {
  j = 0;
  while (j < rooms[i].setlink) {
  if(is_repeated(rooms[i], rooms[i].array_of_rooms[j]->name))
    {
        rooms[i].array_of_rooms[j] = rooms[i].array_of_rooms[rooms[i].setlink - 1];
        rooms[i].array_of_rooms[rooms[i].setlink - 1] = NULL;
        rooms[i].setlink -= 1;
    }
    else
      j++;
  }
  i++;

}
  return (rooms);
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

void print_room(s_room rooms)
{
  int j;

    ft_printf("--------------------------\n");
    ft_printf("the name %s | %d\n", rooms.name, rooms.setlink);
    j = 0;
    while (rooms.array_of_rooms[j] != '\0' && rooms.setlink > j) {
      /* code */
     ft_printf("***%s\n", rooms.array_of_rooms[j]->name);
      j++;
    }
}

void print_rooms(s_room *rooms, int *arr)
{
  int i;
  int j;

  i = 0;
  while(i < number_of_rooms)
  {
    ft_printf("--------------------------\n");
    ft_printf("the name %s (%c) | %d  | %d >>> %d  level %d and %c\n", rooms[i].name, rooms[i].type,rooms[i].setlink, arr[i] , rooms[i].ord, rooms[i].level, rooms[i].ispassed);
    j = 0;
    while (rooms[i].array_of_rooms[j] != '\0' && rooms[i].setlink > j) {
      /* code */
     ft_printf("***%s %d\n", rooms[i].array_of_rooms[j]->name, rooms[i].array_of_rooms[j]->level);
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

  rooms[a].array_of_rooms[rooms[a].setlink] = &rooms[b];
  rooms[b].array_of_rooms[rooms[b].setlink] = &rooms[a];
  rooms[a].setlink = rooms[a].setlink + 1;
  rooms[b].setlink = rooms[b].setlink + 1;

    j++;

    ft_printf("%d , %d \n", a + 1 , b + 1);
    }
    s_room *test = delete_link(rooms);

    return test;
  }
