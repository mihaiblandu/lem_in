/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 18:41:19 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 23:51:09 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

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

void	start(s_room *room)
{
	int i;

	i = 0;
	while (i < room->setlink)
	{
		if (room->ispassed == 'D' && room->array_of_rooms[i]->ispassed == 'D' \
				&& room->level == room->array_of_rooms[i]->level - 1)
		{
      ft_printf("%s - %s \n", room->name, room->array_of_rooms[i]->name);
			start(room->array_of_rooms[i]);
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
			{
				ft_printf("THIS IS CATCHED  ROOM%s\n", str);
				exit(0);
			}
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

void	save_thelinks(s_link *link, char *s, char *d)
{
	link->name_s = (char*)malloc((sizeof(char) * (ft_strlen(s)) + 1));
	link->name_d = (char*)malloc((sizeof(char) * (ft_strlen(d)) + 1));
	link->name_s = ft_strcpy(link->name_s, s);
	link->name_d = ft_strcpy(link->name_d, d);
}

void	get_the_path(s_room *ro, s_link *link)
{
	int		i;

	i = 0;
	ro = set_the_links(ro, link, 0, 0, 0, 0);
	set_level(ro);
	go(ro);
	i = 0;
	print_start_end(ro);
	while (i < number_of_rooms)
	{
		if (ro[i].type == 'S' && ro[i].ispassed == 'D')
		{
			start(&ro[i]);
			ft_printf("___________\n");
			break ;
		}
		i++;
	}
	print_rooms(ro);

}

void	get_the_rooms(void)
{
	char			*temp;
	struct s_room	room[20000];
	struct s_link	*link;
	int				i;
	char			**arg;
	char			type;

	type = 'N';
	i = 0;
	link = (s_link*)malloc(sizeof(s_link) * 50000);
	number_of_rooms = 0;
	number_of_links = 0;
	while (get_next_line(0, &temp) == 1)
	{
		if (!is_comment_room(temp))
		{
			if (check_patern_room(temp) == 'R')
			{
				room[number_of_rooms] = create_room(temp, type);
				number_of_rooms++;
			}
			type = is_command(temp);
			if (check_patern_room(temp) == 'L')
			{
				arg = ft_strsplit(ft_strtrim(temp), '-');
				if (ft_strcmp(arg[0], arg[1]))
				{
					save_thelinks(&link[i], arg[0], arg[1]);
					number_of_links++;
					i++;
				}
			}
			if (check_patern_room(temp) == 'D')
				print_error(temp);
		}
	}
	get_the_path(room,link);
}
