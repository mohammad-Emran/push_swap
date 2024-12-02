NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra 
SRCS = check_errors.c create_a_new_list.c operations.c \
       push_swap.c radix.c sort_small.c sort_the_new_list.c \
       main.c check_error2.c

OBJDIR = obj
SRCDIR = src
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
LIBFT = ./libft
PRINTF = ./ft_printf
INCLUDE = -I./includes/

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)/libft.a $(PRINTF)/libftprintf.a
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -L$(PRINTF) -lftprintf -o $(NAME)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

$(PRINTF)/libftprintf.a:
	@make -C $(PRINTF)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	@make clean -C $(LIBFT)
	@make clean -C $(PRINTF)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@make fclean -C $(PRINTF)

re: fclean all

.PHONY: all clean fclean re
