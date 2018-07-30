/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:03:58 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 16:04:09 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int i;

	i = 0;
	while (n > 0 && src[i])
	{
		dst[i] = src[i];
		i++;
		n--;
	}
	while (n > 0)
	{
		dst[i] = '\0';
		i++;
		n--;
	}
	return (dst);
}
