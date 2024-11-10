/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 01:37:01 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/10 03:35:53 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while ((*lst) && (*lst)->next != NULL)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free ((*lst));
		*lst = tmp;
	}
	if ((*lst) != NULL)
		del((*lst)->content);
	free ((*lst));
	*lst = NULL;
}
