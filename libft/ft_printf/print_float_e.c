/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_e.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 08:36:35 by mblandu           #+#    #+#             */
/*   Updated: 2018/02/09 08:36:36 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static int	apply_flags(char *inte, char *frac, char *exp, t_flags *f)
{
	(f->pound == 1 || ft_strlen_p(frac) > 0) ? append_str(&inte, ".") : 0;
	append_str(&inte, frac);
	free(frac);
	(f->conv == 'E') ? append_str(&inte, "E") : append_str(&inte, "e");
	(f->prec == -1) ? append_str(&inte, "-") : append_str(&inte, "+");
	prepend_char(&exp, '0', 2);
	append_str(&inte, exp);
	free(exp);
	if (f->zero == 1 && f->minus == 0)
		prepend_char(&inte, '0', f->minwid - 1);
	if (f->zero && !(f->minus) && f->sign == 1 && !(f->plus) && !(f->space))
		prepend_char(&inte, '0', f->minwid);
	if (f->sign == -1)
		prepend_str(&inte, "-");
	else if (f->plus == 1)
		prepend_str(&inte, "+");
	else if (f->space == 1)
		prepend_str(&inte, " ");
	if (f->minus == 1)
		append_char(&inte, ' ', f->minwid);
	prepend_char(&inte, ' ', f->minwid);
	f->prec = ft_strlen_p(inte);
	ft_putstr_p(inte);
	free(inte);
	return (f->prec);
}

int			print_float_e(va_list *args, t_flags *f)
{
	long double	a;
	char		*str;
	char		*frac;
	char		*inte;
	int			i;

	(f->lenmod != 7) ? (a = va_arg(*args, double)) : 0;
	if (f->lenmod == 7)
		a = va_arg(*args, long double);
	f->sign = a < 0 ? -1 : 1;
	if ((i = handle_nan(a, f, 0)) >= 0)
		return (i);
	f->prec = (f->prec < 0) ? 6 : f->prec;
	str = get_float(a);
	i = 11999;
	while (str[i] == '0' && i >= 0)
		i--;
	i = i == -1 ? 6000 : i;
	str = round_float(str, i - f->prec);
	inte = ft_strsub_p(str, i, 1);
	frac = ft_strsub_p(str, i - f->prec, f->prec);
	ft_strrev_p(frac);
	free(str);
	f->prec = (i < 6000) ? -1 : 1;
	return (apply_flags(inte, frac, ft_itoa_base((i - 6000) * f->prec, 10), f));
}
