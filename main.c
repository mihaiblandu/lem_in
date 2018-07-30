/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 23:33:19 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 23:45:26 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

int		ignore_comment(char a, char b)
{
	if (a == '#' && b != '#')
		return (0);
	return (1);
}

int		main(void)
{
	number_of_ants = get_the_ant_number();
	number_of_rooms = 0;
	number_of_links = 0;
	ft_printf("Number of ANTS %d \n\n", number_of_ants);
	get_the_rooms('N', 0);
	return (0);
}
