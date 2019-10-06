/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_set_array.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 17:44:42 by lhageman       #+#    #+#                */
/*   Updated: 2019/10/06 14:58:14 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ft_set_int_array_list(t_arrlist *list, int len)
{
	int i;

	i = 0;
	ft_printf("this is len: %i\n", len);
	while (i < len)
	{
		list->arr_a[i] = 0;
		list->arr_b[i] = 0;
		i++;
	}
	ft_print_two_int_array(list->arr_a, list->arr_b, len);
	list->len_a = len;
	list->len_b = 0;
}