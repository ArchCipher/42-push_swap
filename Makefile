#add header for all files

#			Library and Project names
NAME		= push_swap
# BONUS		= checker
LIB_DIR		= ../libft
LIB			= libft.a

#			Compiler and Flags
CC			= cc
FLAGS		= -Wall -Werror -Wextra
SFLAGS		= -fsanitize=address

#			Header
HEADER		= -I.

#			Sources & Objects
MSRCS		= \
	   		main stack_ops1 stack_ops2 stack_init stack_utils sort sort_execute sort_utils
# BSRCS		= \
# 			checker
SRCS		= $(addsuffix .c, $(MSRCS))
# BONUS_SRCS	= $(addsuffix .c, $(BSRCS))
OBJS	= $(SRCS:.c=.o)
# BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -g -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_DIR) && make -C $(LIB_DIR) clean
	$(CC) $(FLAGS) $(SFLAGS) -g $(HEADER) $(LIB_DIR)/$(LIB) $^ -o $@

# bonus: $(BONUS_OBJS)
# 	$(CC) $(FLAGS) -g $(HEADER) $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean test