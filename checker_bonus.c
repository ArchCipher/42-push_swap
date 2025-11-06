#include "push_swap.h"

/*
	NAME
		checker
	DESCRIPTION:
		Reads instructions from STDIN, performs the operations on the stack and checks
        if the stack is sorted in ascending order.
		Prints "OK" if the stack is sorted in ascending order, "KO" if not followed by an '\n'
        on the standard output.
        In case of error, it prints "Error" followed by an '\n' on the standard error.
	EXTERNAL FUNC(S)
		read, write, malloc, free
*/

int		parse_operation(char *line, t_stack *a, t_stack *b);
void	print_output(t_stack *a, t_stack *b);
int     error_handler(char *line, t_stack *a, t_stack *b);

int main(int argc, char **argv)
{
	t_stack	a;
    t_stack	b;
	char	*line;

    if (argc < 2)
        return (0);
    ft_memset(&a, 0, sizeof(t_stack));
    ft_memset(&b, 0, sizeof(t_stack));
	if (!init_stack_a(argc, argv + 1, &a))
        return (write(STDERR_FILENO, ERROR, 6), -1);
    while(1)
    {
		line = get_next_line(STDIN_FILENO);
        if (!line)
            return(print_output(&a, &b), 0);
		if (!parse_operation(line, &a, &b))
			return (error_handler(line, &a, &b));
		free(line);
    }
	return (0);
}

int	parse_operation(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, SA) == 0)
		swap(a, NULL);
	else if (ft_strcmp(line, SB) == 0)
		swap(b, NULL);
	else if (ft_strcmp(line, SS) == 0)
		swap_both(a, b, false);
	else if (ft_strcmp(line, RA) == 0)
		rotate(a, NULL);
	else if (ft_strcmp(line, RB) == 0)
		rotate(b, NULL);
	else if (ft_strcmp(line, RRA) == 0)
		rev_rotate(a, NULL);
	else if (ft_strcmp(line, RRB) == 0)
		rev_rotate(b, NULL);
	else if (ft_strcmp(line, RR) == 0)
		rotate_both(a, b, UP, false);
	else if (ft_strcmp(line, RRR) == 0)
		rotate_both(a, b, DOWN, false);
	else
		return (0);
	return (1);
}

void	print_output(t_stack *a, t_stack *b)
{
	if (stack_sorted(a->first))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
	free_stack(b);
}

int error_handler(char *line, t_stack *a, t_stack *b)
{
	free(line);
	free_stack(a);
	free_stack(b);
    write(STDERR_FILENO, ERROR, 6);
    return (-1);
}