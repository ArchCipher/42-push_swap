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
			sort \
			sort_execute

BSRCS		= checker_bonus \
			checker_utils_bonus \
			get_next_line_bonus

SSRCS		= stack_ops1 \
			stack_ops2 \
			stack_init \
			stack_utils \
			sort_utils \
			utils

MAN_SRCS	= $(addsuffix .c, $(MSRCS))
BONUS_SRCS	= $(addsuffix .c, $(BSRCS))
SHARED_SRCS = $(addsuffix .c, $(SSRCS))
SHARED_OBJS	= $(SHARED_SRCS:.c=.o)
MAN_OBJS	= $(MAN_SRCS:.c=.o) $(SHARED_OBJS)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o) $(SHARED_OBJS)

%.o: %.c
	$(CC) $(FLAGS) -g -c $< -o $@

all: $(NAME)

$(NAME): $(MAN_OBJS) 
	$(CC) $(FLAGS) $(SFLAGS) -g $(HEADER) $^ -o $@

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(FLAGS) $(SFLAGS) -g $(HEADER) $^ -o $@

clean:
	rm -f $(MAN_OBJS) $(BONUS_OBJS) $(SHARED_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all bonus

.PHONY: all clean fclean bonus