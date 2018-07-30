/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:17:12 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 23:21:45 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

void	print_room(s_room rooms)
{
	int		j;

	j = 0;
	while (rooms.array_of_rooms[j] != '\0' && rooms.setlink > j)
		j++;
}

void	print_rooms(s_room *ro)
{
	int		i;
	int		j;

	i = 0;
	while (i < number_of_rooms)
	{
		ft_printf("ROOM %s (%d) %d %d %c %c\n", ro[i].name, ro[i].level, \
			ro[i].x, ro[i].y, ro[i].ispassed, ro[i].type);
		if (ro[i].ispassed != 'Y')
		{
			ft_printf("camara %s (%d) %d %d %c %c\n", ro[i].name, \
				ro[i].level, ro[i].x, ro[i].y, \
				ro[i].ispassed, ro[i].type);
		}
		j = 0;
		while (ro[i].array_of_rooms[j] != NULL && ro[i].setlink > j)
		{
			ft_printf("Link %s %c %c\n", ro[i].array_of_rooms[j]->name, \
				ro[i].array_of_rooms[j]->type, \
				ro[i].array_of_rooms[j]->ispassed);
			j++;
		}
		i++;
	}
}
