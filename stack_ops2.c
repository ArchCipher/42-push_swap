/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurugan <kmurugan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:10:06 by kmurugan          #+#    #+#             */
/*   Updated: 2025/11/06 19:16:48 by kmurugan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
DESCRIPTION
	It swaps the first 2 elements of both stacks and if print is true, it prints
    the operation.

	ss (swap both) : sa and sb at the same time.
*/

void	swap_both(t_stack *a, t_stack *b, bool print)
{
	swap(a, NULL);
	swap(b, NULL);
	if (print)
		write(STDOUT_FILENO, SS, 3);
}

/*
DESCRIPTION
	If direction is UP, it rotates both stacks else reverse rotates both stacks.
    If print is true, it prints the operation.

	rr (rotate both) : ra and rb at the same time.
	rrr (reverse rotate both) : rra and rrb at the same time.
*/
void	rotate_both(t_stack *a, t_stack *b, char direction, bool print)
{
	if (direction == UP)
	{
		rotate(a, NULL);
		rotate(b, NULL);
		if (print)
			write(STDOUT_FILENO, RR, 3);
		return ;
	}
	rev_rotate(a, NULL);
	rev_rotate(b, NULL);
	if (print)
		write(STDOUT_FILENO, RRR, 4);
}
