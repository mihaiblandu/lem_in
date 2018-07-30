/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:08:20 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:08:26 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_max(int *ag, unsigned int len)
{
	int				max;
	unsigned int	i;

	i = 0;
	if (ag[0] == '\0')
		return (0);
	max = ag[0];
	while (i < len)
	{
		if (max < ag[i])
			max = ag[i];
		i++;
	}
	return (max);
}
