#include "push_swap.h"

/*
	NAME
		push_swap
	DESCRIPTION:
		Sort a stack of integers using the least number of instructions.
	RETURN VALUE
		Returns the shortest sequence of instructions needed to sort the stack
        in ascending order. If no parameters are specified, it returns nothing.
        In case of error, it returns "Error" followed by an '\n' on the standard error.
	EXTERNAL FUNC(S)
		read, write, malloc, free, exit
        ft_printf, ft_libft
*/

/*
void    print_stack(t_node *a)
{
    int count = 0;
    while (a)
    {
        printf("[%d]: %d\n", count, a->value);
        a = a->next;
        count++;
    }
}
*/

int main(int argc, char **argv)
{
    t_stack    a;
    t_stack    b;

    if (argc < 2 || (argc == 2 && argv[1][0] == '\0'))
        return (-1);
    ft_memset(&a, 0, sizeof(t_stack));
    ft_memset(&b, 0, sizeof(t_stack));
    if (!init_stack_a(argc, argv + 1, &a))
        return (write(STDERR_FILENO, "Error\n", 6), -1);
    if (!stack_sorted(a.first))
    {
        if (a.len == 2)
            swap(&a, "sa\n");
        else if (a.len == 3)
            sort_3(&a);
        else if (a.len > 3)
            sort_stack(&a, &b);
    }
    free_stack(&a);
    return (0);
}
