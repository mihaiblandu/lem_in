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
		if(ro[i].ispassed == 'D')
		{
			ft_printf("Room %s %d %d %c\n", ro[i].name, ro[i].x, ro[i].y, ro[i].ispassed);
		}
		j = 0;
		while (ro[i].array_of_rooms[j] != NULL && ro[i].setlink > j)
		{
			j++;
		}
		i++;
	}
}
