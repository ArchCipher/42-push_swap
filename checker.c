#include "push_swap.h"

parse_do_op()
{

}

print_output()
{

}

int main()
{
    char    *line;

    line = get_next_line(STDIN_FILENO);
    while(line)
    {
		free(line);
        line = get_next_line(STDIN_FILENO);
        if (!line)
            return(print_output(), 0);
		print_output();
        parse_do_op(); //should parse within gnl.
    }
	free(line);
}

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