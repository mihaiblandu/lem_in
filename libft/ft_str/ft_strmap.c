/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:03:15 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 16:03:18 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	i = 0;
	if (s)
	{
		if ((tmp = ft_strnew(ft_strlen(s))))
		{
			while (*s)
				tmp[i++] = f(*s++);
		}
		return (tmp);
	}
	return (0);
}
