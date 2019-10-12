/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 14:53:45 by lhageman       #+#    #+#                */
/*   Updated: 2019/10/12 16:03:57 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ft_switch_down(int i, int len, int *arr)
{
	while (i <= len)
	{
		arr[i - 1] = arr[i];
		i++;
	}
	arr[i - 2] = 0;
}

void	ft_switch_up(int *arr, int len)
{
	int j;

	j = 0;
	while (arr[j] && j < len)
		j++;
	while (j >= 0)
	{
		arr[j + 1] = arr[j];
		arr[j] = 0;
		j--;
	}
}

int		ft_pa(t_arrlist *list)
{
	int i;

	i = 1;
	if (list->arr_b[0])
	{
		if (list->len_a < 1)
		{
			list->arr_a[0] = list->arr_b[0];
			ft_switch_down(i, list->len_b, list->arr_b);
		}
		else
		{
			ft_switch_up(list->arr_a, list->len_a);
			list->arr_a[0] = list->arr_b[0];
			ft_switch_down(i, list->len_b, list->arr_b);
		}
		list->len_b--;
		list->len_a++;
		if (list->len_b == 0)
		{
			list->arr_b[0] = 0;
		}
	}
	return (0);
}

int		ft_pb(t_arrlist *list)
{
	int i;

	i = 1;
	if (list->arr_a[0])
	{
		if (list->len_b < 1)
		{
			list->arr_b[0] = list->arr_a[0];
			ft_switch_down(i, list->len_a, list->arr_a);
		}
		else
		{
			ft_switch_up(list->arr_b, list->len_b);
			list->arr_b[0] = list->arr_a[0];
			ft_switch_down(i, list->len_a, list->arr_a);
		}
		list->len_b++;
		list->len_a--;
		if (list->len_a == 0)
		{
			list->arr_a[0] = 0;
		}
	}
	return (0);
}

int		ft_push(char *str, t_arrlist *list)
{
	if ((ft_strcmp(str, "pa")) == 0)
		ft_pa(list);
	if ((ft_strcmp(str, "pb")) == 0)
		ft_pb(list);
	else
		ft_rotate(str, list);
	return (0);
}
