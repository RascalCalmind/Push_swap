/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sorting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/10 13:45:02 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/29 17:36:27 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"

void		ft_arrange_three(t_arrlist *list, int small, int big)
{
	if (small == 0)
	{
		ft_rra(list);
		ft_sa(list);
	}
	else if (big == 0)
	{
		if (small == 1)
		{
			ft_rra(list);
			ft_rra(list);
		}
		else
		{
			ft_sa(list);
			ft_rra(list);
		}
	}
	else if (small == 1)
		ft_sa(list);
	else if (small == 2)
		ft_rra(list);
}

void		ft_sort_three(t_arrlist *list)
{
	int big;
	int small;
	int i;

	big = 0;
	small = 0;
	i = 0;
	while (i < list->len_a - 1)
	{
		if (list->arr_a[i] < list->arr_a[i + 1] && list->arr_a[i]
			< list->arr_a[small])
			small = i;
		if (list->arr_a[i + 1] > list->arr_a[i] && list->arr_a[i + 1]
			> list->arr_a[big])
			big = i + 1;
		if (list->arr_a[i + 1] < list->arr_a[i] && list->arr_a[i + 1]
			< list->arr_a[small])
			small = i + 1;
		i += 1;
	}
	ft_arrange_three(list, small, big);
}

int			ft_sorted(t_arrlist *list)
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

void		ft_sorter(t_arrlist *list, int middle)
{
	int i;
	int ret;

	i = 0;
	ret = ft_sorted(list);
	while (ret != 0)
	{
		if (list->len_a == 2 && list->len_b == 0)
		{
			ft_sa(list);
			ret = ft_sorted(list);
		}
		else if (list->len_a == 3 && list->len_b == 0)
		{
			ft_sort_three(list);
			ret = ft_sorted(list);
		}
		else
			ft_sort_bigger(list, middle);
		ret = ft_sorted(list);
		if (ret != 0)
			return ;
		middle = 0;
	}
}
