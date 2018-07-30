/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 08:36:05 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 17:37:23 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "../includes/libft.h"

static int	apply_flags(char *str, t_flags *f)
{
	int		ret;
	int		nc;

	nc = 0;
	if (*str == '\0')
		nc = 1;
	if (f->minus == 1)
		append_char(&str, ' ', f->minwid - nc);
	else if (f->zero == 1)
		prepend_char(&str, '0', f->minwid - nc);
	else
		prepend_char(&str, ' ', f->minwid - nc);
	ret = ft_strlen_p(str);
	if (f->minus == 1 && nc == 1)
		write(1, "\0", 1);
	ft_putstr((const char*)str);
	if (f->minus == 0 && nc == 1)
		write(1, "\0", 1);
	free(str);
	return (ret + nc);
}

int			print_char(va_list *args, t_flags *f)
{
	char	*str;

	if (f->lenmod == 3 || f->conv == 'C')
		str = wchar_to_str(va_arg(*args, wchar_t));
	else
	{
		str = (char*)malloc(sizeof(*str) * 2);
		if (!str)
			return (0);
		str[0] = (char)va_arg(*args, int);
		str[1] = '\0';
	}
	return (apply_flags(str, f));
}

int			print_not_flag(t_flags *f)
{
	char	*str;

	str = (char*)malloc(sizeof(*str) * 2);
	if (!str)
		return (0);
	str[0] = f->conv;
	str[1] = '\0';
	return (apply_flags(str, f));
}
