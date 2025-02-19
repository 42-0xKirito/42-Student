/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 04:49:08 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/12 05:49:32 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	real_cost_pos(int ac, int atc, t_stack *tmp)
{
	if (ac > atc)
		tmp->real_cost = ac;
	else
		tmp->real_cost = atc;
}

void	real_cost_neg(int ac, int atc, t_stack *tmp)
{
	if (ac < atc)
		tmp->real_cost = av(ac);
	else
		tmp->real_cost = av(atc);
}

void	set_real_cost(t_stack **a)
{
	t_stack	*tmp;
	int		ac;
	int		atc;

	tmp = *a;
	while (tmp)
	{
		ac = tmp->cost_to_top;
		atc = tmp->target_node->cost_to_top;
		if (ac >= 0 && atc >= 0)
			real_cost_pos(ac, atc, tmp);
		else if (ac < 0 && atc < 0)
			real_cost_neg(ac, atc, tmp);
		else
			tmp->real_cost = av(ac) + av(atc);
		tmp = tmp->next;
	}
}
