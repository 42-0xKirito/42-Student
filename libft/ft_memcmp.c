/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:14:08 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/06 17:24:54 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*x1;
	unsigned char	*x2;
	size_t	i;

	i = 0;
	x1 = (unsigned char *)s1;
	x2 = (unsigned char *)s2;
	while (x1[i] == x2[i] && x1[i] && x2[i] && i < n)
		i++;
	return (x1[i] - x2[i]);
}