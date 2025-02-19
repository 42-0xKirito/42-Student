/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:57:24 by engiacom          #+#    #+#             */
/*   Updated: 2025/02/13 17:57:59 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_arg(char **argv)
{
	int	i;

	i = 0;
	if (!argv || !argv[i])
		return ;
	while (argv[i])
	{
		if (argv[i])
			free(argv[i]);
		i++;
	}
	if (argv)
		free(argv);
}

void	free_all(char **argv, int argc, t_stack *a, t_stack *b)
{
	if (argv && argc == 2)
		free_arg(argv);
	if (a)
		ft_lstclear(&a);
	if (b)
		ft_lstclear(&b);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free ((*lst));
		*lst = tmp;
	}
	*lst = NULL;
}
