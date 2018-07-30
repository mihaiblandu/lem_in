/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 09:18:53 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/30 09:18:55 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/lem_in.h"

void    print_error(char *temp)
{
    ft_printf("Error", check_patern_room(temp), temp);
    exit(0);
}
