/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:29:52 by engiacom          #+#    #+#             */
/*   Updated: 2025/01/29 17:18:55 by engiacom         ###   ########.fr       */
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
    struct s_stack  *next;
}   t_stack;

t_stack	*ft_lstnew(int content);
int	    ft_atoi(const char *nptr);
void	append_node(t_stack **a, char **argv);

#endif
