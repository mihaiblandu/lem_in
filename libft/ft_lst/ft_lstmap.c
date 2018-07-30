/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:11:48 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:11:51 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *rez;

	if (lst && f)
	{
		new = f(lst);
		rez = new;
		while (lst->next)
		{
			lst = lst->next;
			new->next = f(lst);
			new = new->next;
		}
		return (rez);
	}
	return (NULL);
}
