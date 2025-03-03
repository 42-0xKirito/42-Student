/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:58:52 by engiacom          #+#    #+#             */
/*   Updated: 2025/03/03 11:53:54 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(t_data *data, t_lists **f, int x, int y)
{
	check_col(data->tmap.map[x][y], data);
	lstadd_front(f);
	if (*f == NULL)
		return (1);
	(*f)->x = x;
	(*f)->y = y;
	return (0);
}

int	check_road(t_lists **f, t_data *data)
{
	if (data->tmap.map[(*f)->x - 1][(*f)->y] != '1' && data->tmap.map[(*f)->x - 1][(*f)->y] != 'E')
	{
		if (move(data, f, ((*f)->x - 1), (*f)->y))
			return (1);
	}
	else if (data->tmap.map[(*f)->x][(*f)->y + 1] != '1' && data->tmap.map[(*f)->x][(*f)->y + 1] != 'E')
	{
		if (move(data, f, (*f)->x, ((*f)->y + 1)))
			return (1);
	}
	else if (data->tmap.map[(*f)->x + 1][(*f)->y] != '1' && data->tmap.map[(*f)->x + 1][(*f)->y] != 'E')
	{
		if (move(data, f, ((*f)->x + 1), (*f)->y))
			return (1);
	}
	else if (data->tmap.map[(*f)->x][(*f)->y - 1] != '1' && data->tmap.map[(*f)->x][(*f)->y - 1] != 'E')
	{
		if (move(data, f, (*f)->x, ((*f)->y - 1)))
			return (1);
	}
	else
		delfront(f);
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
	int	i;

	i = 0;
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
	if (data->tmap.map)
	{
		while (data->tmap.map[i])
		{
			free (data->tmap.map[i]);
			i++;
		}
		free (data->tmap.map);
	}
	return (1);
}

int	check_if_finish(t_data *data, char *av)
{
	t_lists *f;

	cpy_tmap(data, av);
	f = ft_lstnewC();
	if (f == NULL)
		return (1);
	data->tmap.C = data->map.C;
	set_f_pos(f, data);
	while (f)
	{
		data->tmap.map[f->x][f->y] = '1';
		if (check_road(&f, data))
			return (1);
	}
	if (data->tmap.C > 0)
		return (1);
	cpy_tmap(data, av);
	f = ft_lstnewC();
	if (f == NULL)
		return (1);
	set_f_pos(f, data);
	if (check_fin(f, data))
		return (1);
	return (0);
}
