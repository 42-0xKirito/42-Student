/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 06:09:49 by engiacom          #+#    #+#             */
/*   Updated: 2025/03/06 12:38:39 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	init_collec(t_lists **collec, t_data *data)
// {
// 	int		i;
// 	t_lists	*tmp;
// 	t_lists	*tmp_p;

// 	i = data->map.c;
// 	tmp = ft_lstnewc();
// 	*collec = tmp;
// 	while (i > 0)
// 	{
// 		tmp_p = ft_lstnewc();
// 		tmp->next = tmp_p;
// 		tmp = tmp_p;
// 		i--;
// 	}
// }

// void	set_c_val(t_lists *col, int i, int k)
// {
// 	col->val = 0;
// 	col->x = i;
// 	col->y = k;
// 	col = col->next;
// }

// void	set_c_pos(t_data *data)
// {
// 	int		i;
// 	int		k;
// 	char	**tmp;
// 	t_lists	*collec;
// 	t_lists	*tmpp;

// 	tmp = data->map.map;
// 	i = 0;
// 	collec = NULL;
// 	init_collec(&collec, data);
// 	tmpp = collec;
// 	while (tmp[i])
// 	{
// 		k = 0;
// 		while (tmp[i][k])
// 		{
// 			if (tmp[i][k] == 'C')
// 				set_c_val(tmpp, i, k);
// 			k++;
// 		}
// 		i++;
// 	}
// 	data->c = *collec;
// }

// void	set_exit_pos(t_data *data)
// {
// 	int		i;
// 	int		k;
// 	char	**tmp;

// 	tmp = data->map.map;
// 	i = 0;
// 	while (tmp[i])
// 	{
// 		k = 0;
// 		while (tmp[i][k])
// 		{
// 			if (tmp[i][k] == 'E')
// 			{
// 				data->exit_pos.x = i;
// 				data->exit_pos.y = k;
// 			}
// 			k++;
// 		}
// 		i++;
// 	}
// }

void	set_player_pos(t_data *data)
{
	int		i;
	int		k;
	char	**tmp;

	tmp = data->map.map;
	i = 0;
	while (tmp[i])
	{
		k = 0;
		while (tmp[i][k])
		{
			if (tmp[i][k] == 'P')
			{
				data->play.x = i;
				data->play.y = k;
			}
			k++;
		}
		i++;
	}
}
