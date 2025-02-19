/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 04:26:41 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/12 05:51:25 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*set_fs(t_stack *a)
{
	a->cost_to_top = 0;
	if (a->next)
	{
		a = a->next;
		a->cost_to_top = 1;
	}
	if (a->next)
		return (a->next);
	return (a);
}

int	set_half(t_stack *a, int half)
{
	if (ft_lstlast(a)->index % 2 == 0)
		return (half = ft_lstlast(a)->index / 2);
	else
		return (half = (ft_lstlast(a)->index / 2) + 1);
}

void	set_index(t_stack *stack)
{
	int	i;

	i = 1;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void	set_cost_top(t_stack *a)
{
	t_stack	*tmp;
	int		i;
	int		half;

	tmp = a;
	half = set_half(a, 0);
	tmp = set_fs(tmp);
	i = 2;
	while (tmp && tmp->index <= half)
	{
		tmp->cost_to_top = i;
		tmp = tmp->next;
		i++;
	}
	if ((ft_lstlast(a)->index % 2) != 0)
		i--;
	while (tmp && tmp->next && tmp->index > half)
	{
		tmp->cost_to_top = -i;
		tmp = tmp->next;
		i--;
	}
	if (ft_lstlast(a)->index > 2)
		tmp->cost_to_top = -i;
}
