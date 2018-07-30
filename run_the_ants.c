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

/*
void    run_the_ants(s_room *room)
{
    int ants;
    ants = 1;  
    while (ants <= number_of_ants)
    {
        k = 0;
        while (last >= 0)
        {
            room[last] = room[last - 1];
            last--;
        }
        ants++;
        if (room[end].int == number_of_rooms)
            return (exit);
    }
}
*/
