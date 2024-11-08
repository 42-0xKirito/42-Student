/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:04:38 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/07 19:54:18 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*res;
	size_t		len;

	len = (ft_strlen(s1) + ft_strlen(s2));
	res = ft_calloc((len + 1) * sizeof(char), 1);
	if (res == NULL)
		return (NULL);
	ft_strlcat(res, s1, ft_strlen(s1) + 1);
	ft_strlcat(res, s2, (ft_strlen(res) + ft_strlen(s2)) + 1);
	return (res);
}
