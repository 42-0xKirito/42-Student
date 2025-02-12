/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 04:50:13 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/12 05:52:48 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	target_plus(t_stack *tmp_a, t_stack *tmp_b, t_stack *b)
{
	if (tmp_a->nbr > find_high(b)->nbr)
		tmp_a->target_node = find_high(b);
	else if (tmp_a->nbr < find_min(b)->nbr)
	{
		if (find_min(b) == ft_lstlast(b))
			tmp_a->target_node = tmp_b;
		else
			tmp_a->target_node = find_min(b)->next;
	}
	else
	{
		if (tmp_a->nbr > tmp_b->nbr && tmp_a->nbr < ft_lstlast(b)->nbr)
			tmp_a->target_node = tmp_b;
		else
		{
			while (tmp_b && !(tmp_a->nbr < tmp_b->nbr
					&& tmp_a->nbr > tmp_b->next->nbr))
				tmp_b = tmp_b->next;
			tmp_a->target_node = tmp_b->next;
		}
	}
}

void	set_target_node(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a)
	{
		target_plus(tmp_a, tmp_b, *b);
		tmp_a = tmp_a->next;
	}
}
