/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 05:53:28 by engiacom          #+#    #+#             */
/*   Updated: 2025/03/04 17:16:03 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_bg(t_data *data)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->bg.img, (data->val.i * 64), (data->val.k * 64));
	return (0);
}

int	put_wall(t_data *data)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->wall.img, (data->val.i * 64), (data->val.k * 64));
	return (0);
}

int	put_collec(t_data *data)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->bg.img, (data->val.i * 64), (data->val.k * 64));
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->collec.img, (data->val.i * 64), (data->val.k * 64));
	return (0);
}

int	put_exit(t_data *data)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->bg.img, (data->val.i * 64), (data->val.k * 64));
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->exit.img, (data->val.i * 64), (data->val.k * 64));
	return (0);
}

int	put_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->bg.img, (data->val.i * 64), (data->val.k * 64));
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->player.img, (data->val.i * 64), (data->val.k * 64));
	data->play.x = data->val.i;
	data->play.y = data->val.k;
	return (0);
}
