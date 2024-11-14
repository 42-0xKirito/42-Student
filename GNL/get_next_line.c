/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:22:27 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/14 15:35:07 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096

char	*get_next_line(int fd)
{
	char c;
	char *res;
	int	i;
	
	res = malloc(100 * sizeof(char));
	i = 0;
	while (read(fd, &c, 1) > 0 && c != '\n')
	{
		res[i] = c;
		i++;
	}
	res[i] = 0;
	return (res);
}

#endif

#include <fcntl.h>

int	main()
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}