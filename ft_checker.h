/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checker.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:41:38 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/28 22:51:46 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

int		ft_valid_input(char *str);
int		ft_check_input(char **argv);
int		*ft_store_input(char **argv);
void	ft_print_int_array(int *array, int len);
int		ft_read_input();

#endif
