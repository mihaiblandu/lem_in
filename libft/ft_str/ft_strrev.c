/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 16:00:28 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 16:00:47 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	ag;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		ag = str[i];
		str[i] = str[j];
		str[j] = ag;
		i++;
		j--;
	}
	return (str);
}
