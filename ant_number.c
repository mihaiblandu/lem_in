/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 09:58:58 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 10:38:53 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/get_next_line.h"

int		is_comment(char *c)
{
	if (ft_strlen(c) == 0)
		return (1);
	if (c[0] == '#' && c[1] == '\0')
		return (1);
	if (c[0] == '#' && c[1] == '#' && c[2] == '\0')
		return (1);
	if (c[0] == '#' && c[1] == '#' && c[2] == '#')
		return (1);
	c = ft_strtrim(c);
	if (!ft_strcmp(c, "##start") || !ft_strcmp("##end", c))
	{
		ft_printf("Here commands are not permited %s\n", c);
		exit(0);
	}
	if (c[0] == '#')
		return (1);
	return (0);
}

int		check_patern(char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = 0;
	while ((str[i] == ' ' || str[i] == '\t') && (i <= len))
		i++;
	if (i == len)
		return (0);
	while ((str[i] != '\0') && !(str[i] == ' ' || str[i] == '\t') &&  \
			(i <= len))
	{
		if (!(ft_isdigit(str[i])))
		{
			if (str[i] == '\0')
				return (1);
			ft_printf("Error %s\n", str);
			exit(0);
		}
		if (str[i] == '\0')
			return (1);
		i++;
	}
	return (1);
}

int		get_the_ant_number(void)
{
	int		n;
	char	*temp;

	n = 0;
	while (get_next_line(0, &temp) == 1)
	{
		if (!is_comment(temp))
		{
			if (check_patern(temp))
			{
				n = ft_atoi(temp);
				return (n);
			}
			else
			{
				ft_printf("Error");
				exit(0);
			}
		}
	}
	ft_printf("Error\n");
	exit(0);
}
