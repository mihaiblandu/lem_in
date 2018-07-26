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

void mark_the_it(s_room *room)
{
  int k;

  k = 0;
//ft_printf("Mark with D %s  ||| %d\n",room->name, room->level);

  while (room->level == room->array_of_rooms[k]->level + 1) {
    /* code */

    if (room->array_of_rooms[k]->ispassed == 'Y' && room->level > room->array_of_rooms[k]->level) {
      room->ispassed = 'D';
      ft_printf("Mark with D %s  ||| %d\n",room->name, room->level);
      room->array_of_rooms[k]->ispassed = 'D';
      if (room->array_of_rooms[k]->type == 'S') {
        /* code */
        ft_printf("URA  %s  ||| %d\n",room->array_of_rooms[k]->name, room->array_of_rooms[k]->level);

        print_way(room);

        return;

      }
      mark_the_it(room->array_of_rooms[k]);
      break;
    }
    k++;
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

          }
            room->array_of_rooms[k]->ispassed = 'Y';
            mark_the_level(room->array_of_rooms[k], i + 1);
    }
    else if(room->level < room->array_of_rooms[k]->level)
    {
      room->array_of_rooms[k]->level = room->level + 1;
      ft_printf(">>>>>%s | %d\n",room->array_of_rooms[k]->name, room->array_of_rooms[k]->level );

      if (room->array_of_rooms[k]->type == 'E')
       {
      room->array_of_rooms[k]->ispassed = 'D';
        room->array_of_rooms[k]->level = room->level + 1;
      ft_printf("URA  %s  ||| %d\n",room->array_of_rooms[k]->name, room->array_of_rooms[k]->level);
      mark_the_it(room);

        }
          room->array_of_rooms[k]->ispassed = 'Y';
          mark_the_level(room->array_of_rooms[k], room->level + 1);
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
void print_way(s_room *room)
{
    int i;

    i = 0;
    while(i < room->setlink)
    {
      if(room->type == 'E')
      {
        ft_printf("End");
        return;
      }
      if (room->array_of_rooms[i]->ispassed == 'D' && room->level == room->array_of_rooms[i]->level - 1) {

        ft_printf("room calea corecta %s   %d", room->array_of_rooms[i]->name, room->array_of_rooms[i]->level);
        print_way(room);

        break;

      }
      i++;
    }

}
