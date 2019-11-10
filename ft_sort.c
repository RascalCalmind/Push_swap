/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 18:23:18 by lhageman       #+#    #+#                */
/*   Updated: 2019/11/10 15:41:08 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "ft_checker.h"

static int	ft_checker_sorted(t_arrlist *list)
{
	int i;

	i = 0;
	if (list->len_b > 0)
		return (-1);
	while (i < list->len_a - 1)
	{
		if (list->arr_a[i] > list->arr_a[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

int			ft_sort(t_arrlist *list)
{
	int ret;

	ret = ft_checker_sorted(list);
	if (ret == 0)
		return (0);
	else
	{
		ret = ft_bubblesort(list);
		ft_sorter(list, ret);
	}
	return (0);
}
