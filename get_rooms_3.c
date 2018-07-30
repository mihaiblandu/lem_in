/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms_3.c                                      :+:      :+:    :+:   */
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

int		check_patern_links(char *str)
{
	char	**array;
	char	a;

	str = ft_strtrim(str);
	a = str[ft_strlen(str) - 1];
	if (ft_contain(str, '-') && (str[0] != '-') && (a != '-'))
		return (1);
	else
		return (0);
	array = ft_strsplit(str, '-');
	if (get_len(array) == 2)
	{
		if (!all_digits(array[1]) && !all_digits(array[0]))
			return (1);
	}
	return (0);
}

char	check_patern_room(char *str)
{
	char	**array;

	if (is_command(str) == 'E' || is_command(str) == 'S')
		return ('F');
	if (is_comment_room(str))
		return ('C');
	if (ft_contain(str, ' '))
	{
		array = ft_strsplit(str, ' ');
		if (get_len(array) == 3)
		{
			if (array[0][0] == 'L' || array[0][0] == 'l')
				print_error("Invalide name");
			if (all_digits(array[1]) && (all_digits(array[2])))
				return ('R');
		}
	}
	else if (check_patern_links(str))
		return ('L');
	return ('D');
}

s_room	create_room(char *str, char type)
{
	char			**arg;
	struct s_room	*new_room;

	arg = ft_strsplit(str, ' ');
	new_room = (s_room*)malloc(sizeof(s_room));
	new_room->name = arg[0];
	new_room->x = ft_atoi(arg[1]);
	new_room->y = ft_atoi(arg[2]);
	new_room->setlink = 0;
	new_room->type = type;
	new_room->ispassed = 'N';
	new_room->level = 0;
	return (*new_room);
}
