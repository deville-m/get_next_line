/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:16:52 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/15 21:02:11 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>

static size_t	fill(char *dest, const char *src)
{
	size_t i;

	i = 0;
	while ()
}

int				get_next_line(const int fd, char **line)
{
	size_t		nb;
	static char	buffer[BUFF_SIZE];

	if (!line || !*line)
		return (-1);
	while ((nb = read(fd, buffer, BUFF_SIZE)) > 0 && )
	{
		fill()
	}
	return (() ? )
}
