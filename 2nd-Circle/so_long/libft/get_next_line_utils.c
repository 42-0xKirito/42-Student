/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:24:53 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/17 16:35:29 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strleng(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*(ptr + i) = 0;
		i++;
	}
}

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*ptr;

// 	ptr = malloc(nmemb * size);
// 	if (ptr == NULL)
// 		return (NULL);
// 	ft_bzero(ptr, nmemb * size);
// 	return (ptr);
// }

int	ft_chr_c(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoing(char *s, char *b)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		s = (char *)ft_calloc(1, sizeof(char));
	if (!s || !b)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strleng(s) + ft_strleng(b)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s)
		while (s[++i] != '\0')
			str[i] = s[i];
	while (b[j] != '\0')
		str[i++] = b[j++];
	str[i] = '\0';
	free(s);
	return (str);
}
