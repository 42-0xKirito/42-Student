/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:04:07 by engiacom          #+#    #+#             */
/*   Updated: 2025/03/12 17:06:00 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rm_nl(t_data *data)
{
	int	i;
	int	k;
	int	len;

	i = 0;
	len = (ft_strleng(data->map.map[i]) - 1);
	while (data->map.map[i])
	{
		k = 0;
		while (data->map.map[i][k] && data->map.map[i][k] != '\n')
			k++;
		if (k != len)
			return (1);
		if (data->map.map[i][k] == '\n')
			data->map.map[i][k] = '\0';
		i++;
	}
	return (0);
}

int	check_char(t_data *data)
{
	int	i;
	int	k;

	i = 0;
	while (data->map.map[i])
	{
		k = 0;
		while (data->map.map[i][k])
		{
			if (data->map.map[i][k] == '0' || data->map.map[i][k] == '1' ||
				data->map.map[i][k] == 'P' || data->map.map[i][k] == 'C' ||
				data->map.map[i][k] == 'E')
				k++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}
