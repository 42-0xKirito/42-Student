/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:48:21 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/19 06:14:03 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cpy_map(t_data *data)
{
	int	i;
	int	k;
	int	fd;
	char	*tmp;

	i = 0;
	fd = open("./map/map.ber", O_RDONLY);
	while (get_next_line(fd))
		i++;
	data->map.map = malloc(sizeof(char **) * (i + 1));
	close(fd);
	fd = open("./map/map.ber", O_RDONLY);
	tmp = get_next_line(fd);
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
	return (close(fd), data->map.map_w = (k - 1) * 64, data->map.map_h = i * 64);
}

t_col	*ft_lstnewC()
{
	t_col	*new;

	new = malloc(sizeof(t_col));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	return (new);
}

int	main()
{
	t_data	data;
	
	cpy_map(&data);
	if(check_map(&data))
	{
		return (1);
	}
	set_C_pos(&data);
	printf("%d\n", data.map.C);
	data.mlx.mlx = mlx_init();
	data.mlx.mlx_win = mlx_new_window(data.mlx.mlx, (data.map.map_w), (data.map.map_h), "so_long");
	set_image(&data);
	set_1st_image(&data);
	mlx_key_hook(data.mlx.mlx_win, key_hook, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
