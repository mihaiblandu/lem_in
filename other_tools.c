/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 09:18:53 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/30 23:26:36 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

void	print_error(char *temp)
{
	ft_printf("Error %s\n", temp);
	exit(0);
}

char	is_command(char *s)
{
	s = ft_strtrim(s);
	if (!ft_strcmp("##start", s))
		return ('S');
	if (!ft_strcmp("##end", s))
		return ('E');
	return ('N');
}

void	mark_the_path(s_room *room)
{
	int		k;

	k = 0;
	while (k < room->setlink)
	{
		if (room->type == 'E' && room->level == \
				room->array_of_rooms[k]->level + 1)
		{
			room->array_of_rooms[k]->ispassed = 'D';
			mark_the_path(room->array_of_rooms[k]);
		}
		else if (room->type != 'S' \
				&& room->level == room->array_of_rooms[k]->level + 1)
		{
			room->array_of_rooms[k]->ispassed = 'D';
			mark_the_path(room->array_of_rooms[k]);
		}
		else if (room->type == 'S')
		{
			return ;
		}
		k++;
	}
}

void	mark_the_path_mod(s_room *room)
{
	int		k;

	k = 0;
	while (k < room->setlink)
	{
		if (room->level == room->array_of_rooms[k]->level + 1)
		{
			room->ispassed = 'P';
			room->array_of_rooms[k]->ispassed = 'P';
			mark_the_path_mod(room->array_of_rooms[k]);
			break ;
		}
		if (room->type == 'S')
		{
			room->ispassed = 'P';
			room->array_of_rooms[k]->ispassed = 'P';
			return ;
		}
		k++;
	}
}

void	go(s_room *room)
{
	int		i;

	i = 0;
	while (i < number_of_rooms)
	{
		if (room[i].type == 'E' && room[i].level > 1)
		{
			room[i].ispassed = 'D';
			mark_the_path(&room[i]);
		}
		i++;
	}
}
