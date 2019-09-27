# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lhageman <lhageman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/09/26 17:41:45 by lhageman       #+#    #+#                 #
#    Updated: 2019/09/27 14:08:18 by lhageman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAMEC	= checker.a
NAMEPS	= push_swap.a
NAMES = $(NAMEC) $(NAMEPS)

CC 		= gcc -Wall -Werror -Wextra -o

SRCC	=	ft_checker.c ft_valid_input.c	
SRCPS	=	ft_push_swap.c

OBJC	= $(SRCC:%.c=%.o)
OBJPS	= $(SRCPS:%.c=%.o)
TRASH	= $(SRCC:%.c=%.c~) $(SRCPS:.c=.c~)

all:	$(NAMES)

$(NAMEC): $(SRCC)
	@echo "\033[0;34mmaking checker.a\033[0m"
	@$(CC) $(NAMEC) $(SRCC)
	
$(NAMEPS): $(SRCPS)
	@echo "\033[0;35mmaking push_swap.a\033[0m"
	@$(CC) $(NAMEPS) $(SRCPS)

clean:
	@rm -f $(OBJC) $(OBJPS)
	@echo "\033[0;31mCleaning object files \033[0m"
	@rm -f $(TRASH)
	@echo "\033[1;33mCleaning the trash\033[0m"

fclean: clean
	@rm -f $(NAMES)
	@echo "\033[0;32mClearing executables\033[0m"

re: fclean all
