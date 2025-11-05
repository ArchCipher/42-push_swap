#include "push_swap.h"

/*
DESCRIPTION
    It sorts a stack of 3 elements.
*/

void    sort_3(t_stack *a)
{
    t_node  *biggest;

    if (!a || !(a->first) || !(a->first)->next || !(a->first)->next->next)
        return ;
    biggest = find_extreme_node(a->first, BIG);
    if (biggest == a->first)
        rotate(a, RA);
    else if (biggest == a->first->next)
        rev_rotate(a, RRA);
    if ((a->first)->value > (a->first)->next->value)
        swap(a, SA);
}

/*
DESCRIPTION
    It sorts a stack of more than 3 elements.
*/

void    sort_stack(t_stack *a, t_stack *b)
{
    t_node  *smallest;

    push(a, b, PB);
    if (a->len > 3 && !stack_sorted(a->first))
        push(a, b, PB);
    while (a->len > 3 && !stack_sorted(a->first))
    {
        set_target(a, b, STACK_A);
        push_node_to_target(a, b, STACK_A, STACK_B);
    }
    if (!stack_sorted(a->first) && a->len == 3)
        sort_3(a);
    while (b->len)
    {
        set_target(b, a, STACK_B);
        push_node_to_target(b, a, STACK_B, STACK_A);
    }
    // update cost to op as necessary or create a function to calculate isngle cost
    calculate_cost_to_top(a);
    smallest = find_extreme_node(a->first, SMALL);
    bring_node_to_top(smallest, smallest->cost, a, STACK_A);
}

/*
DESCRIPTION
    It sets the target for the node to push to the target stack.
*/

void    set_target(t_stack *src, t_stack *dst, char s)
{
    t_node  *current_src;
    t_node  *current_dst;
    t_node  *biggest_dst;
    t_node  *smallest_dst;

    biggest_dst = find_extreme_node(dst->first, BIG);
    smallest_dst = find_extreme_node(dst->first, SMALL);
    current_src = src->first;
    while (current_src)
    {
        current_src->target = NULL;
        current_dst = dst->first;
        while (current_dst)
        {
            if (is_better_target(current_src, current_dst, s))
                current_src->target = current_dst;
            current_dst = current_dst->next;
        }
        if (s == STACK_A && current_src->target == NULL)
            current_src->target = biggest_dst;
        else if (s == STACK_B && current_src->target == NULL)
           current_src->target = smallest_dst; 
        current_src = current_src->next;
    }
}

/*
DESCRIPTION
    When pushing from A → B (when s == A), finds the closest smaller number.
    When pushing from B → A, finds the closest larger number.
*/

int is_better_target(t_node *src, t_node *dst, char s)
{
    if (s == STACK_A && src-> target)
        return (dst->value < src->value && dst->value > src->target->value); 
    else if (s == STACK_A)
        return(dst->value < src->value);
    if (src->target)
        return (dst->value > src->value && dst->value < src->target->value);
    return (dst->value > src->value);
}