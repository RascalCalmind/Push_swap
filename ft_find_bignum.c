/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_bignum.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 15:28:44 by lhageman       #+#    #+#                */
/*   Updated: 2019/11/30 19:09:08 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "ft_checker.h"

static int	ft_swap_two_b(t_arrlist *list, int i, int j)
{
	int temp;

	temp = list->arr_b[i];
	list->arr_b[i] = list->arr_b[j];
	list->arr_b[j] = temp;
	return (0);
}

static int	ft_bubble_sorted_b(t_arrlist *list)
{
	int i;

	i = 0;
	while (i < list->len_b - 1)
	{
		if (list->arr_b[i] > list->arr_b[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

void	ft_list_copy_b(t_arrlist *list, t_arrlist *copy)
{
	int i;

	i = 0;
	copy->len_a = list->len_a;
	copy->len_b = list->len_b;
	copy->arr_a = malloc(sizeof(int) * (list->len_a + list->len_b));
	copy->arr_b = malloc(sizeof(int) * (list->len_a + list->len_b));
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
void		ft_bubblesort_b(t_arrlist *list, t_arrlist *copy_sorted)
{
	int			i;

	ft_list_copy_b(list, copy_sorted);
	i = 0;
	while (ft_bubble_sorted_b(copy_sorted) != 0)
	{
		if (i == copy_sorted->len_b - 1)
			i = 0;
		if (copy_sorted->arr_b[i] > copy_sorted->arr_b[i + 1])
			ft_swap_two_b(copy_sorted, i, i + 1);
		if (i > 0 && copy_sorted->arr_b[i - 1] > copy_sorted->arr_b[i])
			i--;
		else
			i++;
	}
}

int		ft_which_way_b(int find, t_arrlist *list)
{
	int min;
	int max;
	int num;

	min = 0;
	max = list->len_b - 1;
	num = 0;
	while (min != max && min <= max)
	{
		if (list->arr_b[min] == find)
			return (min);
		else if (list->arr_b[max] == find)
			return ((list->len_b - max) * -1);
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

void	ft_rot_and_push(t_arrlist *list, int rot)
{
	// if (rot > 0)
	// 	rot += 1;
	// if (rot < 0)
	// 	rot -= 1;
	while (rot > 0)
	{
		ft_rb(list);
		rot--;
	}
	while (rot < 0)
	{
		ft_rrb(list);
		rot++;
	}
	if (rot == 0)
		ft_pa(list);
}

void	ft_find_bignum(t_arrlist *list)
{
	t_arrlist	*copy_sorted;
	int			rot;
	int			pos;

	copy_sorted = malloc(sizeof(t_arrlist));
	// ft_list_copy(list, copy_sorted);
	ft_bubblesort_b(list, copy_sorted);
	if (copy_sorted == NULL)
	{
		ft_printf("ohno its null\n");
		return ;
	}
	pos = copy_sorted->len_b - 1;
	rot = ft_which_way_b(copy_sorted->arr_b[pos], list);
	ft_rot_and_push(list, rot);
	// while (pos >= 0)
	// {
	// 	ft_printf("find:[%i]\n", copy_sorted->arr_b[pos]);
	// 	ft_print_stacks(list);
	// 	rot = ft_which_way_b(copy_sorted->arr_b[pos], list);
	// 	ft_printf("rot: [%i]\n");
	// 	ft_rot_and_push(list, rot);
	// 	ft_print_stacks(list);
	// 	pos -= 1;
	// }
	free (copy_sorted);
	copy_sorted = NULL;
}