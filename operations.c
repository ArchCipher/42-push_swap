#include "push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.
*/

/*
DESCRIPTION
   It simulates a stack swap by swapping the first 2 elements
   at the top of stack. If argument includes a valid string to print,
   it prints it.
*/

// swap values: will have right indices
void    swap(t_stack **stack, char *str)
{
    int tmp;

    if (!*stack || !(*stack)->next)
        return ;
    tmp = (*stack)->value;
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = tmp;
    if (str)
        write(STDOUT_FILENO, str, 3);
}

void    push(t_stack **from, t_stack **to, char *str)
{
    t_stack *head;
    if (!from || !to || !*from)
        return ;
    head = *from;
    if ((*from)->next)
        (*from)->next->prev = NULL;
    *from = (*from)->next;
    (*to)->prev = head;
    head->next = *to;
    *to = head;
    write(STDOUT_FILENO, str, 3);
}

// switch pointers: will have wrong indices
void    rotate(t_stack **stack, char *str)
{
    t_stack *first;
    t_stack *last;
 
    if (!stack || !*stack)
        return ;
    first = *stack;
    *stack = first->next;
    (*stack)->prev = NULL;
    first->next = NULL;
    last = find_last(*stack);
    append_stack(stack, last, first);
    if (str)
        write(STDOUT_FILENO, str, 3);
}

// switch pointers: will have wrong indices
void    rev_rotate(t_stack **stack, char *str)
{
    t_stack *last;
 
    if (!stack || !*stack)
        return ;
    last = find_last(*stack);
    if (last->prev)
        last->prev->next = NULL;
    (*stack)->prev = last;
    last->next = *stack;
    last->prev = NULL;
    *stack = last;
    if (str)
        write(STDOUT_FILENO, str, 4);
}

/*---------SWAP POINTERS---------
void swap(t_stack **stack, char *str)
{
    t_stack *tmp;
   
    if (!*stack || !(*stack)->next)
        return ;
    tmp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = tmp->prev;
    tmp->next = (*stack)->next;
    if (tmp->next)
        tmp->next->prev = tmp;
    tmp->prev = *stack;
    (*stack)->next = tmp;
    if (str)
        write(STDOUT_FILENO, str, 3);
}
*/

/*--------ROTATE VALUES-----------
void    rotate(t_stack **stack, char *str)
{
    int tmp;
    t_stack *current;
 
    if (!*stack || !(*stack)->next)
        return ;
    current = *stack;
    while(current->next)
    {
        tmp = current->value;
        current->value = current->next->value;
        current->next->value = tmp;
        current = current->next;
    }
    if (str)
        write(STDOUT_FILENO, str, 3);
}
*/