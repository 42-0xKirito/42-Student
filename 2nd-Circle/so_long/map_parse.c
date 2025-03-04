/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:58:52 by engiacom          #+#    #+#             */
/*   Updated: 2025/03/04 17:20:22 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_road2(t_lists **f, t_data *data)
{
	if (data->tmap.map[(*f)->x][(*f)->y - 1] != '1' &&
			data->tmap.map[(*f)->x][(*f)->y - 1] != 'E')
	{
		if (move(data, f, (*f)->x, ((*f)->y - 1)))
			return (1);
	}
	else
		delfront(f);
	return (0);
}

int	check_road(t_lists **f, t_data *data)
{
	if (data->tmap.map[(*f)->x - 1][(*f)->y] != '1' &&
			data->tmap.map[(*f)->x - 1][(*f)->y] != 'E')
	{
		if (move(data, f, ((*f)->x - 1), (*f)->y))
			return (1);
	}
	else if (data->tmap.map[(*f)->x][(*f)->y + 1] != '1' &&
			data->tmap.map[(*f)->x][(*f)->y + 1] != 'E')
	{
		if (move(data, f, (*f)->x, ((*f)->y + 1)))
			return (1);
	}
	else if (data->tmap.map[(*f)->x + 1][(*f)->y] != '1' &&
			data->tmap.map[(*f)->x + 1][(*f)->y] != 'E')
	{
		if (move(data, f, ((*f)->x + 1), (*f)->y))
			return (1);
	}
	else if (check_road2(f, data))
		return (1);
	return (0);
}

int	check_exit(t_lists **f, t_data *data)
{
	if (data->tmap.map[(*f)->x - 1][(*f)->y] != '1')
	{
		if (move(data, f, ((*f)->x - 1), (*f)->y))
			return (1);
	}
	else if (data->tmap.map[(*f)->x][(*f)->y + 1] != '1')
	{
		if (move(data, f, (*f)->x, ((*f)->y + 1)))
			return (1);
	}
	else if (data->tmap.map[(*f)->x + 1][(*f)->y] != '1')
	{
		if (move(data, f, ((*f)->x + 1), (*f)->y))
			return (1);
	}
	else if (data->tmap.map[(*f)->x][(*f)->y - 1] != '1')
	{
		if (move(data, f, (*f)->x, ((*f)->y - 1)))
			return (1);
	}
	else
		delfront(f);
	return (0);
}

int	check_fin(t_lists *f, t_data *data)
{
	while (f)
	{
		data->tmap.map[f->x][f->y] = '1';
		if (check_exit(&f, data))
			return (1);
		if (f && data->tmap.map[f->x][f->y] == 'E')
		{
			while (f)
				delfront(&f);
			return (0);
		}
	}
	return (1);
}

int	check_if_finish(t_data *data, char *av)
{
	t_lists	*f;

	cpy_tmap(data, av);
	f = ft_lstnewc();
	if (f == NULL)
		return (1);
	data->tmap.c = data->map.c;
	set_f_pos(f, data);
	while (f)
	{
		data->tmap.map[f->x][f->y] = '1';
		if (check_road(&f, data))
			return (1);
	}
	if (data->tmap.c > 0)
		return (1);
	cpy_tmap(data, av);
	f = ft_lstnewc();
	if (f == NULL)
		return (1);
	set_f_pos(f, data);
	if (check_fin(f, data))
		return (1);
	return (0);
}
