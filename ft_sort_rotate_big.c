/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_rotate_big.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/29 17:08:45 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/29 17:15:59 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"

int		ft_a_sorted(t_arrlist *list)
{
	int i;

	i = 0;
	while (i < list->len_a - 1)
	{
		if (list->arr_a[i] > list->arr_a[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

int		ft_middles(t_arrlist *list, int middle)
{
	int i;

	i = 0;
	while (i < list->len_a)
	{
		if (list->arr_a[i] < middle)
			return (-1);
		i += 1;
	}
	return (0);
}

int		ft_which_way(t_arrlist *list, int middle, int max)
{
	int min;
	int num;

	min = 0;
	num = 0;
	while (min != max && min <= max)
	{
		if (list->arr_a[min] < middle)
		{
			if (list->arr_a[max] < list->arr_a[min])
				return ((list->len_a - max) * -1);
			return (min);
		}
		else if (list->arr_a[max] < middle)
			return ((list->len_a - max) * -1);
		else
		{
			min++;
			max--;
		}
	}
	if (min == max)
		return (min);
	return (0);
}

int		ft_which_rotate(t_arrlist *list, int turn)
{
	if (turn > 0)
	{
		if (list->len_b >= 2 && list->arr_b[0] < list->arr_b[list->len_b - 1])
			ft_rr(list);
		else
			ft_ra(list);
		return (turn - 1);
	}
	if (turn < 0)
	{
		if (list->len_b >= 2 && list->arr_b[list->len_b - 1] > list->arr_b[0])
			ft_rrr(list);
		else
			ft_rra(list);
		return (turn + 1);
	}
	return (0);
}
