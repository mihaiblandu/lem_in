/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:59:03 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:59:05 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int		ft_word(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && str[i] != '\0')
		{
			count++;
			while (str[i] != c && str[i + 1] != '\0')
				i++;
		}
		i++;
	}
	return (count);
}

static	int		ft_lenword(char *str, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i] == c)
		i++;
	while (str[i] && str[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		words;

	i = 0;
	if (!s)
		return (NULL);
	words = ft_word((char *)s, c);
	if ((str = (char **)malloc(sizeof(char *) * (words + 1))))
	{
		while (*s && i < words)
		{
			if (*s != c && *s)
			{
				str[i] = ft_strnew(ft_lenword((char *)s, c));
				ft_strncpy(str[i], s, ft_lenword((char *)s, c));
				s = s + ft_lenword((char *)s, c);
				i++;
			}
			s++;
		}
		str[i] = NULL;
		return (str);
	}
	return (NULL);
}
