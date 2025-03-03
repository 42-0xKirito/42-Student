/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:48:21 by engiacom          #+#    #+#             */
/*   Updated: 2025/03/01 15:28:56 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_count()
{
	static int	i;

	i++;
	ft_printf("Move n⁰%d\n", i);
}

void	set_f_pos(t_lists *f, t_data *data)
{
	f->x = data->play.x;
	f->y = data->play.y;
}

void	destroy_image(t_data *data)
{
	mlx_destroy_image(data->mlx.mlx, data->collec.img);
	mlx_destroy_image(data->mlx.mlx, data->exit.img);
	mlx_destroy_image(data->mlx.mlx, data->player.img);
	mlx_destroy_image(data->mlx.mlx, data->bg.img);
}

int	close_win(int keycode, t_data *data)
{
	(void)keycode;
	ft_error(data, 0);
	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	destroy_image(data);
	if (data->mlx.mlx)
		free (data->mlx.mlx);
	if (data)
		free (data);
	exit(0);
	return(0);
}

int	mlx_main(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, (data->map.map_w), (data->map.map_h), "so_long");
	set_image(data);
	set_1st_image(data);
	mlx_key_hook(data->mlx.mlx_win, key_hook, data);
	mlx_hook(data->mlx.mlx_win, 17, 1L<<0, close_win, data);
	mlx_loop(data->mlx.mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	
	if (ac == 2)
	{
		data = malloc(sizeof(t_data));
		if (cpy_map(data, av[1]))
			return (ft_error(data, 1), 1);
		if(check_map(data, av[1]))
			return (ft_error(data, 1), 1);
		mlx_main(data);
		return (0);
	}
	return (1);
}
