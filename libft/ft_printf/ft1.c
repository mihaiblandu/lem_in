/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 08:33:29 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:18:37 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int		ft_strlen_p(char *str)
{
	int		len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup_p(char *str)
{
	int		len;
	char	*dup;

	if (!str)
		return (NULL);
	len = ft_strlen_p(str);
	if (!(dup = (char*)malloc(sizeof(*dup) * (len + 1))))
		return (NULL);
	dup[len] = '\0';
	while (len--)
		dup[len] = str[len];
	return (dup);
}

void	ft_putstr_p(char *str)
{
	if (str)
		write(1, str, ft_strlen_p(str));
}

char	*ft_strsub_p(char *str, int start, int len)
{
	int		slen;
	char	*sub;

	if ((slen = ft_strlen_p(str)) < start + len)
		len = slen - start;
	if (!str || !(sub = (char*)malloc(sizeof(*sub) * (len + 1))))
		return (NULL);
	sub[len] = '\0';
	while (len--)
		sub[len] = str[start + len];
	return (sub);
}

void	ft_strtoupper(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}
