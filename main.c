/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 23:12:56 by mdeville          #+#    #+#             */
/*   Updated: 2017/11/23 20:31:38 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int fd;
	char *test;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	printf("%d - %s\n", get_next_line(fd, &test), test);
	free(test);
	printf("%d - %s\n", get_next_line(fd, &test), test);
	close(fd);
}
