/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:13:17 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:13:19 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char *str;

	if ((str = (char *)malloc(sizeof(*str) * size)))
		ft_bzero(str, size);
	return (str);
}
