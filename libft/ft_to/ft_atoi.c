/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:27:11 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 16:27:13 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	int s;
	int numb;

	s = 1;
	numb = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
		*str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		numb = numb * 10 + (*str - '0');
		str++;
	}
	return (numb * s);
}
