/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:12:08 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/07 00:38:29 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] != 0)
	{
		while (i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		j++;
	}
	while (i < size)
	{
		dst[i] = 0;
		i++;
	}
	dst[i] = 0;
	return (j);
}
