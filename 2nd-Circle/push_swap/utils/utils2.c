/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:01:15 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/14 01:27:39 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	max_to_top(t_stack **b)
{
	t_stack	*high;
	t_stack	*tmp_b;

	tmp_b = *b;
	high = find_high(tmp_b);
	if (high->cost_to_top > 0)
	{
		while (*b != high)
			rb(b, 0);
	}
	if (high->cost_to_top < 0)
	{
		while (*b != high)
			rrb(b, 0);
	}
}

void	min_on_top(t_stack **a, t_stack *min)
{
	while ((*a) != min)
	{
		if (min->index <= ft_lstlast(*a)->index / 2)
			ra(a, 0);
		else
			rra(a, 0);
		set_index(*a);
	}
}

int	av(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}
