/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bubblesort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/23 16:12:32 by lhageman       #+#    #+#                */
/*   Updated: 2019/10/23 19:15:00 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"

static int	ft_swap_two(t_arrlist *list, int i, int j)
{
	int temp;

	temp = list->arr_a[i];
	list->arr_a[i] = list->arr_a[j];
	list->arr_a[j] = temp;
	return (0);
}

static int	ft_sorted(t_arrlist *list)
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

int		ft_middle(t_arrlist *list)
{
	int middle;
	int number;

	middle = list->len_a / 2;
	number = list->arr_a[middle];
	return (number);
}

int		ft_whichway(t_arrlist *list, int middle)
{
	int min;
	int max;

	min = 0;
	max = list->len_a - 1;
	ft_printf("these are min %i and max %i\n", min, max);
	while (min != max && min <= max)
	{
		ft_printf("these are min %i, %i and max %i, %i\n", min, list->arr_a[min], max, list->arr_a[max]);
		ft_print_stacks(list);
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
	return (0);
}

int		ft_done(t_arrlist *list, int middle)
{
	int min;
	int max;

	min = 0;
	max = list->len_a - 1;
	while (min != max && min < max)
	{
		if (list->arr_a[min] <= middle)
			return (0);
		else if (list->arr_a[max] <= middle)
			return (0);
		else
		{
			min++;
			max++;
		}
	}
	if (min == max || min > max)
		return (1);
	return (0);
}

int		ft_tob_and_rotate(t_arrlist *list, int middle, int push)
{
	int ret;

	ret = 1;
	if (push == 1)
	{
		ft_printf("pb\n");
		ft_pb(list);
	}
	ret = ft_whichway(list, middle);
	ft_printf("this is ret in tobandrotate: %i\n", ret);
	if (ret == 0)
		ret = ft_done(list, middle);
	ft_printf("this is ret in tobandrotate: %i\n", ret);
	if (ret == 1)
		return (-1);
	if (ret != 0)
	{
		while (ret >= 0)
		{
			ft_printf("ra\n");
			ft_ra(list);
			ret--;
		}
		while (ret <= 0)
		{
			ft_printf("rra\n");
			ft_rra(list);
			ret++;
		}
	}
	return (0);
}

void	ft_sorter(t_arrlist *list, int middle)
{
	int i;
	int ret;

	i = 0;
	ft_printf("sorter\n");
	ret = ft_sorted(list);
	while (ret != 0)
	{
		ft_printf("This is middle:%i && this is list->arr_a[0]: %i\n", middle,  list->arr_a[0]);
		if (list->len_a == 2)
		{
			if (list->arr_a[0] > list->arr_a[1])
				ft_sa(list);
			ft_pa(list);
			ft_pa(list);
			if (list->arr_a[0] > list->arr_a[1] && list->arr_b[1] > list->arr_b[0])
				ft_ss(list);
			if (list->arr_a[0] > list->arr_a[1])
				ft_sa(list);
			if (list->arr_b[1] > list->arr_b[0])
				ft_sb(list);
		}
		else if (list->arr_a[0] <= middle)
			ft_tob_and_rotate(list, middle, 1);
		else if (list->arr_a[0] > middle)
		{
			ret = ft_tob_and_rotate(list, middle, 0);
			if (ret == -1)
				middle = ft_bubblesort(list);
		}
		ret = ft_sorted(list);
		ft_printf("this is ret: %i\n", ret);
	}
}

void	ft_list_copy(t_arrlist *list, t_arrlist *copy)
{
	int i;

	i = 0;
	copy->len_a = list->len_a;
	copy->len_b = list->len_b;
	copy->arr_a = malloc(sizeof(int) * list->len_a);
	copy->arr_b = malloc(sizeof(int) * list->len_a);
	while (i < list->len_a && list->arr_a[i])
	{
		copy->arr_a[i] = list->arr_a[i];
		i++;
	}
	i = 0;
	while (i < list->len_b && list->arr_b[i])
	{
		copy->arr_b[i] = list->arr_b[i];
		i++;
	}
	ft_printf("The COPY STACK in list copy:\n");
	ft_print_stacks(copy);
}

int		ft_bubblesort(t_arrlist *list_og)
{
	t_arrlist	*list;
	int			i;
	int			middle;

	list = malloc(sizeof(t_arrlist));
	// list = list_og;
	ft_list_copy(list_og, list);
	i = 0;
	while (ft_sorted(list) != 0)
	{
		if (i == list->len_a - 1)
			i = 0;
		if (list->arr_a[i] > list->arr_a[i + 1])
			ft_swap_two(list, i, i + 1);
		if (i > 0 && list->arr_a[i - 1] > list->arr_a[i])
			i--;
		else
			i++;
	}
	ft_printf("The OG STACK:\n");
	ft_print_stacks(list_og);
	ft_printf("The COPY STACK:\n");
	ft_print_stacks(list);
	middle = ft_middle(list);
	return (middle);
}
