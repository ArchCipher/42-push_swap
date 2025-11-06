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

int main(int argc, char **argv)
{
	t_stack	a;
    t_stack	b;
	char	*line;

    if (argc < 2)
        return (0);
    ft_memset(&a, 0, sizeof(t_stack));
    ft_memset(&b, 0, sizeof(t_stack));
	if ((argc == 2 && argv[1][0] == '\0') || !init_stack_a(argc, argv + 1, &a))
        return (write(STDERR_FILENO, ERROR, 6), -1);
    while(1)
    {
		line = get_next_line(STDIN_FILENO);
        if (!line)
            break ;
		if (!parse_operation(line, &a, &b))
			return (error_handler(line, &a, &b));
		free(line);
    }
	print_output(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
