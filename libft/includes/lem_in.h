/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:28:51 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/31 02:26:29 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				ant;
	char			ispassed;
	int				setlink;
	char			type;
	int				level;
	struct s_room	**array_of_rooms;
}					s_room;

typedef struct		s_link
{
	char			*name_s;
	char			*name_d;
}					s_link;

typedef struct		s_path
{
	char			*name;
	int				ants;
	char			type;
}					s_path;

int					number_of_rooms;
int					number_of_links;
int					number_of_ants;
int					first;
int					end;

int					all_digits(char *str);
s_room				create_room(char *str, char type);
int					ft_contain(char *str, char c);
int					get_len(char **str);
void				print_room(s_room rooms);
s_room				*set_level(s_room *rooms);
int					get_the_ant_number();
int					is_comment(char *c);
int					is_comment_room(char *c);
int					check_patern(char *str);
char				check_patern_room(char *str);
void				get_the_rooms(char type, int i);
int					check_patern_links(char *str);
int					get_len(char **str);
int					all_digits(char *str);
char				is_command(char *s);
void				print_rooms(s_room *rooms);
int					*count_links_per_state(s_room *rooms, s_link *links);
s_room				*set_the_links(s_room *rooms, \
		s_link	*links, \
		int	i, int	j);
void				print_way(s_room *rooms);
void				print_start_end(s_room *rooms);
void				print_error(char *str);
void				get_end_and_start(s_room *room);
s_path				*save_ants(s_room *room, s_path *path, \
		int level, int i, int k);
void				mark_the_path_mod(s_room *room);
char				is_command(char *s);
void				mark_the_path(s_room *room);
void				go(s_room *room);
void				start(s_room *room, s_path *path, int k);
#endif
