/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 08:36:16 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 17:26:03 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "../includes/libft.h"

int		print_color_text(va_list *args)
{
	char	*str;
	char	*num;
	int		ret;
	int		col;

	col = va_arg(*args, int);
	str = ft_strdup_p("\e[38;2;");
	num = ft_itoa_base((col >> 16) & 255, 10);
	append_str(&str, num);
	free(num);
	append_str(&str, ";");
	num = ft_itoa_base((col >> 8) & 255, 10);
	append_str(&str, num);
	free(num);
	append_str(&str, ";");
	num = ft_itoa_base(col & 255, 10);
	append_str(&str, num);
	free(num);
	append_str(&str, "m");
	ret = ft_strlen_p(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int		print_color_bg(va_list *args)
{
	char	*str;
	char	*num;
	int		ret;
	int		col;

	col = va_arg(*args, int);
	str = ft_strdup_p("\e[48;2;");
	num = ft_itoa_base((col >> 16) & 255, 10);
	append_str(&str, num);
	free(num);
	append_str(&str, ";");
	num = ft_itoa_base((col >> 8) & 255, 10);
	append_str(&str, num);
	free(num);
	append_str(&str, ";");
	num = ft_itoa_base(col & 255, 10);
	append_str(&str, num);
	free(num);
	append_str(&str, "m");
	ret = ft_strlen_p(str);
	ft_putstr(str);
	free(str);
	return (ret);
}

int		print_color_reset(void)
{
	ft_putstr("\e[0m");
	return (4);
}
