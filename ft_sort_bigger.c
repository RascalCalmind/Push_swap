/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sort_bigger.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/10 17:43:47 by lhageman       #+#    #+#                */
/*   Updated: 2019/11/10 19:01:05 by lhageman      ########   odam.nl         */
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
	while (i < list->len_a - 1)
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
	// int ret;

	min = 0;
	max = list->len_a - 1;
	while (min != max && min <= max)
	{
		if (list->arr_a[min] <= middle)
			return (min);
		else if (list->arr_a[max] <= middle)
			return ((list->len_a - max) * -1);
		else
		{
			min++;
			max--;
		}
	}
	// ret = ft_nonumber(list, middle);
	if (min == max)
		return (min);
	return (0);	
}

int		ft_rot_find(t_arrlist *list, int middle)
{
	int turn;

	turn = ft_which_way(list, middle);
	while (turn != 0)
	{
		if (turn > 0)
		{
			ft_ra(list);
			turn -= 1;
		}
		if (turn < 0)
		{
			ft_rra(list);
			turn += 1;
		}
	}
	return (0);
}

int		ft_bubble_to_b(t_arrlist *list, int middle)
{
	int check;
	int sort_a;
	int i;

	ft_printf("we go into bubble to b\nThis is middle: %i\n", middle);
	i = 0;
	check = ft_middles(list, middle);
	while (check != 0 && sort_a != 0)
	{
		if (list->arr_a[i] < middle)
			ft_pb(list);
		if (list->arr_a[i] > middle)
			ft_rot_find(list, middle);
		if (list->len_a == 3)
			ft_sort_three(list);
		ft_printf("check: %i\n", check);
		check = ft_middles(list, middle);
		sort_a = ft_a_sorted(list);
	}
	ft_print_stacks(list);
	ft_printf("we go out bubble to b\n");
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
		ft_printf("sort bigger, middle:%i\n", middle);
		ft_bubble_to_b(list, middle);
		middle = ft_bubblesort(list);
		ft_printf("this is the new middle after bubblesort: %i\n", middle);
		ret = ft_sorted(list);
		sort_a = ft_a_sorted(list);
	}
	// if (ret != 0)
	// 	ft_sort_back(list);
	ret = ft_sorted(list);
	if (ret != 0)
		ft_printf("I Seem to have a lot of trouble sorting this shitty list you gave me\n");
	return (0);
}
