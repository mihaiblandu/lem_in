/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 11:05:19 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 18:19:50 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

int		is_repeated(s_room room, char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < room.setlink)
	{
		if (ft_strcmp(room.array_of_rooms[i]->name, str) == 0)
		{
			j++;
			if (j == 2)
				return (1);
		}
		i++;
	}
	return (0);
}

s_room	*delete_link(s_room *rooms)
{
	int		i;
	int		j;

	i = 0;
	while (i < number_of_rooms)
	{
		j = 0;
		while (j < rooms[i].setlink)
		{
			if (is_repeated(rooms[i], rooms[i].array_of_rooms[j]->name))
			{
				rooms[i].array_of_rooms[j] = \
					rooms[i].array_of_rooms[rooms[i].setlink - 1];
				rooms[i].array_of_rooms[rooms[i].setlink - 1] = NULL;
				rooms[i].setlink -= 1;
			}
			else
				j++;
		}
		i++;
	}
	return (rooms);
}

int		*count_links_per_state(s_room *rooms, s_link *links)
{
	int		*arr;
	int		i;
	int		j;

	j = 0;
	i = 0;
	arr = (int*)malloc(sizeof(int) * number_of_rooms);
	while (i < number_of_rooms)
	{
		arr[i] = 0;
		j = 0;
		while (j < number_of_links)
		{
			if (ft_strcmp(rooms[i].name, links[j].name_d) == 0 || \
					ft_strcmp(rooms[i].name, links[j].name_s) == 0)
				arr[i]++;
			j++;
		}
		i++;
	}
	return (arr);
}

int		get_the_rooms_by_name(s_room *rooms, char *name)
{
	int		i;

	i = 0;
	while (i < number_of_rooms)
	{
		if (ft_strcmp(rooms[i].name, name) == 0)
			return (i);
		i++;
	}
	ft_printf("Error\n");
	exit(0);
}

s_room	*set_the_links(s_room *rooms, s_link *links, int i, int j)
{
	int		*arr;
	s_room	*test;
	int		a;
	int		b;

	arr = count_links_per_state(rooms, links);
	while (i < number_of_rooms)
	{
		rooms[i].array_of_rooms = (s_room**)malloc(sizeof(s_room*) * arr[i]);
		i++;
	}
	while (j < number_of_links)
	{
		a = get_the_rooms_by_name(rooms, links[j].name_s);
		b = get_the_rooms_by_name(rooms, links[j].name_d);
		rooms[a].array_of_rooms[rooms[a].setlink] = &rooms[b];
		rooms[b].array_of_rooms[rooms[b].setlink] = &rooms[a];
		rooms[a].setlink = rooms[a].setlink + 1;
		rooms[b].setlink = rooms[b].setlink + 1;
		j++;
	}
	return (test = delete_link(rooms));
}
