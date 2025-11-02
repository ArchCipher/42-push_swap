#include "push_swap.h"

int init_stack_a(int argc, char **argv, t_stack **a, int *len)
{
    int     num;
    t_stack *new;
    t_stack *last;

    last = NULL;
    while((argc > 2 && *argv) || (argc == 2  && **argv))
    {
        if (argc == 2 && *len > 0 && **argv == ' ')
            (*argv)++;
        num = ft_atoi_mod(argv);
        if ((errno == EINVAL || errno == ERANGE)
            || (argc > 2 && **argv) || value_repeated(num, *a))
            return (free_stack(a), 0);
        new = new_stack(num, *len);
        if (!new)
            return (free_stack(a), 0);
        last = append_stack(a, last, new);
        (*len)++;
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

t_stack	*new_stack(int num, int len)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = num;
    new->index = len;
	new->next = NULL;
    new->prev = NULL;
	return (new);
}

t_stack *append_stack(t_stack **head, t_stack *last, t_stack *new)
{
    if (!last)
        *head = new;
	if (last)
    {
		(last)->next = new;
        new->prev = last;
    }
    return (new);
}

void free_stack(t_stack **a)
{
    t_stack *tmp;

    if (!a)
        return ;
    while (*a)
    {
        tmp = *a;
        *a = (*a)->next;
        free(tmp);
    }
}
