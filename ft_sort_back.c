/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_back.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/10 21:39:17 by lhageman       #+#    #+#                */
/*   Updated: 2019/11/11 15:22:10 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"

void ft_resort(t_arrlist *list)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (list->arr_a[i + 1] < list->arr_a[i])
	{
		if (i < 1)
			ft_sa(list);
		if (i >= 1)
		{
			j = i;
			k = i;
			ft_sa(list);
			while (j > 0)
			{
				ft_ra(list);
				ft_sa(list);
				j -= 1;
			}
			while (k > 0)
			{
				ft_rra(list);
				k -= 1;
			}
		}
		i += 1;
	}
}

int	ft_sort_back(t_arrlist *list)
{
	int ret;

	ret = ft_sorted(list);
	while (ret != 0)
	{
		if (list->arr_a[0] < list->arr_a[1])
			ft_pa(list);
		ft_resort(list);
		// if (list->arr_a[1] < list->arr_a[0])
		// 	ft_sa(list);
		// if (list->arr_a[2] < list->arr_a[1])
		// {
		// 	ft_ra(list);
		// 	ft_sa(list);
		// 	ft_rra(list);
		// }
		ret = ft_sorted(list);
	}
	return (0);
}