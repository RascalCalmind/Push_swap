/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_stack.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/06 15:31:10 by lhageman       #+#    #+#                */
/*   Updated: 2019/10/07 15:24:13 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ft_check_stack(t_arrlist *list)
{
	int i;

	i = 0;
	if (list->len_b > 0)
	{
		ft_printf("KO\n");
		return ;
	}
	while (i < list->len_a - 1)
	{
		if (list->arr_a[i] > list->arr_a[i + 1])
		{
			ft_printf("KO\n");
			return ;
		}
		i++;
	}
	ft_printf("OK\n");
}
