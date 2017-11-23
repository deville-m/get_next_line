/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 21:43:28 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/20 23:17:15 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *src, size_t size, size_t newsize)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	*tmp;

	if (!src)
		return (malloc(newsize));
	res = (unsigned char *)malloc(newsize);
	if (!res)
		return (NULL);
	tmp = (unsigned char *)src;
	i = 0;
	while (i < newsize && i < size)
	{
		res[i] = tmp[i];
		i++;
	}
	free(src);
	return (res);
}
