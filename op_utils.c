#include "push_swap.h"

void    ss(t_stack **a, t_stack **b)
{
    swap(a, NULL);
    swap(b, NULL);
    write(STDOUT_FILENO, "ss\n", 3);
}

void    rotate_both(t_stack **a, t_stack **b, char direction)
{
    if (direction == 'u')
    {
        rotate(a, NULL);
        rotate(b, NULL);
        write(STDOUT_FILENO, "rr\n", 3);
        return ;
    }
    rev_rotate(a, NULL);
    rev_rotate(b, NULL);
    write(STDOUT_FILENO, "rrr\n", 4);
}

t_stack *find_last(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while(stack->next)
        stack = stack->next;
    return (stack);
}