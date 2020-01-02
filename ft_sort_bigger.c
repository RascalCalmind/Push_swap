/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_bigger.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/10 17:43:47 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/02 20:20:45 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"

int			ft_rot_find(t_arrlist *list, int middle)
{
	int turn;
	int check;

	check = ft_middles(list, middle);
	if (check == 0)
		middle = ft_bubblesort(list);
	turn = ft_which_way(list, middle, list->len_a - 1);
	while (turn != 0)
	{
		turn = ft_which_rotate(list, turn);
	}
	return (0);
}

static void	ft_which_s(t_arrlist *list)
{
	if (list->arr_a[0] < list->arr_a[1] && list->arr_b[0] < list->arr_b[1])
		ft_ss(list);
	if (list->arr_b[0] < list->arr_b[1])
		ft_sb(list);
}

int			check_three_sorted(t_arrlist *list)
{
	int ret;

	ret = 0;
	if (list->len_a == 3)
		ft_sort_three(list);
	ret = ft_a_sorted(list);
	if (ret == 0)
		return (0);
	return (-1);
}

int			ft_bubble_to_b(t_arrlist *list, int middle)
{
	int check;
	int sort_a;

	check = ft_middles(list, middle);
	sort_a = ft_a_sorted(list);
	while (check != 0 && sort_a != 0)
	{
		sort_a = check_three_sorted(list);
		if (sort_a == 0)
			break ;
		if (list->arr_a[0] < middle)
			ft_pb(list);
		ft_which_s(list);
		sort_a = check_three_sorted(list);
		if (sort_a == 0)
			break ;
		if (list->arr_a[0] >= middle)
			ft_rot_find(list, middle);
		check = ft_middles(list, middle);
		sort_a = ft_a_sorted(list);
	}
	return (0);
}

int			ft_sort_bigger(t_arrlist *list, int middle)
{
	int ret;
	int sort_a;

	ft_print_stacks(list);
	ret = ft_sorted(list);
	sort_a = ft_a_sorted(list);
	while (ret != 0 && sort_a != 0)
	{
		if (list->len_a == 2 && list->arr_a[0] > list->arr_a[1])
			ft_sa(list);
		if (ft_a_sorted(list) == 0)
			break ;
		ft_bubble_to_b(list, middle);
		middle = ft_bubblesort(list);
		ret = ft_sorted(list);
		sort_a = ft_a_sorted(list);
	}
	if (ret != 0)
		ft_sort_back(list);
	ret = ft_sorted(list);
	if (ret != 0)
		return (ft_quick_error_return());
	return (0);
}
