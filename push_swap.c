#include "push_swap.h"

/*
	NAME
		push_swap
	DESCRIPTION:
		Sort a stack of integers in ascending order using swap, push, rotate, reverse rotate operations.
		Prints the sequence of instructions needed to sort the stack in ascending order.
        If no parameters are specified, it does nothing.
        In case of error, it prints "Error" followed by an '\n' on the standard error.
	EXTERNAL FUNC(S)
		write, malloc, free
*/

int main(int argc, char **argv)
{
    t_stack    a;
    t_stack    b;

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
