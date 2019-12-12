/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_bigger.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/10 17:43:47 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/12 16:26:12 by lhageman      ########   odam.nl         */
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

int		ft_which_way(t_arrlist *list, int middle)
{
	int min;
	int max;
	int num;

	min = 0;
	max = list->len_a - 1;
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

int		ft_rot_find(t_arrlist *list, int middle)
{
	int turn;
	int check;

	check = ft_middles(list, middle);
	if (check == 0)
		middle = ft_bubblesort(list);
	turn = ft_which_way(list, middle);
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

int		ft_bubble_to_b(t_arrlist *list, int middle)
{
	int check;
	int sort_a;

	check = ft_middles(list, middle);
	sort_a = ft_a_sorted(list);
	while (check != 0 && sort_a != 0)
	{
		if (list->len_a == 3)
			ft_sort_three(list);
		sort_a = ft_a_sorted(list);
		if (sort_a == 0)
			break ;
		if (list->arr_a[0] < middle)
			ft_pb(list);
		ft_which_s(list);
		if (list->len_a == 3)
			ft_sort_three(list);
		sort_a = ft_a_sorted(list);
		if (sort_a == 0)
			break ;
		if (list->arr_a[0] >= middle)
			ft_rot_find(list, middle);
		check = ft_middles(list, middle);
		sort_a = ft_a_sorted(list);
	}
	return (0);
}

int		ft_sort_bigger(t_arrlist *list, int middle)
{
	int ret;
	int sort_a;

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
		ft_printf("I Seem to have a lot of trouble sorting this shitty list you gave me\n");
	return (0);
}
