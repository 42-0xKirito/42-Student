/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:01:43 by engiacom          #+#    #+#             */
/*   Updated: 2025/03/01 12:10:21 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	alloc_map(t_data *data, char *av)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd <= 0)
		return (1);
	while (get_next_line(fd))
		i++;
	data->map.map = malloc(sizeof(char **) * (i + 1));
	if (data->map.map == NULL)
		return (1);
	data->map.map[i] = NULL;
	close(fd);
	return (0);
}

int	cpy_map(t_data *data, char *av)
{
	int	i;
	int	k;
	int	fd;
	char	*tmp;

	if (alloc_map(data, av))
		return (1);
	fd = open(av, O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (1);
	k = ft_strlen(tmp);
	i = 0;
	if (tmp[k - 1] == '\n')
		tmp[k - 1] = 0;
	while (tmp)
	{
		data->map.map[i++] = tmp;
		if (tmp[k - 1] == '\n')
			tmp[k - 1] = 0;
		tmp = get_next_line(fd);
	}
	return (close(fd), data->map.map_w = (k - 1) * 64, data->map.map_h = i * 64, 0);
}

int	alloc_tmap(t_data *data, char *av)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd <= 0)
		return (1);
	while (get_next_line(fd))
		i++;
	data->tmap.map = malloc(sizeof(char **) * (i + 1));
	if (data->tmap.map == NULL)
		return (1);
	data->tmap.map[i] = NULL;
	close(fd);
	return (0);
}

int	cpy_tmap(t_data *data, char *av)
{
	int	i;
	int	k;
	int	fd;
	char	*tmp;

	if (alloc_tmap(data, av))
		return (1);
	fd = open(av, O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (1);
	k = ft_strlen(tmp);
	i = 0;
	if (tmp[k - 1] == '\n')
		tmp[k - 1] = 0;
	while (tmp)
	{
		data->tmap.map[i++] = tmp;
		if (tmp[k - 1] == '\n')
			tmp[k - 1] = 0;
		tmp = get_next_line(fd);
	}
	return (close(fd), data->tmap.map_w = (k - 1) * 64, data->tmap.map_h = i * 64, 0);
}
