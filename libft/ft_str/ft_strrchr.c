/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:58:04 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:58:07 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *s;
	char *res;

	res = NULL;
	s = (char *)str;
	while (*s)
	{
		if (*s == (char)c)
			res = s;
		s++;
	}
	if ((char)c == '\0')
		return (s);
	return (res);
}
