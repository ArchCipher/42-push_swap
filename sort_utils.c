# include "push_swap.h"

int value_repeated(int num, t_node *a)
{
    while (a)
    {
        if (a->value == num)
            return (1);
        a = a->next;
    }
    return (0);
}

int stack_sorted(t_node *a)
{
    while (a && a->next)
    {
        if (a->value > a->next->value)
            return (0);
        a = a->next;
    }
    return (1);
}

int is_more_extreme(t_node *extreme, t_node *stack, char mode)
{
    if (mode == SMALL)
        return(stack->value < extreme->value);
    return (stack->value > extreme->value);
}

t_node  *find_extreme_node(t_node *stack, char mode)
{
    t_node *extreme;

    if (!stack)
        return (NULL);
    extreme = stack;
    while (stack->next)
    {
        stack = stack->next;
        if (is_more_extreme(extreme, stack, mode))
            extreme = stack;
    }
    return (extreme);
}
