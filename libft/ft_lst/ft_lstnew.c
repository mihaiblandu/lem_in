/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:12:20 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/29 15:12:23 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	char	*str;

	if ((list = (t_list *)malloc(sizeof(t_list))))
	{
		if (!content)
		{
			content_size = 0;
			str = NULL;
		}
		else
		{
			str = malloc(content_size);
			str = ft_strncpy(str, content, content_size);
		}
		list->content_size = content_size;
		list->content = str;
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
