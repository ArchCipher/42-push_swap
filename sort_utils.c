# include "push_swap.h"

static int  is_more_extreme(t_node *extreme, t_node *stack, char mode);

/*
DESCRIPTION
    It checks if a value is repeated in the stack.
*/

bool value_repeated(int num, t_node *a)
{
    while (a)
    {
        if (a->value == num)
            return (true);
        a = a->next;
    }
    return (false);
}

/*
DESCRIPTION
    It checks if the stack is sorted in ascending order.
*/

bool stack_sorted(t_node *a)
{
    while (a && a->next)
    {
        if (a->value > a->next->value)
            return (false);
        a = a->next;
    }
    return (true);
}

/*
DESCRIPTION
    It finds the extreme node (smallest or biggest) in the stack.
*/

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

/*
DESCRIPTION
    It checks if a node is more extreme (smaller or bigger) than the other.
*/

static int  is_more_extreme(t_node *extreme, t_node *stack, char mode)
{
    if (mode == SMALL)
        return(stack->value < extreme->value);
    return (stack->value > extreme->value);
}
