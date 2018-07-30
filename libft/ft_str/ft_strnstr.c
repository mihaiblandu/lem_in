/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:58:29 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:58:44 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	if (find[0] == '\0')
		return ((char*)str);
	while (str[i] && n > 0)
	{
		j = 0;
		k = n;
		while (find[j] && str[i + j] == find[j] && n > 0)
		{
			j++;
			n--;
		}
		if (find[j] == '\0')
			return ((char*)str + i);
		n = k;
		i++;
		n--;
	}
	return (0);
}
