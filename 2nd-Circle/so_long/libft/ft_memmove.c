/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:45:58 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/07 00:31:12 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;
	size_t			i;

	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			dest_tmp[i] = src_tmp[i];
		}
	}
	else if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			dest_tmp[i] = src_tmp[i];
			i++;
		}
	}
	return (dest);
}
