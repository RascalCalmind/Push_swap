/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_back.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/10 21:39:17 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/18 13:02:50 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"

void	ft_which_s(t_arrlist *list)
{
	if (list->arr_b[0] < list->arr_b[1] && list->arr_a[1] < list->arr_a[0])
		ft_ss(list);
	else if (list->arr_a[1] < list->arr_a[0])
		ft_sa(list);
	else if (list->arr_b[0] < list->arr_b[1])
		ft_sb(list);
}

int		ft_rot_and_swap(t_arrlist *list, int j)
{
	ft_ra(list);
	ft_which_s(list);
	return (j - 1);
}

int		ft_rrot_and_swap(t_arrlist *list, int k)
{
	ft_rra(list);
	return (k - 1);
}

void	ft_resort(t_arrlist *list)
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
			ft_which_s(list);
		if (i >= 1)
		{
			j = i;
			k = i;
			ft_which_s(list);
			while (j > 0)
				j = ft_rot_and_swap(list, j);
			while (k > 0)
				k = ft_rrot_and_swap(list, k);
		}
		i += 1;
	}
}

int		ft_sort_back(t_arrlist *list)
{
	int ret;
	int a_sort;

	a_sort = ft_a_sorted(list);
	ret = ft_sorted(list);
	while (ret != 0)
	{
		ft_which_s(list);
		ft_find_bignum(list);
		ft_resort(list);
		ret = ft_sorted(list);
	}
	return (0);
}
