/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:33:43 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:33:45 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		*ft_sort(int *str, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	int				a;

	i = 0;
	j = 0;
	while (i < len)
	{
		while (j < len)
		{
			if (str[i] < str[j])
			{
				a = str[i];
				str[i] = str[j];
				str[j] = a;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (str);
}
