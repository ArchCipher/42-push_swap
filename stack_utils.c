#include "push_swap.h"

/*
DESCRIPTION
    It initializes the stack 'a' with the values from the command line arguments.
    It handles single (spaces separated) or multiple arguments.
    Repeated values, invalid input, and overflow are considered errors.
    It returns 1 if successful, 0 in case of error.
*/

int init_stack_a(int argc, char **argv, t_stack *a)
{
    int     num;
    t_node *new;

    while ((argc > 2 && *argv) || (argc == 2  && **argv))
    {
        if (argc == 2 && a->len > 0 && **argv == ' ')
            (*argv)++;
        num = ft_atoi_mod(argv);
        if ((errno == EINVAL || errno == ERANGE)
            || (argc > 2 && **argv) || value_repeated(num, a->first))
            return (free_stack(a), 0);
        new = new_node(num);
        if (!new)
            return (free_stack(a), 0);
        append_stack(a, new);
        (a->len)++;
        if (argc > 2)
            (argv)++;
    }
    return(1);
}

/*
DESCRIPTION
    It is modified version of atoi that does not skip spaces in the beginning.
    It converts a string to an integer and returns the converted integer.
    Sets errno to EINVAL in case of invalid input, ERANGE in case of overflow
    or underflow.
    It returns the converted integer or -1 in case of error.
*/

int	ft_atoi_mod(char **str)
{
	int     num;
	int		sign;

	num = 0;
	sign = 1;
    errno = 0;
	if (**str == '-')
		sign = -1;
	if (**str == '-' || **str == '+')
		(*str)++;
    if (!ft_isdigit(**str))
       return (errno = EINVAL, -1);
	while (ft_isdigit(**str))
	{
		if ((sign == 1 && (num > INT_MAX / 10 || (num == INT_MAX / 10 && (**str - '0') > 7)))
            || (sign == -1 && (num > INT_MAX / 10 || (num == INT_MAX / 10 && (**str - '0') > 8))))
			return (errno = ERANGE, -1);
		num = (num * 10) + (**str - '0');
		(*str)++;
	}
	return (num * sign);
}

/*
DESCRIPTION
    It creates a new node with the given value and returns it.
    In case of error, it sets errno to ENOMEM and returns NULL.
*/

t_node	*new_node(int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (errno = ENOMEM, NULL);
    ft_memset(new, 0, sizeof(t_node));
	new->value = num;
	return (new);
}

/*
DESCRIPTION
    It appends a new node to the front of the stack.
*/

void    append_front(t_stack *a, t_node *new)
{
    if (!a->first)
        a->last = new;
	else
    {
        new->next = a->first;
		(a->first)->prev = new;
    }
    a->first = new;
}

/*
DESCRIPTION
    It appends a new node to the end of the stack.
*/

void    append_stack(t_stack *a, t_node *new)
{
    if (!a->last)
        a->first = new;
	else
    {
        new->prev = a->last;
		(a->last)->next = new;
    }
    a->last = new;
}

/*
DESCRIPTION
    It frees the stack.
*/

void free_stack(t_stack *a)
{
    t_node *tmp;

    if (!a || !a->first)
        return ;
    while (a->first)
    {
        tmp = a->first;
        a->first = (a->first)->next;
        free(tmp);
    }
}
