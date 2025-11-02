#include "push_swap.h"

void    sort_3(t_stack **a)
{
    t_stack *biggest;

    if (!*a || !(*a)->next || !(*a)->next->next)
        return ;
    biggest = find_biggest(*a, 3);
    if (biggest->index == 0)
        rotate(a, "ra\n");
    else if (biggest->index == 1)
        rev_rotate(a, (*a)->next->next, "rra\n");
    if ((*a)->value > (*a)->next->value)
        swap(a, "sa\n");
}

void    sort_stack(t_stack **a, t_stack **b, int a_len)
{
    int b_len;

    b_len = 0;
    while(a_len > 3)
    {
        if ()
        push(a, b, "pa\n");
        a_len--;
        b_len++;
    }
}