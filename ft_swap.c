/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 15:52:53 by lhageman       #+#    #+#                */
/*   Updated: 2019/10/06 15:25:24 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int		ft_sa(t_arrlist *list)
{
	int temp;

	temp = 0;
	if (list->arr_a[0] && list->arr_a[1])
	{
		temp = list->arr_a[0];
		list->arr_a[0] = list->arr_a[1];
		list->arr_a[1] = temp;
	}
	return (0);
}

int		ft_sb(t_arrlist *list)
{
	int temp;

	temp = 0;
	if (list->arr_b[0] && list->arr_b[1])
	{
		temp = list->arr_b[0];
		list->arr_b[0] = list->arr_b[1];
		list->arr_b[1] = temp;
	}
	return (0);
}

int		ft_swap(char *str, t_arrlist *list)
{
	int biggestlen;

	biggestlen = 0;
	if ((ft_strcmp(str, "sa")) == 0)
		ft_sa(list);
	else if ((ft_strcmp(str, "sb")) == 0)
		ft_sb(list);
	else if ((ft_strcmp(str, "ss")) == 0)
	{
		ft_sa(list);
		ft_sb(list);
	}
	else
		ft_push(str, list);
	if (list->len_a > list->len_b)
		biggestlen = list->len_a;
	else
		biggestlen = list->len_b;
	if (list->vflag == 1)
		ft_print_two_int_array(list->arr_a, list->arr_b, biggestlen);
	return (0);
}