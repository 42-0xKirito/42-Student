/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:22:27 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/14 22:55:02 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_chr_c(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	ft_chr_c_l(char *s, char c, int j)
{
	int	i;

	i = 0;
	while (s[i] && i < j)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (c == '\0' && i - 1 < j)
		return (1);
	return (0);
}

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strcat(char *src, char *dst)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(src);
	while (dst[i] && dst[i] != '\n')
	{
		src[j + i] = dst[i];
		i++;
	}
	src[i + j] = 0;
}

char	*ft_strdup(char *s)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (dst == NULL)
		return (NULL);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*get_next_line(int fd)
{
	char	*buffer =  NULL;
	static char *stash;
	char	*line;
	char	*tmp;
	int	i;
	int	j;
	
	j = 0;
	i = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	buffer[BUFFER_SIZE] = 0;
	while (!ft_chr_c(buffer, '\n') && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (!stash)
		{
			stash = malloc(4096 + 1);
			if (stash == NULL)
				return (NULL);
		}
		if (i > 0)
			ft_strcat(stash, buffer);
	}
	if (i <= 0 && !stash)
		return (NULL);
	//printf("stash = %s\n", stash);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = malloc(i + 1);
	if (line == NULL)
		return (NULL);
	while (i + 1 > 0)
	{
		line[j] = stash[j];
		j++;
		i--;
	}
	tmp = (char *)malloc(ft_strlen(stash) - ft_strlen(line) + 1);
	if (tmp == NULL)
		return (NULL);
	if (stash[j - 1] == '\n')
		j--;
	while(stash[j])
	{
		tmp[i] = stash[j];
		i++;
		j++;
	}
	tmp[i] = 0;
	free (stash);
	stash = tmp;
	printf("TEST\n");
	if (tmp)
		free (tmp);
	return (line);
}

#include <fcntl.h>

int	main()
{
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}