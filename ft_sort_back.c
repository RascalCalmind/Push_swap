/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_back.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/10 21:39:17 by lhageman       #+#    #+#                */
/*   Updated: 2019/11/10 22:03:11 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"

int	ft_sort_back(t_arrlist *list)
{
	int ret;

	ret = ft_sorted(list);
	while (ret != 0)
	{
		ft_pa(list);
		if (list->arr_a[1] < list->arr_a[0])
			ft_sa(list);
		ret = ft_sorted(list);
	}
	return (0);
}
