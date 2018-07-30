/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:10:45 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:10:49 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list *list;

	list = *alst;
	del(list->content, list->content_size);
	free(list);
	*alst = NULL;
}
