# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lhageman <lhageman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/26 17:41:45 by lhageman       #+#    #+#                 #
#    Updated: 2019/12/01 15:47:14 by lhageman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAMEC	= checker.a
NAMEPS	= push_swap.a
LIBFT	= libft/libft.a
NAMES = $(NAMEC) $(NAMEPS)

CCC		= gcc -gc -Wall -Werror -Wextra
CCO		= gcc -g -Wall -Werror -Wextra -o

SRCC	=	ft_checker.c \
			ft_valid_input.c \
			ft_store_input.c \
			ft_print_int_array.c \
			ft_read_input.c \
			ft_set_array.c \
			ft_swap.c \
			ft_push.c \
			ft_rotate.c \
			ft_reverse_rotate.c \
			ft_check_stack.c \
			ft_check_file.c

SRCPS	=	ft_push_swap.c \
			ft_valid_input.c \
			ft_set_array.c \
			ft_store_input.c \
			ft_sort.c \
			ft_push.c \
			ft_swap.c \
			ft_rotate.c \
			ft_reverse_rotate.c \
			ft_print_int_array.c \
			ft_bubblesort.c \
			ft_sorting.c \
			ft_sort_bigger.c \
			ft_sort_back.c \
			ft_check_file.c \
			ft_find_bignum.c

OBJC	= $(SRCC:%.c=%.o)
OBJPS	= $(SRCPS:%.c=%.o)
TRASH	= $(SRCC:%.c=%.c~) $(SRCPS:.c=.c~)

all:	$(NAMES)

$(LIBFT):
	@$(MAKE) -C libft

%.o: %.c
	@$(CCO) $@ $<  -I./libft -c

$(NAMEC): $(OBJC) $(LIBFT)
	@echo "\033[0;34mmaking checker.a\033[0m"
	@$(CCO) $(NAMEC) $(OBJC) -L ./libft -lft


$(NAMEPS): $(OBJPS) $(LIBFT)
	@echo "\033[0;35mmaking push_swap.a\033[0m"
	@$(CCO) $(NAMEPS) $(OBJPS) -L ./libft -lft

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJC) $(OBJPS)
	@echo "\033[0;31mCleaning object files \033[0m"
	@rm -f $(TRASH)
	@echo "\033[1;33mCleaning the trash\033[0m"

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAMES)
	@echo "\033[0;32mClearing executables\033[0m"

re: fclean all
