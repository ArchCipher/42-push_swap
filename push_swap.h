#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <errno.h>     // error
# include <unistd.h>    // write
# include "../libft/libft.h"
#include <stdio.h>      // printf (to remove)

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"
# define UP 'U'
# define DOWN 'D'
# define STACK_A 'A'
# define STACK_B 'B'
# define BIG 'b'
# define SMALL 's'

typedef struct  s_node
{
    int             value;
    struct s_node   *prev;
    struct s_node   *next;
    struct s_node   *target;
    int             cost;
    bool            rotate;
    int             rot_both_cost;
    long long       total_cost;
}                   t_node;

typedef struct  s_stack
{
    t_node     *first;
    t_node     *last;
    int         len;
}               t_stack;

// main

// stack_utils
int     init_stack_a(int argc, char **argv, t_stack *a);
int     ft_atoi_mod(char **str);
t_node	*new_node(int num);
void    append_front(t_stack *a, t_node *new);
void    append_stack(t_stack *a, t_node *new);
void    free_stack(t_stack *a);

// operations
void    swap(t_stack *stack, char *str);
void    push(t_stack *src, t_stack *dst, char *str);
void    rotate(t_stack *stack, char *str);
void    rev_rotate(t_stack *stack, char *str);

// op_utils
void    swap_both(t_stack *a, t_stack *b);
void    rotate_both(t_stack *a, t_stack *b, char direction);

// sort
void    sort_3(t_stack *a);
void    sort_stack(t_stack *a, t_stack *b);
void    set_target(t_stack *src, t_stack *dst, char s);
int     check_direction(t_node *src, t_node *dst, char s);
void    calculate_cost_to_top(t_stack *stack);
t_node  *find_cheapest_node(t_stack *src, t_stack *dst);
void    bring_node_to_top(t_node *node, int node_cost, t_stack *stack, char stack_name);
void    push_node_to_target(t_stack *src, t_stack *dst, char src_name, char dst_name);

// sort_utils
int     value_repeated(int num, t_node *a);
int     stack_sorted(t_node *a);
t_node  *find_extreme_node(t_node *stack, char ext);
int     compare_values(t_node *extreme, t_node *stack, char ext);

// void    print_stack(t_node *a);

#endif