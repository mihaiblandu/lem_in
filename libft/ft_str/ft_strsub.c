/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:00:01 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 16:02:07 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (s)
	{
		if ((str = (char *)malloc(sizeof(char) * (len + 1))))
		{
			while (len--)
			{
				str[i++] = s[start++];
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (0);
}
