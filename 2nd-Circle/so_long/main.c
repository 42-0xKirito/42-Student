/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:48:21 by engiacom          #+#    #+#             */
/*   Updated: 2025/03/12 17:00:49 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_count(void)
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

int	mlx_main(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx,
			(data->map.map_w), (data->map.map_h), "so_long");
	set_image(data);
	set_1st_image(data);
	mlx_key_hook(data->mlx.mlx_win, key_hook, data);
	mlx_hook(data->mlx.mlx_win, 17, 1L << 0, close_winx, data);
	mlx_loop(data->mlx.mlx);
	return (0);
}

int	check_arg(char *av)
{
	char	*find;
	int		i;
	int		k;

	i = 0;
	k = 0;
	find = ".ber";
	while (av[i])
	{
		k = 0;
		while (find[k] && find[k] == av[i + k])
			k++;
		if (find[k] == av[i + k])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		if (check_arg(av[1]))
			return (1);
		data = malloc(sizeof(t_data));
		data->map.map = NULL;
		data->tmap.map = NULL;
		if (data == NULL)
			return (ft_error(data, 1), 1);
		if (cpy_map(data, av[1]))
			return (ft_error(data, 1), 1);
		if (check_map(data, av[1]))
			return (ft_error(data, 1), 1);
		mlx_main(data);
		return (0);
	}
	return (1);
}
