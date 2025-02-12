/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 04:21:41 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/12 07:37:26 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	if (ft_lstlast(*a)->index == 2)
		sa(a, 0);
	else if (ft_lstlast(*a)->index == 3)
		sort_three(a);
	else if (ft_lstlast(*a)->index == 4)
		sort_four(a, b);
	else if (ft_lstlast(*a)->index == 5)
		sort_five(a, b);
	else
	{
		pb(a, b);
		pb(a, b);
		if ((*b)->nbr < (*b)->next->nbr)
			sb(b, 0);
		sort_big(a, b);
	}
}

void	spam_min(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (ft_lstlast(*a)->index != 5)
	{
		set_index(*a);
		min_on_top(a, find_min(*a));
		pb(a, b);
		i++;
	}
	sort_five(a, b);
	while (i > 0)
	{
		pa(a, b);
		i--;
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	while (*a)
	{
		init_all(a, b);
		if (ft_lstlast(*a)->index <= (set_half(*b, 0) * 0.15))
		{
			if (!stack_sorted(*a))
				spam_min(a, b);
			max_to_top(b);
			final_sort(a, b);
			return ;
		}
		cheap_to_top(a, b);
	}
}

void	final_sort(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = ft_lstlast(*a);
	while (tmp->nbr > (*b)->nbr)
	{
		rra(a, 0);
		tmp = ft_lstlast(*a);
	}
	while (*b)
	{
		if (tmp->nbr < (*a)->nbr && tmp->nbr > (*b)->nbr)
		{
			rra(a, 0);
			tmp = ft_lstlast(*a);
		}
		else
			pa(a, b);
	}
	if ((*a)->nbr > ft_lstlast(*a)->nbr)
		rra(a, 0);
}
