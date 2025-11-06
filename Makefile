#			Library and Project names
NAME		= push_swap
BONUS		= checker

#			Compiler and Flags
CC			= cc
FLAGS		= -Wall -Werror -Wextra
SFLAGS		= -fsanitize=address

#			Header
HEADER		= -I.

#			Sources & Objects
MSRCS		= push_swap \
			sort sort_execute \
			stack_ops1 stack_ops2 \
			stack_init stack_utils \
			sort_utils utils
BSRCS		= checker \
			get_next_line \
			stack_ops1 stack_ops2 \
			stack_init stack_utils \
			sort_utils utils

SRCS		= $(addsuffix .c, $(MSRCS))
BONUS_SRCS	= $(addsuffix .c, $(BSRCS))
OBJS	= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -g -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(SFLAGS) -g $(HEADER) $^ -o $@

bonus: $(BONUS_OBJS)
	$(CC) $(FLAGS) $(SFLAGS) -g $(HEADER) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean test