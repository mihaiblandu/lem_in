/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:36:25 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:42:56 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	char	*str;

	j = 0;
	if (s1 && s2)
	{
		if ((str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			while (*s1)
				str[j++] = *s1++;
			while (*s2)
				str[j++] = *s2++;
			str[j] = '\0';
			return (str);
		}
	}
	return (0);
}
