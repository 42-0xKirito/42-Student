/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 07:01:33 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/12 07:45:40 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_min(t_stack *a)
{
	t_stack	*min;

	if (!a)
		return (NULL);
	min = a;
	while (a)
	{
		if (a->nbr < min->nbr)
			min = a;
		a = a->next;
	}
	return (min);
}

t_stack	*find_high(t_stack *a)
{
	t_stack	*high;

	if (!a)
		return (NULL);
	high = a;
	while (a)
	{
		if (a->nbr > high->nbr)
			high = a;
		a = a->next;
	}
	return (high);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	long	n;
	int		res;

	i = 0;
	n = 0;
	res = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			res *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + nptr[i] - 48;
		i++;
	}
	return (n * res);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->nbr = content;
	new->next = NULL;
	return (new);
}
