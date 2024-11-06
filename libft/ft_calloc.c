/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:51:26 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/07 00:28:01 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_c_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n - 1)
	{
		ptr[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_c_bzero(ptr, nmemb * size);
	return (ptr);
}

// int main(void)
// {
//     int *array;
//     size_t  i;
//     size_t  nmemb = 10;

//     array = (int *)ft_calloc(nmemb, sizeof(int));
//     if (array == NULL)
//     {
//         printf("Memory allocation failed\n");
//         return (1);
//     }

//     for (i = 0; i < 10; i++)
//     {
//         printf("array[%zu] = %d\n", i, array[i]);
//     }

//     free(array);
//     return (0);
// }