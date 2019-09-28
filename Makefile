# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lhageman <lhageman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/26 17:41:45 by lhageman       #+#    #+#                 #
#    Updated: 2019/09/28 20:57:03 by lhageman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAMEC	= checker.a
NAMEPS	= push_swap.a
LIBFT	= libft/libft.a
NAMES = $(NAMEC) $(NAMEPS)

CC 		= clang -o -Wall -Werror -Wextra

SRCC	=	ft_checker.c \
			ft_valid_input.c \
			ft_store_input.c \
			ft_print_int_array.c \
			ft_read_input.c

SRCPS	=	ft_push_swap.c

OBJC	= $(SRCC:%.c=%.o)
OBJPS	= $(SRCPS:%.c=%.o)
TRASH	= $(SRCC:%.c=%.c~) $(SRCPS:.c=.c~)

all:	$(NAMES)

$(LIBFT):
	@$(MAKE) -C libft

# $(NAMEC): $(OBJC) $(LIBFT)
# 	@echo "\033[0;34mmaking checker.a\033[0m"
# 	@cp libft/libft.a $(NAMEC)
# 	@ar crs $(NAMEC) $(OBJC)

# $(NAMEPS): $(OBJPS) $(LIBFT)
# 	@echo "\033[0;35mmaking push_swap.a\033[0m"
# 	@cp libft/libft.a $(NAMEPS)
# 	@ar crs $(NAMEPS) $(OBJPS)

$(NAMEC): $(SRCC) $(LIBFT)
	@echo "\033[0;34mmaking checker.a\033[0m"
# @$(CC) $(NAMEC) $(SRCC) -L./libft -lft
	@clang -o $(NAMEC) $(SRCC) -Wall -Werror -Wextra -I./libft -L./libft libft

# @$(CC) -o $(NAME) $(SRCS) $(CFLAGS)  -I./get_next_line -L./libft -I./libft/includes -lft

$(NAMEPS): $(SRCPS) $(LIBFT)
	@echo "\033[0;35mmaking push_swap.a\033[0m"
	@$(CC) $(NAMEPS) $(SRCPS)

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
