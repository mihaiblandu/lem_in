#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

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

      if(ft_strcmp(rooms[i].name, links[j].name_s) == 0 ||
      ft_strcmp(rooms[i].name, links[j].name_d) == 0)
      {

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

  void set_the_links(s_room *rooms, s_link *links)
  {

    int i = 0;
    int j = 0;
    int *arr;

    arr = count_links_per_state(rooms, links);

    while (i < number_of_rooms) {
      i++;
    }
    i =0;
    while(i  < number_of_rooms)
    {
      j = 0;
      rooms[i].ord = i;
    rooms[i].array_of_rooms = (s_room*)malloc(sizeof(s_room) * arr[i]);
      while (j < number_of_links)
       {
      if (ft_strcmp(rooms[i].name, links[j].name_d) == 0)
      {
        ft_printf(">>>>>>>>>>>>>>>>>>>>>>>%d", sizeof(rooms[i].array_of_rooms));
        //  rooms[i].array_of_rooms[j] = &rooms[i];
        //rooms[ i].array_of_rooms[j] = &rooms[get_the_rooms_by_name(rooms, links[j].name_d)];
      //  ft_printf("######%s", rooms[i].array_of_rooms[i]->name);
      ft_printf(">>>>>>>>>>>>>>>>>>>>>>>%s", rooms[i].name);
      }
      if (ft_strcmp(rooms[i].name, links[j].name_d) == 0)
      {

      }
      j++;
    }

      i++;
    }
    ft_printf("%d\n", arr[0]);

  }
