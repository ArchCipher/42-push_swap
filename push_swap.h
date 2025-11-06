#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>      // printf (to remove)

# include <errno.h>     // error
# include <limits.h>    // INT_MAX
# include <stdbool.h>   // boolean
// # include <stdint.h>    // SIZE_MAX
# include <stdlib.h>    // malloc, free
# include <unistd.h>    // read, write, ssize_t

# define ERROR "Error\n"

# define STACK_A 'A'
# define STACK_B 'B'

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

# define BIG 'b'
# define SMALL 's'

# define BUFFER_SIZE 256

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

// PUSH_SWAP
// sort
void    sort_3(t_stack *a);
void    sort_stack(t_stack *a, t_stack *b);

// sort_execute
void    push_cheapest_node(t_stack *src, t_stack *dst, char src_name, char dst_name);
void    bring_node_to_top(t_node *node, int node_cost, t_stack *stack, char stack_name);

// CHECKER (BONUS)
// get_next_line
char	*get_next_line(int fd);

// checker_utils
int		parse_operation(char *line, t_stack *a, t_stack *b);
void	print_output(t_stack *a, t_stack *b);
int     error_handler(char *line, t_stack *a, t_stack *b);


// SHARED BY BOTH PUSH_SWAP AND CHECKER
// stack_init
int     init_stack_a(int argc, char **argv, t_stack *a);

// stack_utils
void    add_front(t_stack *a, t_node *new);
void    add_last(t_stack *a, t_node *new);
void    free_stack(t_stack *a);

// stack_ops1
void    swap(t_stack *stack, char *str);
void    push(t_stack *src, t_stack *dst, char *str);
void    rotate(t_stack *stack, char *str);
void    rev_rotate(t_stack *stack, char *str);

// stack_ops2
void    swap_both(t_stack *a, t_stack *b, bool print);
void    rotate_both(t_stack *a, t_stack *b, char direction, bool print);

// sort_utils
bool    value_repeated(int num, t_node *a);
bool    stack_sorted(t_node *a);
t_node  *find_extreme_node(t_node *stack, char mode);

// utils
void	*ft_memset(void *b, int c, size_t len);
int     ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

#endif