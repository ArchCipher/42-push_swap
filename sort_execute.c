/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurugan <kmurugan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:41:28 by kmurugan          #+#    #+#             */
/*   Updated: 2025/11/06 18:43:27 by kmurugan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_cheapest_node(t_stack *src);

/*
DESCRIPTION
	It finds the node with the lowest total cost and performs rotation on both
    stacks at once. It brings the cheapest node and its target node to the top
    of the source stack and target stack, and pushes the cheapest node to the
    target stack. It prints all operations performed on standard output.
*/

void	push_cheapest_node(t_stack *src, t_stack *dst, char src_name,
		char dst_name)
{
	t_node	*node;
	int		i;

	i = 0;
	node = find_cheapest_node(src);
	while (i < node->rot_both_cost)
	{
		if (node->rotate)
			rotate_both(src, dst, UP, true);
		else
			rotate_both(src, dst, DOWN, true);
		i++;
	}
	bring_node_to_top(node, node->cost - node->rot_both_cost, src, src_name);
	bring_node_to_top(node->target, node->target->cost - node->rot_both_cost,
		dst, dst_name);
	if (src_name == STACK_A)
		push(src, dst, PB);
	else
		push(src, dst, PA);
}

/*
DESCRIPTION
	It brings a particular node to the top of the stack and prints all rotation
    operations performed on standard output.
*/

void	bring_node_to_top(t_node *node, int node_cost, t_stack *stack,
		char stack_name)
{
	while (node_cost)
	{
		if (node->rotate && stack_name == STACK_A)
			rotate(stack, RA);
		else if (node->rotate && stack_name == STACK_B)
			rotate(stack, RB);
		else if (!node->rotate && stack_name == STACK_A)
			rev_rotate(stack, RRA);
		else
			rev_rotate(stack, RRB);
		node_cost--;
	}
}

/*
DESCRIPTION
	It calculates the cost to rotate both stacks at once and the total cost of
    each node and returns the node with the lowest total cost.
*/

static t_node	*find_cheapest_node(t_stack *stack)
{
	t_node	*current;
	t_node	*cheapest;

	current = stack->first;
	cheapest = stack->first;
	while (current)
	{
		current->rot_both_cost = 0;
		if (current->rotate == current->target->rotate)
		{
			if (current->cost <= current->target->cost)
				current->rot_both_cost = current->cost;
			else
				current->rot_both_cost = current->target->cost;
		}
		current->total_cost = current->cost + current->target->cost
			- current->rot_both_cost;
		if (current->total_cost < cheapest->total_cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
