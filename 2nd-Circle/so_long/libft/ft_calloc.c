/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:51:26 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/09 20:25:45 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
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