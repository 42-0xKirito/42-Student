/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:29:52 by engiacom          #+#    #+#             */
/*   Updated: 2025/01/30 16:30:20 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
    int             nbr;
	int				index;
    struct s_stack  *next;
}   t_stack;

t_stack	*ft_lstnew(int content);
int	    ft_atoi(const char *nptr);
void	append_node(t_stack **a, char **argv);
void	ra(t_stack **a);
void	rra(t_stack **a);
void	sa(t_stack **a);
t_stack	*ft_lstlast(t_stack *lst);
char	**ft_split(char const *s, char c);
void	sb(t_stack **b);

#endif