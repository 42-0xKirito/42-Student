/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:30:21 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/12 05:54:13 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*high;

	high = find_high(*a);
	if (high->index == 1)
	{
		ra(a, 0);
		set_index(*a);
	}
	if (high->index == 2)
	{
		rra(a, 0);
		set_index(*a);
	}
	if ((*a)->nbr > (*a)->next->nbr)
	{
		sa(a, 0);
		set_index(*a);
	}
	return ;
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = find_min(*a);
	min_on_top(a, min);
	pb(a, b);
	set_index(*a);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = find_min(*a);
	min_on_top(a, min);
	pb(a, b);
	set_index(*a);
	min = find_min(*a);
	min_on_top(a, min);
	pb(a, b);
	set_index(*a);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
