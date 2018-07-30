/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:13:44 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:13:51 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *s;

	s = (unsigned char *)str;
	while (n--)
	{
		if (*s == (unsigned char)c)
			return (s);
		s++;
	}
	return (NULL);
}
