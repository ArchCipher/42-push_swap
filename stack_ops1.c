/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurugan <kmurugan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:06:22 by kmurugan          #+#    #+#             */
/*   Updated: 2025/11/06 19:09:36 by kmurugan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
DESCRIPTION
	It swaps the first 2 elements at the top of stack.
	If argument includes a string (sa or sb) to print, it prints it.

	sa (swap a): Swap the first 2 elements at the top of stack a.
	Does nothing if there is only one element or none.
	sb (swap b): Swap the first 2 elements at the top of stack b.
	Does nothing if there is only one element or none.
*/

void	swap(t_stack *stack, char *str)
{
	int	tmp;

	if (!stack || !(stack->first) || !(stack->first)->next)
		return ;
	tmp = (stack->first)->value;
	(stack->first)->value = (stack->first)->next->value;
	(stack->first)->next->value = tmp;
	if (str)
		write(STDOUT_FILENO, str, 3);
}

/*
DESCRIPTION
	It pushes one element from one stack to another.
	If argument includes a string (pa or pb) to print, it prints it.
	It prints pa or pb along with a newline.

	pa (push a): Take the first element at the top of b and put it at the top
    of a. Does nothing if b is empty.
	pb (push b): Take the first element at the top of a and put it at the top
    of b. Does nothing if a is empty.
*/

void	push(t_stack *src, t_stack *dst, char *str)
{
	t_node	*first;

	if (!src || !dst || !src->first)
		return ;
	first = src->first;
	src->first = first->next;
	if (src->first)
		(src->first)->prev = NULL;
	else
		src->last = NULL;
	first->next = NULL;
	add_front(dst, first);
	(src->len)--;
	(dst->len)++;
	if (str)
		write(STDOUT_FILENO, str, 3);
}

/*
DESCRIPTION
	It takes the first element from the stack and moves it to the end.
	If argument includes a string (ra or rb) to print, it prints it.

	ra (rotate a): Shift up all elements of stack a by 1.
	The first element becomes the last one.
	rb (rotate b): Shift up all elements of stack b by 1.
	The first element becomes the last one.
*/

void	rotate(t_stack *stack, char *str)
{
	t_node	*first;

	if (!stack || !stack->first || !stack->last || stack->first == stack->last)
		return ;
	first = stack->first;
	stack->first = first->next;
	if (stack->first)
		(stack->first)->prev = NULL;
	first->next = NULL;
	add_last(stack, first);
	if (str)
		write(STDOUT_FILENO, str, 3);
}

/*
DESCRIPTION
	It takes the last element from the stack and moves it to the beginning.
	If argument includes a string (rra or rrb) to print, it prints it.

	rra (reverse rotate a): Shift down all elements of stack a by 1.
	The last element becomes the first one.
	rrb (reverse rotate b): Shift down all elements of stack b by 1.
	The last element becomes the first one.
*/

void	rev_rotate(t_stack *stack, char *str)
{
	t_node	*last;

	if (!stack || !stack->first || !stack->last || stack->first == stack->last)
		return ;
	last = stack->last;
	stack->last = last->prev;
	(stack->last)->next = NULL;
	last->prev = NULL;
	add_front(stack, last);
	if (str)
		write(STDOUT_FILENO, str, 4);
}
