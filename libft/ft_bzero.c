/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:47:22 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/05 18:19:58 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t	i;
	
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n - 1)
	{
		ptr[i] = 0;
		i++;
	}
}
