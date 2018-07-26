#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

int find_min(s_room *room)
{
  int i;
  int j;
  int temp;
  i = 0;
  temp = 99999999;
  while(i < room->setlink)
  {
    if(room->array_of_rooms[i]->level < temp)
    {
      temp = room->array_of_rooms[i]->level;
      j = i;
    }
    i++;
  }
  ft_printf("print the %d  () %d   ", j, temp);
  return j;
}

int find_max(s_room *room)
{
  int i;
  int j;
  int temp;
  i = 0;
  temp = 0;
  while(i < room->setlink)
  {
    if(room->array_of_rooms[i]->level > temp)
    {
      temp = room->array_of_rooms[i]->level;
      j = i;
    }
    i++;
  }
  ft_printf("print the %d  () %d   ", j, temp);
  return j;
}



void mark_the_it(s_room *room)
{
  int k;
  int temp;
  k = 0;
//ft_printf("Mark with D %s  ||| %d\n",room->name, room->level);



    temp = find_min(room);
    k = temp;
    if (room->array_of_rooms[k]->ispassed == 'Y' && room->level > room->array_of_rooms[k]->level) {
      room->ispassed = 'D';
      ft_printf("Mark with D %s  ||| %d\n",room->name, room->level);
      room->array_of_rooms[k]->ispassed = 'D';
      if (room->array_of_rooms[k]->type == 'S') {
        /* code */
        ft_printf("URA  %s  ||| %d\n",room->array_of_rooms[k]->name, room->array_of_rooms[k]->level);

        return;
        //exit(0);
      }
      mark_the_it(room->array_of_rooms[k]);
    // exit(0);
  }


}


void mark_the_it_back(s_room *room)
{
  int k;
  int temp;
  k = 0;
//ft_printf("Mark with D %s  ||| %d\n",room->name, room->level);



    temp = find_max(room);
    k = temp;
    if (room->array_of_rooms[k]->ispassed == 'D' && room->level < room->array_of_rooms[k]->level) {
      room->ispassed = 'c';
      ft_printf("Mark with D %s  ||| %d\n",room->name, room->level);
      room->array_of_rooms[k]->ispassed = 'D';
      if (room->array_of_rooms[k]->type == 'S') {
        /* code */
        ft_printf("URA  %s  ||| %d\n",room->array_of_rooms[k]->name, room->array_of_rooms[k]->level);

        return;
        //exit(0);
      }
      mark_the_it(room->array_of_rooms[k]);
    // exit(0);
  }


}


void mark_the_level(s_room *room, int i)
{
  int k;
  k = 0;

  while (k < room->setlink)
  {
    if (room->array_of_rooms[k]->ispassed == 'N')
    {
        room->array_of_rooms[k]->level = i;

        ft_printf(">>>>>%s | %d\n",room->array_of_rooms[k]->name, room->array_of_rooms[k]->level );

        if (room->array_of_rooms[k]->type == 'E')
         {
        room->array_of_rooms[k]->ispassed = 'D';
        ft_printf("URA  %s  ||| %d\n",room->array_of_rooms[k]->name, room->array_of_rooms[k]->level);
        mark_the_it(room);
          break;
          }
            room->array_of_rooms[k]->ispassed = 'Y';
            mark_the_level(room->array_of_rooms[k], i + 1);
    }
    k++;
  }
}



s_room* set_level(s_room *rooms)
{
    int i;

    i = 0;
    while(i < number_of_rooms)
    {
      if (rooms[i].type == 'S') {
        ft_printf("seting the level\n");
        rooms[i].level = 1;
        rooms[i].ispassed = 'Y';
       mark_the_level(&rooms[i], 2);
      }
      i++;
    }
    return rooms;
}
