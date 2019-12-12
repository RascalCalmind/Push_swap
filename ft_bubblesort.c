/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bubblesort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/23 16:12:32 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/12 16:22:01 by lhageman      ########   odam.nl         */
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
	while (middle > 60)
	{
		middle /= 2;
	}
	while (middle > 49 && list->total_len < 200)
	{
		middle /= 2;
	}
	if (list->len_a % 2 == 0)
		middle -= 1;
	number = list->arr_a[middle];
	return (number);
}

void	ft_list_copy(t_arrlist *list, t_arrlist *copy)
{
	int i;

	i = 0;
	copy->len_a = list->len_a;
	copy->len_b = list->len_b;
	copy->arr_a = malloc(sizeof(int) * (list->len_a + list->len_b));
	copy->arr_b = malloc(sizeof(int) * (list->len_a + list->len_b));
	copy->total_len = list->total_len;
	while (i < list->len_a && list->len_a > 0)
	{
		copy->arr_a[i] = list->arr_a[i];
		i++;
	}
	i = 0;
	while (i < list->len_b && list->len_b > 0)
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
	ft_free_arrlist(list);
	return (middle);
}
