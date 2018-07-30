/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:02:46 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 16:03:27 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#define TAB(x) (x == ' ' || x == '\t' || x == '\n')

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	if (s)
	{
		len = ft_strlen(s);
		while (TAB(s[i]))
			i++;
		while (TAB(s[len - 1]))
			len--;
		len = len - i;
		if (len < 0)
			len = 0;
		str = ft_strsub(s, i, len);
		return (str);
	}
	return (NULL);
}
