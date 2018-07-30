/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:09:54 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:30:08 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_list_size(t_list *list)
{
	int count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}
