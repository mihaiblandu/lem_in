/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mblandu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:47:44 by mblandu           #+#    #+#             */
/*   Updated: 2018/07/11 18:53:08 by mblandu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# define ERROR -1
# define END 0
# define LINE 1
# define FD fd % 4864
# include "libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

int					get_next_line(const int fd, char **line);
typedef struct		s_line
{
	char			*tmp;
	int				define;
}					t_line;
#endif
