/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurugan <kmurugan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:19:32 by kmurugan          #+#    #+#             */
/*   Updated: 2025/11/06 18:31:09 by kmurugan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	NAME
		push_swap - sort integers using stack operations
    USAGE
        ./push_swap [list of unique integers]
	DESCRIPTION:
		Sorts a stack of integers in ascending order using swap, push, rotate and
		reverse rotate operations. Prints the optimal sequence of instructions.
        If no arguments are specified, it does nothing. In case of error, it
        prints "Error" followed by an '\n' on the standard error.
	EXTERNAL FUNC(S)
		write, malloc, free
*/

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
		return (0);
	ft_memset(&a, 0, sizeof(t_stack));
	ft_memset(&b, 0, sizeof(t_stack));
	if (!init_stack_a(argc, argv + 1, &a))
		return (write(STDERR_FILENO, ERROR, 6), -1);
	if (!stack_sorted(a.first))
	{
		if (a.len == 2)
			swap(&a, SA);
		else if (a.len == 3)
			sort_3(&a);
		else if (a.len > 3)
			sort_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}
