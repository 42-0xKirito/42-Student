/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 04:24:46 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/12 05:49:13 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*set_cheapest(t_stack **a)
{
	t_stack	*tmp_a;
	t_stack	*current;

	tmp_a = *a;
	current = tmp_a;
	while (tmp_a)
	{
		if (av(current->real_cost) > av(tmp_a->real_cost))
			current = tmp_a;
		tmp_a = tmp_a->next;
	}
	return (current);
}

void	cheap_to_top(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = set_cheapest(a);
	if (cheap->cost_to_top >= 0 && cheap->target_node->cost_to_top >= 0)
		up(a, b, cheap);
	else if (cheap->cost_to_top < 0 && cheap->target_node->cost_to_top < 0)
		down(a, b, cheap);
	else if (cheap->cost_to_top < 0 && cheap->target_node->cost_to_top >= 0)
		neg_pos(a, b, cheap);
	else if (cheap->cost_to_top >= 0 && cheap->target_node->cost_to_top < 0)
		pos_neg(a, b, cheap);
	pb(a, b);
}
