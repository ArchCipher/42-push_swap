#include "push_swap.h"

static t_node  *find_cheapest_node(t_stack *src);

/*
DESCRIPTION
    It pushes the node to the target stack.
*/

void    push_node_to_target(t_stack *src, t_stack *dst, char src_name, char dst_name)
{
    t_node  *node;
    int     i;

    i = 0;
    node = find_cheapest_node(src);
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

/*
DESCRIPTION
    It brings the node to the top of the stack.
*/

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

/*
DESCRIPTION
    It finds the cheapest node to push to the target stack.
*/

static t_node  *find_cheapest_node(t_stack *stack)
{
    t_node      *current;
    t_node      *cheapest;

    current = stack->first;
    cheapest = stack->first;
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
