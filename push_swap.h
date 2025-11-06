#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>      // printf (to remove)

# include <errno.h>     // error
# include <limits.h>    // INT_MAX
# include <stdbool.h>   // boolean
// # include <stdint.h>    // SIZE_MAX
# include <stdlib.h>    // malloc, free
# include <unistd.h>    // read, write, ssize_t

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

// stack_init
int     init_stack_a(int argc, char **argv, t_stack *a);
int     parse_int(char **str);
t_node	*new_node(int num);

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
void    swap_both(t_stack *a, t_stack *b);
void    rotate_both(t_stack *a, t_stack *b, char direction);

// sort
void    sort_3(t_stack *a);
void    sort_stack(t_stack *a, t_stack *b);
void    set_target(t_stack *src, t_stack *dst, char s);
int     is_better_target(t_node *src, t_node *dst, char s);

// sort_execute
void    push_node_to_target(t_stack *src, t_stack *dst, char src_name, char dst_name);
t_node  *find_cheapest_node(t_stack *src, t_stack *dst);
void    calculate_cost_to_top(t_stack *stack);
void    bring_node_to_top(t_node *node, int node_cost, t_stack *stack, char stack_name);

// sort_utils
int     value_repeated(int num, t_node *a);
int     stack_sorted(t_node *a);
t_node  *find_extreme_node(t_node *stack, char ext);
int     is_more_extreme(t_node *extreme, t_node *stack, char ext);

// get_next_line
char	*get_next_line(int fd);
ssize_t	read_buffer(int fd, char *buf);
char	*grow_line(char *line, size_t line_len, size_t append_len,
			size_t *capacity);
char	*append_line(char *line, size_t *line_len, char *buf,
			size_t append_len);

// utils
// push_swap: isdigit, memset; gnl: strlen, memcpy, memchr
int	    ft_isdigit(int c);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

// void    print_stack(t_node *a);

#endif