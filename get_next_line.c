/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:16:52 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/23 20:25:21 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>

static char		*copy(char *tmp, int *offset)
{
	char	*res;
	size_t	i;
	size_t	j;
	size_t	max;

	i = 0 + *offset;
	j = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		j += 1;
		i += 1;
	}
	max = j;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = '\0';
	i = 0 + *offset;
	j = 0;
	while (j < max)
		res[j++] = tmp[i++];
	while (tmp[i++] == '\n');
	*offset = (!tmp[i]) ? 0 : i;
	return (res);
}

static t_clist	*getcontent(t_clist **alst, int fd)
{
	t_clist *tmp;

	if (!alst || fd < 0)
		return (NULL);
	tmp = *alst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return tmp;
		tmp = tmp->next;
	}
	tmp = (t_clist *)malloc(sizeof(t_clist));
	if (!tmp)
		return (NULL);
	tmp->fd = fd;
	tmp->next = *alst;
	tmp->offset = 0;
	*alst = tmp;
	return (*alst);
}

static void		delclist(t_clist **lst, t_clist *buff)
{
	t_clist		*curr;
	t_clist		*prev;

	curr = *lst;
	prev = NULL;
	while (curr)
	{
		if (curr == buff)
		{
			if (prev)
				prev->next = curr->next;
			else
				*lst = (*lst)->next;
			free(curr->next);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_clist	*lst = NULL;
	t_clist			*b;
	char			*tmp;
	int				nb;

	if (fd < 0 || read(fd, "", 0) < 0 || !line || !(b = getcontent(&lst, fd)))
		return (-1);
	if (b->offset)
	{
		*line = copy(b->buff, &b->offset);
		if (!*line)
		{
			delclist(&lst, b);
			return (-1);
		}
		if (b->offset)
			return (1);
	}
	else
		tmp = ft_strnew(1);
	while((nb = read(fd, b->buff, BUFF_SIZE)))
	{
		b->buff[nb] = '\0';
		*line = tmp;
		tmp = ft_strjoin(tmp, b->buff);
		free(*line);
		if ((*line = ft_strchr(tmp, '\n')))
		{
			b->offset = 0;
			*line = copy(tmp, &b->offset);
			free(tmp);
			return (1);
		}
	}
	return (0);
}
