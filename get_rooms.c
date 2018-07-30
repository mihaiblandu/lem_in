/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
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

void	save_thelinks(s_link *link, char *s, char *d)
{
	number_of_links++;
	link->name_s = (char*)malloc((sizeof(char) * (ft_strlen(s)) + 1));
	link->name_d = (char*)malloc((sizeof(char) * (ft_strlen(d)) + 1));
	link->name_s = ft_strcpy(link->name_s, s);
	link->name_d = ft_strcpy(link->name_d, d);
}

void	shift_to_left(s_path *path, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (path[i].ants != 0)
			ft_printf(" L%10s [%d] ", path[i].name, path[i].ants);
		i++;
	}
	ft_printf("\n");
	i = len;
	while (i > 0)
	{
		if (i != 1)
		{
			path[i - 1].ants = path[i - 2].ants;
		}
		else
		{
			path[i - 1].ants = 0;
		}
		i--;
	}
}

void	put_ants(s_path *path, int len)
{
	int		i;

	i = 0;
	while (!(path[len - 1].ants == number_of_ants))
	{
		if (i <= number_of_ants)
		{
			path[0].ants = i;
			i++;
		}
		else
			path[0].ants = 0;
		shift_to_left(path, len);
	}
	shift_to_left(path, len);
	ft_printf("\n");
	exit(0);
}

void	get_the_path(s_room *ro, s_link *link)
{
	int		i;
	s_path	*path;

	i = ro[end].level;
	ro = set_the_links(ro, link, 0, 0);
	set_level(ro);
	go(ro);
	i = 0;
	print_start_end(ro);
	get_end_and_start(ro);
	path = (s_path*)malloc(sizeof(s_path) * ro[end].level);
	while (i < ro[end].level)
	{
		path[i].name = (char*)malloc(sizeof(char) * 10);
		i++;
	}
	start(&ro[first], path, 0);
	put_ants(path, ro[end].level);
}

void	get_the_rooms(char type, int i)
{
	char			*temp;
	struct s_room	room[20000];
	struct s_link	*link;
	char			**arg;

	link = (s_link*)malloc(sizeof(s_link) * 50000);
	while (get_next_line(0, &temp) == 1)
	{
		if (!is_comment_room(temp))
		{
			if (check_patern_room(temp) == 'R')
				room[number_of_rooms++] = create_room(temp, type);
			type = is_command(temp);
			if (check_patern_room(temp) == 'L')
			{
				arg = ft_strsplit(ft_strtrim(temp), '-');
				if (ft_strcmp(arg[0], arg[1]))
					save_thelinks(&link[i++], arg[0], arg[1]);
			}
			if (check_patern_room(temp) == 'D')
				print_error(temp);
		}
	}
	get_the_path(room, link);
}
