/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurugan <kmurugan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:17:38 by kmurugan          #+#    #+#             */
/*   Updated: 2025/11/06 19:17:43 by kmurugan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
DESCRIPTION
	It adds the new node to the front of the stack.
*/

void	add_front(t_stack *a, t_node *new)
{
	if (!a->first)
		a->last = new;
	else
	{
		new->next = a->first;
		(a->first)->prev = new;
	}
	a->first = new;
}

/*
DESCRIPTION
	It adds the new node to the end of the stack.
*/

void	add_last(t_stack *a, t_node *new)
{
	if (!a->last)
		a->first = new;
	else
	{
		new->prev = a->last;
		(a->last)->next = new;
	}
	a->last = new;
}

/*
DESCRIPTION
	It frees the stack.
*/

void	free_stack(t_stack *a)
{
	t_node	*tmp;

	if (!a || !a->first)
		return ;
	while (a->first)
	{
		tmp = a->first;
		a->first = (a->first)->next;
		free(tmp);
	}
}
