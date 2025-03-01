/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 05:55:01 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/27 17:41:22 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_left(t_data *data)
{
	if (data->map.map[(data->play.y)][data->play.x - 1] != '1' && data->map.map[(data->play.y)][data->play.x - 1] != 'E')
	{
		if (data->map.map[(data->play.y)][data->play.x - 1] == 'C')
		{
			data->map.map[(data->play.y)][data->play.x - 1] = '0';
			data->map.C--;
		}
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->bg.img, (data->play.x * 64), (data->play.y * 64));
		data->play.x -= 1;
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->bg.img, (data->play.x * 64), (data->play.y * 64));
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->player.img, (data->play.x * 64), (data->play.y * 64));
		move_count();
	}
	else if (data->map.map[(data->play.y)][data->play.x - 1] == 'E' && data->map.C == 0)
		printf("GG\n");
	return (0);
}

int	move_right(t_data *data)
{
	if (data->map.map[(data->play.y)][data->play.x + 1] != '1' && data->map.map[(data->play.y)][data->play.x + 1] != 'E')
	{
		if (data->map.map[(data->play.y)][data->play.x + 1] == 'C')
		{
			data->map.map[(data->play.y)][data->play.x + 1] = '0';
			data->map.C--;
		}
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->bg.img, (data->play.x * 64), (data->play.y * 64));
		data->play.x += 1;
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->bg.img, (data->play.x * 64), (data->play.y * 64));
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->player.img, (data->play.x * 64), (data->play.y * 64));
		move_count();
	}
	else if (data->map.map[(data->play.y)][data->play.x + 1] == 'E' && data->map.C == 0)
		printf("GG\n");
	return (0);
}

int	move_up(t_data *data)
{
	if (data->map.map[(data->play.y - 1)][data->play.x] != '1' && data->map.map[(data->play.y - 1)][data->play.x] != 'E')
	{
		if (data->map.map[(data->play.y - 1)][data->play.x] == 'C')
		{
			data->map.map[(data->play.y - 1)][data->play.x] = '0';
			data->map.C--;
		}
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->bg.img, (data->play.x * 64), (data->play.y * 64));
		data->play.y -= 1;
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->bg.img, (data->play.x * 64), (data->play.y * 64));
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->player.img, (data->play.x * 64), (data->play.y * 64));
		move_count();
	}
	else if (data->map.map[(data->play.y - 1)][data->play.x] == 'E' && data->map.C == 0)
		printf("GG\n");
	return (0);
}

int	move_down(t_data *data)
{
	if (data->map.map[(data->play.y + 1)][data->play.x] != '1' && data->map.map[(data->play.y + 1)][data->play.x] != 'E')
	{
		if (data->map.map[(data->play.y + 1)][data->play.x] == 'C')
		{
			data->map.map[(data->play.y + 1)][data->play.x] = '0';
			data->map.C--;
		}
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->bg.img, (data->play.x * 64), (data->play.y * 64));
		data->play.y += 1;
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->bg.img, (data->play.x * 64), (data->play.y * 64));
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win, data->player.img, (data->play.x * 64), (data->play.y * 64));
		move_count();
	}
	else if (data->map.map[(data->play.y + 1)][data->play.x] == 'E' && data->map.C == 0)
		printf("GG\n");
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 0 || keycode == 123)
		move_left(data);
	else if (keycode == 2 || keycode == 124)
		move_right(data);
	else if (keycode == 13 || keycode == 126)
		move_up(data);
	else if (keycode == 1 || keycode == 125)
		move_down(data);
	else if (keycode == 53)
		close_win(53, data);
	return (0);
}
