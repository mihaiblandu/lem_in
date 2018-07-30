/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 10:39:06 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/31 01:59:01 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

int		find_min(s_room *room)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	temp = 99999999;
	while (i < room->setlink)
	{
		if (room->array_of_rooms[i]->level < temp)
		{
			temp = room->array_of_rooms[i]->level;
			j = i;
		}
		i++;
	}
	return (j);
}

void	mark_the_it(s_room *room)
{
	int k;

	k = 0;
	while (room->level == room->array_of_rooms[k]->level + 1)
	{
		if (room->array_of_rooms[k]->ispassed == 'Y' && room->level > \
				room->array_of_rooms[k]->level)
		{
			room->ispassed = 'D';
			room->array_of_rooms[k]->ispassed = 'D';
			if (room->array_of_rooms[k]->type == 'S')
			{
				print_way(room);
				return ;
			}
			mark_the_it(room->array_of_rooms[k]);
			break ;
		}
		k++;
	}
}

void	mark_the_level(s_room *room, int i)
{
	int		k;

	k = 0;
	while (k < room->setlink)
	{
		if (room->array_of_rooms[k]->ispassed == 'N')
		{
			room->array_of_rooms[k]->level = i;
			if (room->array_of_rooms[k]->type == 'E')
			{
				room->array_of_rooms[k]->ispassed = 'D';
				mark_the_it(room->array_of_rooms[k]);
			}
			room->array_of_rooms[k]->ispassed = 'Y';
			mark_the_level(room->array_of_rooms[k], i + 1);
		}
		else if (room->level < room->array_of_rooms[k]->level)
		{
			room->array_of_rooms[k]->level = room->level + 1;
			if (room->array_of_rooms[k]->type == 'E')
			{
				room->array_of_rooms[k]->ispassed = 'D';
				room->array_of_rooms[k]->level = room->level + 1;
				mark_the_it(room->array_of_rooms[k]);
			}
			room->array_of_rooms[k]->ispassed = 'Y';
			mark_the_level(room->array_of_rooms[k], room->level + 1);
		}
		k++;
	}
}

s_room	*set_level(s_room *rooms)
{
	int		i;

	i = 0;
	while (i < number_of_rooms)
	{
		if (rooms[i].type == 'S')
		{
			rooms[i].level = 1;
			rooms[i].ispassed = 'Y';
			mark_the_level(&rooms[i], 2);
		}
		i++;
	}
	return (rooms);
}

void	print_way(s_room *room)
{
	int		i;

	i = 0;
	while (i < room->setlink)
	{
		if (room->level == room->array_of_rooms[i]->level - 1)
		{
			print_way(room->array_of_rooms[i]);
			if (room->array_of_rooms[i]->type == 'E')
				return ;
		}
		i++;
	}
}
