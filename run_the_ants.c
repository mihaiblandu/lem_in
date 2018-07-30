/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_the_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 01:19:47 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/31 01:45:35 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

void	print_start_end(s_room *rooms)
{
	int		i;

	i = 0;
	while (i < number_of_rooms)
	{
		if (rooms[i].type == 'S')
		{
			ft_printf("#START\n%s %d %d\n", rooms[i].name, \
					rooms[i].x, rooms[i].y);
			break ;
		}
		i++;
	}
	i = 0;
	while (i < number_of_rooms)
	{
		if (rooms[i].type == 'E')
		{
			ft_printf("#END\n%s %d %d\n\n", rooms[i].name, \
					rooms[i].x, rooms[i].y);
			break ;
		}
		i++;
	}
}

void	get_start(s_room *rooms)
{
	int		i;

	i = 0;
	while (i < number_of_rooms)
	{
		if (rooms[i].type == 'S')
		{
			first = i;
			break ;
		}
		i++;
	}
}

void	get_end(s_room *rooms)
{
	int		i;

	i = 0;
	while (i < number_of_rooms)
	{
		if (rooms[i].type == 'E')
		{
			end = i;
			break ;
		}
		i++;
	}
}

void	get_end_and_start(s_room *room)
{
	end = 0;
	first = 0;
	get_start(room);
	get_end(room);
}
