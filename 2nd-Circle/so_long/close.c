/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:30:26 by engiacom          #+#    #+#             */
/*   Updated: 2025/03/06 13:07:53 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_image(t_data *data)
{
	if (data->collec.img)
		mlx_destroy_image(data->mlx.mlx, data->collec.img);
	if (data->wall.img)
		mlx_destroy_image(data->mlx.mlx, data->wall.img);
	if (data->exit.img)
		mlx_destroy_image(data->mlx.mlx, data->exit.img);
	if (data->player.img)
		mlx_destroy_image(data->mlx.mlx, data->player.img);
	if (data->bg.img)
		mlx_destroy_image(data->mlx.mlx, data->bg.img);
}

int	close_winx(t_data *data)
{
	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	destroy_image(data);
	mlx_destroy_display(data->mlx.mlx);
	if (data->mlx.mlx)
		free (data->mlx.mlx);
	ft_error(data, 0);
	exit(0);
	return (0);
}

int	close_win(int keycode, t_data *data)
{
	(void)keycode;
	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	destroy_image(data);
	mlx_destroy_display(data->mlx.mlx);
	if (data->mlx.mlx)
		free (data->mlx.mlx);
	ft_error(data, 0);
	exit (0);
	return (0);
}
