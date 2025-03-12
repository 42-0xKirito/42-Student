/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 05:57:34 by engiacom          #+#    #+#             */
/*   Updated: 2025/03/12 17:04:32 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(t_data *data)
{
	int		i;
	int		k;
	char	**map;

	i = 0;
	map = data->map.map;
	k = (int)ft_strlen(map[i]);
	while (map[i])
	{
		if (k != (int)ft_strlen(map[i]))
			return (1);
		i++;
	}
	return (0);
}

void	set_item(char **map, int i, int k, t_data *data)
{
	if (map[i][k] == 'C')
		data->map.c++;
	else if (map[i][k] == 'P')
		data->map.p++;
	else if (map[i][k] == 'E')
		data->map.e++;
}

int	check_item(t_data *data)
{
	int		i;
	int		k;
	char	**map;

	i = 0;
	data->map.c = 0;
	data->map.p = 0;
	data->map.e = 0;
	map = data->map.map;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			set_item(map, i, k, data);
			k++;
		}
		i++;
	}
	if (data->map.e != 1 || data->map.p != 1 || data->map.c == 0)
		return (1);
	return (0);
}

int	check_wall(t_data *data)
{
	int		i;
	int		k;
	char	**map;

	i = 0;
	k = 0;
	map = data->map.map;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if ((i == 0 || k == 0) && map[i][k] != '1')
				return (1);
			if (i == (data->map.map_h / 64) - 1 && map[i][k] != '1')
				return (1);
			k++;
		}
		if (map[i][k - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_map(t_data *data, char *av)
{
	if (rm_nl(data))
		return (1);
	if (check_char(data))
		return (1);
	if (check_rectangle(data))
		return (1);
	if (check_wall(data))
		return (1);
	if (check_item(data))
		return (1);
	set_player_pos(data);
	if (check_if_finish(data, av))
		return (1);
	return (0);
}
