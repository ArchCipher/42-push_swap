/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurugan <kmurugan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:54:43 by kmurugan          #+#    #+#             */
/*   Updated: 2025/11/07 11:57:39 by kmurugan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		parse_int(char **str, int argc);
static t_node	*new_node(int num);
static int		int_overflow(int num, int digit);
static bool		int_repeated(int num, t_node *a);

/*
DESCRIPTION
	It initializes the stack 'a' with the values from the command line arguments.
	It handles both single space separated argument and multiple arguments
	(array of strings). Returns 1 on success, 0 on error. Repeated values,
	invalid input, integer overflow / underflow are considered errors.
*/

int	init_stack_a(int argc, char **argv, t_stack *a)
{
	int		num;
	t_node	*new;

	while ((argc > 2 && *argv) || (argc == 2 && **argv))
	{
		if (argc == 2 && a->len > 0 && **argv == ' ')
			(*argv)++;
		num = parse_int(argv, argc);
		if (errno || int_repeated(num, a->first))
			return (free_stack(a), 0);
		new = new_node(num);
		if (!new)
			return (free_stack(a), 0);
		add_last(a, new);
		(a->len)++;
		if (argc > 2)
			(argv)++;
	}
	return (1);
}

/*
DESCRIPTION
	It parses an integer from a string and returns the parsed integer or '-1'
	on error. Sets errno to EINVAL or ERANGE in case of invalid input, or
	overflow / underflow.
*/

static int	parse_int(char **str, int argc)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	errno = 0;
	if (**str == '-')
		sign = -1;
	if (**str == '-' || **str == '+')
		(*str)++;
	if (!(**str >= '0' && **str <= '9'))
		return (errno = EINVAL, -1);
	while (**str >= '0' && **str <= '9')
	{
		if (int_overflow(num * sign, **str - '0'))
			return (errno = ERANGE, -1);
		num = (num * 10) + (**str - '0');
		(*str)++;
	}
	if ((argc > 2 && **str) || (argc == 2 && **str && **str != ' '))
		return (errno = EINVAL, -1);
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

/*
DESCRIPTION
	Returns 1 in case of overflow or underflow else 0.
*/

static int	int_overflow(int num, int digit)
{
	if (num > 0)
		return (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7));
	return (num < INT_MIN / 10 || (num == INT_MIN / 10 && digit > 8));
}

/*
DESCRIPTION
	It checks if a value is repeated in the stack.
*/

static bool	int_repeated(int num, t_node *a)
{
	while (a)
	{
		if (a->value == num)
			return (true);
		a = a->next;
	}
	return (false);
}
