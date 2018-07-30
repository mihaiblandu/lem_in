/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:18:21 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:18:28 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	prepend_char(char **str, char c, int min_len)
{
	int		len;
	char	*new;

	if (!str || !*str)
		return ;
	len = ft_strlen_p(*str);
	if (min_len <= len)
		return ;
	if (!(new = (char*)malloc(sizeof(*new) * (min_len) + 1)))
	{
		free(*str);
		*str = NULL;
		return ;
	}
	new[min_len] = '\0';
	while (len--)
		new[--min_len] = (*str)[len];
	while (min_len--)
		new[min_len] = c;
	free(*str);
	*str = new;
}

void	append_char(char **str, char c, int min_len)
{
	int		len;
	char	*new;

	if (!str || !*str)
		return ;
	len = ft_strlen_p(*str);
	if (min_len <= len)
		return ;
	if (!(new = (char*)malloc(sizeof(*new) * (min_len) + 1)))
	{
		free(*str);
		*str = NULL;
		return ;
	}
	new[min_len] = '\0';
	while (min_len > len)
		new[--min_len] = c;
	while (min_len--)
		new[min_len] = (*str)[min_len];
	free(*str);
	*str = new;
}

void	prepend_str(char **dst, char *src)
{
	int		dst_len;
	int		src_len;
	char	*cat;

	if (!dst || !*dst || !src)
		return ;
	dst_len = ft_strlen_p(*dst);
	src_len = ft_strlen_p(src);
	if (!(cat = (char*)malloc(sizeof(*cat) * (dst_len + src_len + 1))))
	{
		free(*dst);
		*dst = NULL;
		return ;
	}
	cat[dst_len + src_len] = '\0';
	while (dst_len--)
		cat[dst_len + src_len] = (*dst)[dst_len];
	while (src_len--)
		cat[src_len] = src[src_len];
	free(*dst);
	*dst = cat;
}

void	append_str(char **dst, char *src)
{
	int		dst_len;
	int		src_len;
	char	*cat;

	if (!dst || !*dst || !src)
		return ;
	dst_len = ft_strlen_p(*dst);
	src_len = ft_strlen_p(src);
	if (!(cat = (char*)malloc(sizeof(*cat) * (dst_len + src_len + 1))))
	{
		free(*dst);
		*dst = NULL;
		return ;
	}
	cat[dst_len + src_len] = '\0';
	while (src_len--)
		cat[dst_len + src_len] = src[src_len];
	while (dst_len--)
		cat[dst_len] = (*dst)[dst_len];
	free(*dst);
	*dst = cat;
}

void	insert_commas(char **str, int i)
{
	int		ind;
	int		count;
	char	*new;

	if (!i || !str || !*str)
		return ;
	ind = ft_strlen_p(*str) - 1;
	i = ind + ind / 3 + 1;
	if (!(new = (char*)malloc(sizeof(*new) * (i + 1))))
	{
		free(*str);
		*str = NULL;
		return ;
	}
	new[i] = '\0';
	count = -1;
	while (i-- && ++count >= 0)
	{
		if (count % 4 == 3)
			new[i] = ',';
		else
			new[i] = (*str)[ind--];
	}
	free(*str);
	*str = new;
}
