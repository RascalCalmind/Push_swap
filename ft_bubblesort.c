/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bubblesort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/23 16:12:32 by lhageman       #+#    #+#                */
/*   Updated: 2019/11/10 22:32:27 by lhageman      ########   odam.nl         */
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

// static int	ft_sorted(t_arrlist *list)
// {
// 	int i;

// 	i = 0;
// 	if (list->len_b > 0)
// 		return (-1);
// 	while (i < list->len_a - 1)
// 	{
// 		if (list->arr_a[i] > list->arr_a[i + 1])
// 			return (-1);
// 		i++;
// 	}
// 	return (0);
// }

// static void ft_find_smallest(t_arrlist *list)
// {
// 	int i;
// 	int j;

// 	ft_printf("find smallest!\n");
// 	i = 0;
// 	j = 1;
// 	while (j < list->len_a - 1)
// 	{
// 		if (list->arr_a[i] > list->arr_a[j])
// 			i = j;
// 		j++;
// 	}
// 	if (i == 1)
// 		ft_rra(list);
// 	if (i == 2)
// 		ft_ra(list);
// 	// if (list->arr_a[1] > list->arr_a[2])
// 	// {
// 	// 	ft_ra(list);
// 	// 	ft_sa(list);
// 	// 	ft_rra(list);
// 	// }
// 	ft_pb(list);
// }

static int	ft_bubble_sorted_a(t_arrlist *list)
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

int		ft_middle(t_arrlist *list)
{
	int middle;
	int number;

	middle = list->len_a / 2;
	if (list->len_a % 2 == 0)
		middle -= 1;
	number = list->arr_a[middle];
	return (number);
}

// int ft_nonumber(t_arrlist *list, int middle)
// {
// 	int i;

// 	i = 0;
// 	while (i < list->len_a - 1)
// 	{
// 		if (list->arr_a[i] < middle)
// 			return (i);
// 		i++;
// 	}
// 	return (0);
// }

// int		ft_whichway(t_arrlist *list, int middle)
// {
// 	int min;
// 	int max;
// 	int ret;

// 	min = 0;
// 	max = list->len_a - 1;
// 	while (min != max && min <= max)
// 	{
// 		if (list->arr_a[min] <= middle)
// 			return (min);
// 		else if (list->arr_a[max] <= middle)
// 			return ((list->len_a - max) * -1);
// 		else
// 		{
// 			min++;
// 			max--;
// 		}
// 	}
// 	ret = ft_nonumber(list, middle);
// 	if (min == max)
// 		return (ret);
// 	return (0);
// }

// int		ft_done(t_arrlist *list, int middle)
// {
// 	int min;
// 	int max;

// 	min = 0;
// 	max = list->len_a - 1;
// 	while (min != max && min < max)
// 	{
// 		if (list->arr_a[min] <= middle)
// 			return (0);
// 		else if (list->arr_a[max] <= middle)
// 			return (0);
// 		else
// 		{
// 			min++;
// 			max++;
// 		}
// 	}
// 	if (min == max || min > max)
// 		return (1);
// 	return (0);
// }

// int		ft_tob_and_rotate(t_arrlist *list, int middle, int push)
// {
// 	int ret;

// 	ret = 1;
// 	if (list->len_a == 3)
// 	{
// 		ft_find_smallest(list);
// 		return (0);
// 	}
// 	if (list->len_a < 3)
// 		return (0);
// 	if (push == 1)
// 		ft_pb(list);
// 	ret = ft_whichway(list, middle);
// 	if (ret == 0)
// 	{
// 		ret = ft_done(list, middle);
// 		if (ret == 1)
// 			return (-1);
// 	}
// 	if (ret != 0)
// 	{
// 		while (ret > 0)
// 		{
// 			ft_ra(list);
// 			ret--;
// 		}
// 		while (ret < 0)
// 		{
// 			ft_rra(list);
// 			ret++;
// 		}
// 	}
// 	return (0);
// }

// static void		ft_ss(t_arrlist *list)
// {
// 	ft_sa(list);
// 	ft_sb(list);
// }

// int ft_get_a_sorted(t_arrlist *list)
// {
// 	if (list->arr_a[0] > list->arr_a[1])
// 		ft_sa(list);
// 	ft_pa(list);
// 	while (ft_sorted(list) != 0)
// 	{
// 		if (list->arr_a[0] > list->arr_a[1] && list->arr_b[1] > list->arr_b[0])
// 			ft_ss(list);
// 		if (list->arr_a[0] > list->arr_a[1])
// 			ft_sa(list);
// 		if (list->arr_b[1] > list->arr_b[0])
// 			ft_sb(list);
// 		if (list->arr_a[0] < list->arr_b[0] && list->len_b > 1)
// 		{
// 			ft_printf("we go in pa ra pb rra\n");
// 			ft_pa(list);
// 			ft_rra(list);
// 			ft_pb(list);
// 			ft_ra(list);
// 			if (list->arr_a[0] > list->arr_a[1] && list->arr_b[1] > list->arr_b[0])
// 				ft_ss(list);
// 			if (list->arr_a[0] > list->arr_a[1])
// 				ft_sa(list);
// 			if (list->arr_b[1] > list->arr_b[0])
// 				ft_sb(list);
// 		}
// 		if (list->arr_a[1] < list->arr_b[0])
// 		{
// 			ft_ra(list);
// 			ft_pb(list);
// 			ft_rra(list);
// 		}
// 		if (list->arr_a[0] > list->arr_b[0])
// 		{
// 			ft_pa(list);
// 			ft_pa(list);
// 		}
// 		if (list->len_b == 1 && list->arr_b[0] > list->arr_a[0])
// 		{
// 			ft_pa(list);
// 			ft_sa(list);
// 		}
// 	}
// 	return (0);
// }

// int		ft_toa_and_rotate(t_arrlist *list, int middle)
// {
// 	if (list->arr_a[0] < middle && list->len_a > 2)
// 		ft_pb(list);
// 	if (list->arr_a[1] < middle && list->len_a > 2)
// 	{
// 		ft_ra(list);
// 		ft_pb(list);
// 	}
// 	ft_get_a_sorted(list);
// 	return (0);
// }

// void	ft_sorter(t_arrlist *list, int middle)
// {
// 	int i;
// 	int ret;

// 	i = 0;
// 	//ft_printf("sorter\n");
// 	ret = ft_sorted(list);
// 	while (ret != 0)
// 	{
// 		//ft_printf("This is middle:%i && this is list->arr_a[0]: %i\n", middle,  list->arr_a[0]);
// 		if (list->len_a == 2)
// 			break ;
// 		else if (list->arr_a[0] <= middle)
// 			ft_tob_and_rotate(list, middle, 1);
// 		else if (list->arr_a[0] > middle)
// 		{
// 			if (list->len_a == 3)
// 				ft_find_smallest(list);
// 			ret = ft_tob_and_rotate(list, middle, 0);
// 			if (ret == -1 || (ret == 0 && ft_nonumber(list, middle) == 0))
// 				middle = ft_bubblesort(list);
// 		}
// 		ret = ft_sorted(list);
// 	}
// 	ft_toa_and_rotate(list, middle);
// }

void	ft_list_copy(t_arrlist *list, t_arrlist *copy)
{
	int i;

	i = 0;
	copy->len_a = list->len_a;
	copy->len_b = list->len_b;
	copy->arr_a = malloc(sizeof(int) * list->len_a);
	copy->arr_b = malloc(sizeof(int) * list->len_a);
	while (i < list->len_a)
	{
		copy->arr_a[i] = list->arr_a[i];
		i++;
	}
	i = 0;
	while (i < list->len_b)
	{
		copy->arr_b[i] = list->arr_b[i];
		i++;
	}
}

int		ft_bubblesort(t_arrlist *list_og)
{
	t_arrlist	*list;
	int			i;
	int			middle;

	list = malloc(sizeof(t_arrlist));
	ft_list_copy(list_og, list);
	i = 0;
	while (ft_bubble_sorted_a(list) != 0)
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
	middle = ft_middle(list);
	free(list);
	return (middle);
}
