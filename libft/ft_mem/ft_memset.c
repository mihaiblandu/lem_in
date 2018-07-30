/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:15:17 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:17:57 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char*)str;
	while (n-- > 0)
		*tmp++ = (unsigned char)c;
	return (str);
}
