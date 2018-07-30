#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

void    print_start_end(s_room *rooms)
{
    int     i;

    i = 0;
    while (i < number_of_rooms)
    {
        if(rooms[i].type == 'S')
        {
           ft_printf("#START\n%s %d %d\n", rooms[i].name, rooms[i].x, rooms[i].y);
            break ;
        }
        i++;
    }
    i = 0;
    while (i < number_of_rooms)
    { 
        if(rooms[i].type == 'E')
        {
            ft_printf("#END\n%s %d %d\n\n", rooms[i].name, rooms[i].x, rooms[i].y);
            break ;
        }
        i++;
    }
}

void  get_start(s_room *rooms)
{   

   int     i;

    i = 0;
    while (i < number_of_rooms)
    {
        if(rooms[i].type == 'S')
        {
            first = i;
            break ;
        }
        i++;
    }
}

void  get_end(s_room *rooms)
{   

   int     i;

    i = 0;
    while (i < number_of_rooms)
    {
        if(rooms[i].type == 'E')
        {
            end = i;
            break ;
        }
        i++;
    }
}

void    get_end_and_start(s_room *room)
{
    end = 0;
    first = 0;
    get_start(room);
    get_end(room);
}


s_path    *save_ants(s_room *room, s_path *path, int level)
{
    int i;
    int k;
    
    i = 0;
    k = 0;
    path = (s_path*)malloc(sizeof(s_path) * level);
    while (room->type != 'E')
    {
        if(room->type == 'E')
            {
                ft_printf("%s - %s \n", room->name, room->array_of_rooms[i]->name);
                path[k].name = room->name;
                path[k].type = 'E';
                path[k].ants = 0;
                return path;
            }
        if ((room->ispassed == 'P' && room->array_of_rooms[k]->ispassed == 'P') && (room->level == room->array_of_rooms[k]->level - 1))
        {
                ft_printf("%s - %s \n", room->name, room->array_of_rooms[i]->name);
               
                path[k].name = room->name;
                path[k].type = room->type;
                path[k].ants = 0;
                room = room->array_of_rooms[i];
                i = 0;
                k++;
        }
        i++;
    }
    return path;
}
