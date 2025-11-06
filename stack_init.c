#include "push_swap.h"

static int      parse_int(char **str);
static t_node	*new_node(int num);
static int      ft_isdigit(int c);

/*
DESCRIPTION
    It initializes the stack 'a' with the values from the command line arguments.
    It handles single spaces separated argument or multiple arguments (array of strings).
    Returns 1 on success, 0 on error.
    Repeated values, invalid input, and overflow are considered errors.
*/

int init_stack_a(int argc, char **argv, t_stack *a)
{
    int     num;
    t_node *new;

    while ((argc > 2 && *argv) || (argc == 2  && **argv))
    {
        if (argc == 2 && a->len > 0 && **argv == ' ')
            (*argv)++;
        num = parse_int(argv);
        if ((errno == EINVAL || errno == ERANGE)
            || (argc > 2 && **argv) || value_repeated(num, a->first))
            return (free_stack(a), 0);
        new = new_node(num);
        if (!new)
            return (free_stack(a), 0);
        add_last(a, new);
        (a->len)++;
        if (argc > 2)
            (argv)++;
    }
    return(1);
}

/*
DESCRIPTION
    It parses an integer from a string and returns the parsed integer.
    Sets errno to EINVAL in case of invalid input, ERANGE in case of overflow or underflow.
    Returns the parsed integer or -1 on error.
*/

static int	parse_int(char **str)
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
    It creates a new node with the given integer value and returns the new node
    or NULL if the allocation fails.
*/

static t_node	*new_node(int num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
    ft_memset(new, 0, sizeof(t_node));
	new->value = num;
	return (new);
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
