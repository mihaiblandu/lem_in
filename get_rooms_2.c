/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:41:19 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/31 00:00:49 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

void	start(s_room *room, s_path *path, int k)
{
	int i;

	i = 0;
	while (i < room->setlink)
	{
		if (room->ispassed == 'D' && room->array_of_rooms[i]->ispassed == 'D' \
				&& room->level == room->array_of_rooms[i]->level - 1)
		{
			ft_printf("%s - %s \n", room->name, room->array_of_rooms[i]->name);
			path[k].name = room->name;
			path[k].type = room->type;
			path[k].ants = 0;
			path[k + 1].name = room->array_of_rooms[i]->name;
			path[k + 1].type = room->array_of_rooms[i]->type;
			path[k + 1].ants = 0;
			start(room->array_of_rooms[i], path, k + 1);
			break ;
		}
		i++;
	}
}

int		is_comment_room(char *c)
{
	c = ft_strtrim(c);
	if (ft_strlen(c) == 0 || c[0] == '\n' || c[0] == '\0')
		return (1);
	if (c[0] == '#' && c[1] == '\0')
		return (1);
	if (c[0] == '#' && c[1] == '#' && c[2] == '\0')
		return (1);
	if (!ft_strcmp(c, "##start") || !ft_strcmp("##end", c))
		return (0);
	if (c[0] == '#')
		return (1);
	return (0);
}

int		all_digits(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		get_len(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int		ft_contain(char *str, char c)
{
	char	*s;

	s = (char *)str;
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}
