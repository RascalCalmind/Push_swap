/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 15:52:53 by lhageman       #+#    #+#                */
/*   Updated: 2019/10/03 18:15:12 by lhageman      ########   odam.nl         */
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

int		ft_ss(t_arrlist *list)
{
	ft_sa(list);
	ft_sb(list);
	return (0);
}

int		ft_swap(char *str, t_arrlist *list)
{
	if ((ft_strcmp(str, "sa")) == 0)
		ft_sa(list);
	else if ((ft_strcmp(str, "sb")) == 0)
		ft_sb(list);
	else if ((ft_strcmp(str, "ss")) == 0)
		ft_ss(list);
	else
		ft_push(str, list);
	if (list->vflag == 1)
		ft_print_two_int_array(list->arr_a, list->arr_b, list->len);
	return (0);
}