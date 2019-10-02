/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checker.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:41:38 by lhageman       #+#    #+#                */
/*   Updated: 2019/10/02 17:49:50 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKER_H
# define FT_CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct		s_arrlist
{
	int *arr_a;
	int *arr_b;
}					t_arrlist;


int					ft_valid_input(char *str);
int					ft_check_input(char **argv);
int					ft_store_input(char **argv);
void				ft_print_int_array(int *array, int len);
void				ft_print_two_int_array(int *array1, int *array2, int len);
void				ft_set_int_array_list(t_arrlist *list, int len);
int					ft_read_input();

#endif
