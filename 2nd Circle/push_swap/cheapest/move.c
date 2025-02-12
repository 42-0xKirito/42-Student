/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 04:08:32 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/12 05:49:23 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	down(t_stack **a, t_stack **b, t_stack *cheap)
{
	int	i;
	int	j;

	i = cheap->cost_to_top;
	j = cheap->target_node->cost_to_top;
	while (i < 0 && j < 0)
	{
		rrr(a, b);
		i++;
		j++;
	}
	while (i < 0)
	{
		rra(a, 0);
		i++;
	}
	while (j < 0)
	{
		rrb(b, 0);
		j++;
	}
}

void	up(t_stack **a, t_stack **b, t_stack *cheap)
{
	int	i;
	int	j;

	i = cheap->cost_to_top;
	j = cheap->target_node->cost_to_top;
	while (i > 0 && j > 0)
	{
		rr(a, b);
		i--;
		j--;
	}
	while (i > 0)
	{
		ra(a, 0);
		i--;
	}
	while (j > 0)
	{
		rb(b, 0);
		j--;
	}
}

void	neg_pos(t_stack **a, t_stack **b, t_stack *cheap)
{
	int	i;
	int	j;

	i = cheap->cost_to_top;
	j = cheap->target_node->cost_to_top;
	while (i < 0)
	{
		rra(a, 0);
		i++;
	}
	while (j > 0)
	{
		rb(b, 0);
		j--;
	}
}

void	pos_neg(t_stack **a, t_stack **b, t_stack *cheap)
{
	int	i;
	int	j;

	i = cheap->cost_to_top;
	j = cheap->target_node->cost_to_top;
	while (i > 0)
	{
		ra(a, 0);
		i--;
	}
	while (j < 0)
	{
		rrb(b, 0);
		j++;
	}
}
