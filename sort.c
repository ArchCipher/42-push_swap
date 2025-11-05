#include "push_swap.h"

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
    When pushing from A → B (when s == A), finds the closest smaller number.
    When pushing from B → A, finds the closest larger number.
*/

int check_direction(t_node *src, t_node *dst, char s)
{
    if (s == STACK_A && src-> target)
        return (dst->value < src->value && dst->value > src->target->value); 
    else if (s == STACK_A)
        return(dst->value < src->value);
    if (src->target)
        return (dst->value > src->value && dst->value < src->target->value);
    return (dst->value > src->value);
}

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
            if (check_direction(current_src, current_dst, s))
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

void    calculate_cost_to_top(t_stack *stack)
{
    t_node  *current;
    int     i;
    int     median;

    i = 0;
    current = stack->first;
    median = stack->len / 2 + 1;
    while (current && i < median)
    {
        current->cost = i++;
        current->rotate = true;
        current = current->next;
    }
    while (current && i < stack->len)
    {
        current->cost = stack->len - i++;
        current->rotate = false;
        current = current->next;
    }
}

t_node  *find_cheapest_node(t_stack *src, t_stack *dst)
{
    t_node      *current;
    t_node      *cheapest;

    calculate_cost_to_top(src);
    calculate_cost_to_top(dst);
    current = src->first;
    cheapest = src->first;
    while (current)
    {
        current->rot_both_cost = 0;
        if (current->rotate == current->target->rotate)
        {
            if (current->cost <= current->target->cost)
                current->rot_both_cost = current->cost;
            else
                current->rot_both_cost = current->target->cost;
        }
        current->total_cost = current->cost + current->target->cost - current->rot_both_cost;
        if (current->total_cost < cheapest->total_cost)
            cheapest = current;
        current = current->next;
    }
    return (cheapest);
}

void    bring_node_to_top(t_node *node, int node_cost, t_stack *stack, char stack_name)
{
    while (node_cost)
    {
        if (node->rotate && stack_name == STACK_A)
            rotate(stack, RA);
        else if (node->rotate && stack_name == STACK_B)
            rotate(stack, RB);
        else if (!node->rotate && stack_name == STACK_A)
            rev_rotate(stack, RRA);
        else
            rev_rotate(stack , RRB);
        node_cost--;
    }
}

void    push_node_to_target(t_stack *src, t_stack *dst, char src_name, char dst_name)
{
    t_node  *node;
    int     i;

    i = 0;
    node = find_cheapest_node(src, dst);
    while (i < node->rot_both_cost)
    {
        if (node->rotate)
            rotate_both(src, dst, UP);
        else
            rotate_both(src, dst, DOWN);
        i++;
    }
    bring_node_to_top(node, node->cost - node->rot_both_cost, src, src_name);
    bring_node_to_top(node->target, node->target->cost - node->rot_both_cost, dst, dst_name);
    if (src_name == STACK_A)
        push(src, dst, PB);
    else
        push(src, dst, PA);
}
