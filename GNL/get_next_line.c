/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:22:27 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/14 13:21:26 by engiacom         ###   ########.fr       */
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
	
	res = malloc(BUFFER_SIZE * sizeof(char));
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
}