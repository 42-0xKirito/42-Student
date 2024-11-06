/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:15:02 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/06 02:33:09 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;
	size_t	i;

	i = 0;
	dest_tmp = (unsigned char *)dest;
	src_tmp = (unsigned char *)src;
	while(i < n)
	{
		dest_tmp[i] = src_tmp[i];
		i++;
	}
	return (dest);
}