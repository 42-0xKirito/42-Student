/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:51:26 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/12 16:05:20 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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