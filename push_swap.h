#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>    // write
# include <errno.h>     // error
# include "../libft/libft.h"
#include <stdio.h>      // printf (to remove)

typedef struct  s_stack
{
    int             value;
    int             index;
    struct s_stack  *prev;
    struct s_stack  *next;
}               t_stack;

typedef struct  s_stacks
{
    t_stack     *a;
    t_stack     *a_last;
    int         a_len;
    t_stack     *b;
    t_stack     *b_last;
    int         b_len;
}               t_stacks;

// init_stack
int     init_stack_a(int argc, char **argv, t_stack **a, int *a_len);
int     ft_atoi_mod(char **str);
t_stack	*new_stack(int num, int len);
t_stack *append_stack(t_stack **head, t_stack *last, t_stack *new);
void    free_stack(t_stack **a);

// operations
void    swap(t_stack **stack, char *str);
void    push(t_stack **from, t_stack **to, char *str);
void    rotate(t_stack **stack, char *str);
void    rev_rotate(t_stack **stack, char *str);

// op_utils
void    ss(t_stack **a, t_stack **b);
void    rotate_both(t_stack **a, t_stack **b, char direction);
t_stack *find_last(t_stack *stack);

// sort
void    sort_3(t_stack **a);
void    sort_stack(t_stack **a, t_stack **b, int a_len);

// sort_utils
int     value_repeated(int num, t_stack *a);
int     stack_sorted(t_stack *a);
t_stack *find_biggest(t_stack *a, int count);

#endif