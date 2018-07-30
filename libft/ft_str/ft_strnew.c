/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:00:13 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 16:01:56 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if ((str = ft_memalloc(size + 1)))
	{
		str[size] = '\0';
		return ((char *)str);
	}
	return (0);
}
