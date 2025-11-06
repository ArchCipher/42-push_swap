#include "push_swap.h"

/*
DESCRIPTION
    It performs the operations given to it on the stack.
	In case of invlid operation it returns 0.
*/

int	parse_operation(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, SA) == 0)
		swap(a, NULL);
	else if (ft_strcmp(line, SB) == 0)
		swap(b, NULL);
    else if (ft_strcmp(line, PA) == 0)
		push(b, a, NULL);
	else if (ft_strcmp(line, PB) == 0)
		push(a, b, NULL);
	else if (ft_strcmp(line, RA) == 0)
		rotate(a, NULL);
	else if (ft_strcmp(line, RB) == 0)
		rotate(b, NULL);
	else if (ft_strcmp(line, RRA) == 0)
		rev_rotate(a, NULL);
	else if (ft_strcmp(line, RRB) == 0)
		rev_rotate(b, NULL);
    else if (ft_strcmp(line, SS) == 0)
		swap_both(a, b, false);
	else if (ft_strcmp(line, RR) == 0)
		rotate_both(a, b, UP, false);
	else if (ft_strcmp(line, RRR) == 0)
		rotate_both(a, b, DOWN, false);
	else
		return (0);
	return (1);
}

/*
DESCRIPTION
	Prints "OK" if the stack is sorted in ascending order, "KO" if not followed by an '\n'
    on the standard output. It frees the stacks.
*/

void	print_output(t_stack *a, t_stack *b)
{
	if (stack_sorted(a->first) && !b->first)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

/*
DESCRIPTION
	It frees the line and stacks and prints "Error" followed by an '\n' on the standard error.
*/

int error_handler(char *line, t_stack *a, t_stack *b)
{
	free(line);
	free_stack(a);
	free_stack(b);
    write(STDERR_FILENO, ERROR, 6);
    return (-1);
}