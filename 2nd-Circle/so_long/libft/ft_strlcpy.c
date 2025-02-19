/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:12:08 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/07 18:08:01 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (src[j] != 0)
	{
		while (i < size - 1 && src[i] != 0)
		{
			dst[i] = src[i];
			i++;
		}
		j++;
	}
	dst[i] = 0;
	return (j);
}
