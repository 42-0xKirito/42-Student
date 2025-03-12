/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:01:43 by engiacom          #+#    #+#             */
/*   Updated: 2025/03/12 16:56:23 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	alloc_map(t_data *data, char *av)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 1;
	fd = open(av, O_RDONLY);
	if (fd <= 0)
		return (1);
	tmp = get_next_line(fd);
	while (tmp)
	{
		free (tmp);
		tmp = get_next_line(fd);
		i++;
	}
	data->map.map = malloc(sizeof(char *) * (i));
	if (data->map.map == NULL)
		return (1);
	data->map.map[i - 1] = NULL;
	close(fd);
	return (0);
}

int	cpy_map(t_data *data, char *av)
{
	int		i;
	int		k;
	int		fd;
	char	*tmp;

	if (alloc_map(data, av))
		return (1);
	fd = open(av, O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (1);
	i = 0;
	k = ft_strlen(tmp);
	while (tmp)
	{
		data->map.map[i++] = tmp;
		tmp = get_next_line(fd);
	}
	if (tmp)
		free (tmp);
	data->map.map_w = (k - 1) * 64;
	data->map.map_h = i * 64;
	return (close(fd), 0);
}

void	free_tmap(t_data *data)
{
	int	i;

	i = 0;
	while (data->tmap.map[i])
	{
		free (data->tmap.map[i]);
		i++;
	}
	free (data->tmap.map);
}

int	alloc_tmap(t_data *data, char *av)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 1;
	fd = open(av, O_RDONLY);
	if (fd <= 0)
		return (1);
	tmp = get_next_line(fd);
	while (tmp)
	{
		free (tmp);
		tmp = get_next_line(fd);
		i++;
	}
	if (data->tmap.map)
		free_tmap(data);
	data->tmap.map = malloc(sizeof(char *) * (i));
	if (data->tmap.map == NULL)
		return (1);
	data->tmap.map[i - 1] = NULL;
	close(fd);
	return (0);
}

int	cpy_tmap(t_data *data, char *av)
{
	int		i;
	int		k;
	int		fd;
	char	*tmp;

	if (alloc_tmap(data, av))
		return (1);
	fd = open(av, O_RDONLY);
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (1);
	i = 0;
	k = ft_strlen(tmp);
	while (tmp)
	{
		data->tmap.map[i++] = tmp;
		tmp = get_next_line(fd);
	}
	if (tmp)
		free (tmp);
	data->tmap.map_w = (k - 1) * 64;
	data->tmap.map_h = i * 64;
	return (close(fd), 0);
}
