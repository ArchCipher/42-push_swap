#include "push_swap.h"

/*
	NAME
		push_swap
	SYNOPSIS
		#include "get_next_line.h"
	PROTOTYPE
		char *get_next_line(stack a);   //stack a is a list of integers
	DESCRIPTION:
		Sort stacks
	RETURN VALUE
		Returns the shortest sequence of instructions needed to sort stack a
        with the smallest number at the top. If no parameters are specified,
		it returns nothing. In case of error, it returns "Error" followed
		by an '\n' on the standard error.
	EXTERNAL FUNC(S)
		read, write, malloc, free, exit
        ft_printf, ft_libft
*/

/*
- Global variables forbidden
- Takes as an argument the stack a formatted as a list of integers.
The first argument should be at the top of the stack (be careful about the order).
- Instructions must be separated by a ’\n’ and nothing else.
- In case of error, it must display "Error" followed by an ’\n’ on the standard error.
Errors include, for example: some arguments not being integers, some arguments
exceeding the integer limits, and/or the presence of duplicates.
*/

/*-------------ERROR CASES------------------------
    - In case of error, display "Error" followed by an ’\n’ on the standard error.
    Errors include, for example: some arguments not being integers, some arguments
    exceeding the integer limits, and/or the presence of duplicates.
--------------------------------------------------*/

/* ----------------PSEUDO CODE-------------------
if argc = 1 -> return nothing
if argc = 2 and argv[1] == '\0' -> print "Error\n" on std err or return nothing?
if argc = 2 -> split
create/init stack a (add elements to stack a)
    if valid input(int) & no duplicates -> add to stack a
    else -> free stack, print "Error\n" on std err
if argc = 2 -> free argv
check if stack is sorted
    if not sorted
        if stack_len = 2 -> sa
        if stack_len = 3 -> sort 3
        else sort stacks(greedy/turk algorithm)
free stack

sa:
    if top value > bottom value
        sa

sort 3:
    if biggest on top
        r
    if biggest in middle
        rr
    sa

sort stacks:
while stack_len > 3
    init node a
        find target a (closest smaller number (in b) or biggest number (in b) in case of no smaller number)
        calculate cost
        find cheapest
    move a to b
sort 3
while b
    int node b
        find target b(closest bigger number (in a) or smallest number (in a)in case of no bigger number)
        calculate cost
        find cheapest using the cost
    move b to a
move min to top

find target:
    init best match to LONG_MIN
    find target_node
    if best match not found
        max number in b is the target_node

calculate cost to bring to top:
    if index > median -> len - index
    else -> index
    if target_node > median -> += target_stack_len - target_node_index
    else += target_node_index

move a to b:
    get cheapest of a
    if cheapest a and target_node above median -> rotate both
    else -> rev rotate both
    prep for push
    push

prep for push:
    if top node not cheapest node & above median
        r
    else
        rr

min to top:
    if above median -> ra
    else -> rra

rotate both:
    if top nodes are not the cheapest nodes
        rr both
    set current_node for a and b
---------------PSEUDO CODE----------------------*/

int main(int argc, char **argv)
{
    // t_stacks    stacks;
    t_stack *a;
    t_stack *b;
    int     a_len;

    if (argc < 2) // || (argc == 2 && argv[1][0] == '\0'))
        return (-1);
    // ft_memset(&stacks, 0, sizeof(t_stacks));
    a = NULL;
    b = NULL;
    a_len = 0;
    if (!init_stack_a(argc, argv + 1, &a, &a_len))
        return (write(STDERR_FILENO, "Error\n", 6));
    if (!stack_sorted(a))
    {
        if (a_len == 2)
            swap(&a, "sa\n");
        else if (a_len == 3)
            sort_3(&a);
        else if (a_len > 3)
            sort_stack(&a, &b, a_len);
    }
    free_stack(&a);
    return (0);
}
