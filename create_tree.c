#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

void mark_the_it(s_room *room)
{
  int k;
  k = 0;
ft_printf("UTTTTTTTTTTTTTTTTT  %s  ||| %d\n",room->name, room->level);
  while (k < room->setlink && !(room->type == 'S') )
  {

    if (room->array_of_rooms[k]->ispassed == 'Y' && room->level > room->array_of_rooms[k]->level) {
      room->ispassed = 'D';
      room->array_of_rooms[k]->ispassed = 'D';
      if (room->array_of_rooms[k]->type == 'S') {
        /* code */
        ft_printf("URA  %s  ||| %d\n",room->array_of_rooms[k]->name, room->array_of_rooms[k]->level);

        break;
        //exit(0);
      }
      mark_the_it(room->array_of_rooms[k]);
    // exit(0);
    break;
    }
    k++;
  }
}

void mark_the_level(s_room *room, int i)
{
  int k;
  k = 0;
    ft_printf("mark level: ");
  while (k < room->setlink)
  {

    if (room->array_of_rooms[k]->ispassed == 'N') {

        room->array_of_rooms[k]->level = i;
        ft_printf(">>>>>%s | %d\n",room->array_of_rooms[k]->name, room->array_of_rooms[k]->level );
          room->array_of_rooms[k]->ispassed = 'Y';
      if (room->array_of_rooms[k]->type == 'E') {
        /* code */
        room->array_of_rooms[k]->ispassed = 'D';
        ft_printf("URA  %s  ||| %d\n",room->array_of_rooms[k]->name, room->array_of_rooms[k]->level);
        mark_the_it(room);
          break;
          }
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
        ft_printf("!!!!!!!!!!!!!!!!!!\n");
        rooms[i].level = 0;
        rooms[i].ispassed = 'Y';
      mark_the_level(&rooms[i], 1);
      }
      i++;
    }
    return rooms;
}
