# include "push_swap.h"

int value_repeated(int num, t_stack *a)
{
    while(a != NULL && a->value)
    {
        if (a->value == num)
            return (1);
        a = a->next;
    }
    return (0);
}

int stack_sorted(t_stack *a)
{
    while(a && a->next)
    {
        if (a->value > a->next->value)
            return (0);
        a = a->next;
    }
    return (1);
}

int len_sorted(t_stack *a)
{
    t_stack *last;
    int len;

    len = 0;
    last = find_last(a);
    if (!last)
        return (0);
    while(last->prev && last->value > last->prev->value)
        last = last->prev;
    return (len);
}

t_stack *find_biggest(t_stack *a, int count)
{
    t_stack *biggest;

    if (!a)
        return (NULL);
    biggest = a;
    while (count-- > 1 && a->next)
    {
        a = a->next;
        if (biggest->value < a->value)
            biggest = a;
    }
    return (biggest);
}
