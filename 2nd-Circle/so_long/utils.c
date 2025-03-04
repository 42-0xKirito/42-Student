/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:55:36 by engiacom          #+#    #+#             */
/*   Updated: 2025/03/04 17:20:30 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lists	*ft_lstnewc(void)
{
	t_lists	*new;

	new = malloc(sizeof(t_lists));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	lstadd_front(t_lists **lst)
{
	t_lists	*new;

	new = malloc(sizeof(t_lists));
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void	delfront(t_lists **f)
{
	t_lists	*tmp;

	if (*f)
	{
		tmp = *f;
		*f = (*f)->next;
		free(tmp);
	}
}

void	check_col(char c, t_data *data)
{
	if (c == 'C')
		data->tmap.c--;
}

void	ft_error(t_data *data, int x)
{
	int	i;

	i = 0;
	if (data->map.map)
	{
		while (data->map.map[i])
			free (data->map.map[i++]);
		free (data->map.map);
	}
	i = 0;
	if (data->tmap.map)
	{
		while (data->tmap.map[i])
			free (data->tmap.map[i++]);
		free (data->tmap.map);
	}
	if (data)
		free (data);
	if (x == 1)
		ft_printf("Error\n");
}
