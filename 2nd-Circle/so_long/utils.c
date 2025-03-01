/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:55:36 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/27 17:16:20 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lists	*ft_lstnewC()
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
	t_lists *new;
	
	new = malloc(sizeof(t_lists));
	if (new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void delfront(t_lists **f)
{
	t_lists *tmp;

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
		data->tmap.C--;
}
void	ft_error(t_data *data, int x)
{
	if (data->map.map)
		free (data->map.map);
	if (data->tmap.map)
		free (data->tmap.map);
	if (x == 1)
		ft_printf("Error\n");
}
