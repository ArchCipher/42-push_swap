/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurugan <kmurugan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:44:00 by kmurugan          #+#    #+#             */
/*   Updated: 2025/11/07 11:57:21 by kmurugan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_more_extreme(t_node *extreme, t_node *stack, char mode);

/*
DESCRIPTION
	It checks if the stack is sorted in ascending order.
*/

bool	stack_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

/*
DESCRIPTION
	It finds the extreme node (smallest or biggest) in the stack.
*/

t_node	*find_extreme_node(t_node *stack, char mode)
{
	t_node	*extreme;

	if (!stack)
		return (NULL);
	extreme = stack;
	while (stack->next)
	{
		stack = stack->next;
		if (is_more_extreme(extreme, stack, mode))
			extreme = stack;
	}
	return (extreme);
}

/*
DESCRIPTION
	It checks if a node is more extreme (smaller or bigger) than the other.
*/

static int	is_more_extreme(t_node *extreme, t_node *stack, char mode)
{
	if (mode == SMALL)
		return (stack->value < extreme->value);
	return (stack->value > extreme->value);
}
