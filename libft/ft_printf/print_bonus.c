/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 08:35:36 by mblandu           #+#    #+#             */
/*   Updated: 2018/02/09 08:35:37 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "ft_printf.h"
#include "../includes/libft.h"

int		store_numchar(va_list *args, t_flags *f)
{
	int		*loc;

	loc = va_arg(*args, int*);
	if (f->lenmod == 1)
		*(signed char*)loc = f->num_char;
	else if (f->lenmod == 2)
		*(short*)loc = f->num_char;
	else if (f->lenmod == 3)
		*(long*)loc = f->num_char;
	else if (f->lenmod == 4)
		*(long long*)loc = f->num_char;
	else if (f->lenmod == 5)
		*(intmax_t*)loc = f->num_char;
	else if (f->lenmod == 6)
		*(ssize_t*)loc = f->num_char;
	else if (f->lenmod == 8)
		*(ptrdiff_t*)loc = f->num_char;
	else
		*loc = f->num_char;
	return (0);
}
