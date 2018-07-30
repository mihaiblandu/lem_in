/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 08:33:37 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:18:49 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	ft_strrev_p(char *str)
{
	int		i;
	int		len;
	char	tmp;

	if (!str)
		return ;
	len = ft_strlen_p(str);
	i = -1;
	while (++i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
	}
}

void	empty_string(char **str)
{
	free(*str);
	*str = (char*)malloc(sizeof(**str));
	(*str)[0] = '\0';
}
