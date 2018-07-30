/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:49:30 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 16:01:41 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	if (s)
	{
		if ((tmp = ft_strnew(ft_strlen(s))))
		{
			while (*s)
			{
				tmp[i] = f(i, *s++);
				i++;
			}
		}
		return (tmp);
	}
	return (0);
}
