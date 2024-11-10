/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:12:39 by engiacom          #+#    #+#             */
/*   Updated: 2024/11/10 01:18:42 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	head = *lst;
	while (*lst != NULL && (*lst)->next != NULL)
	{
		*lst = (*lst)->next;
	}
	if (*lst != NULL)
		(*lst)->next = new;
	else
		head = new;
	*lst = head;
}
