/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_reverse_rotate.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 17:57:52 by lhageman       #+#    #+#                */
/*   Updated: 2019/11/10 15:34:57 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int		ft_rra(t_arrlist *list)
{
	int temp;
	int j;

	j = 1;
	if (list->len_a > 1)
	{
		if (list->len_a == 2)
		{
			ft_sa(list);
			return (0);
		}
		temp = list->arr_a[list->len_a - 1];
		ft_switch_up(list->arr_a, list->len_a - j);
		if (j > 1)
		{
			list->arr_a[list->len_a - 1] = 0;
		}
		list->arr_a[0] = temp;
		if (list->prog == 1)
			ft_printf("rra\n");
		if (list->vflag == 1)
			ft_print_stacks(list);
	}
	return (0);
}

int		ft_rrb(t_arrlist *list)
{
	int temp;
	int j;

	j = 1;
	if (list->len_b > 1)
	{
		if (list->len_b == 2)
		{
			ft_sb(list);
			return (0);
		}
		temp = list->arr_b[list->len_b - 1];
		ft_switch_up(list->arr_b, list->len_b - j);
		if (j > 1)
		{
			list->arr_b[list->len_b - 1] = 0;
		}
		list->arr_b[0] = temp;
		if (list->prog == 1)
			ft_printf("rrb\n");
		if (list->vflag == 1)
			ft_print_stacks(list);
	}
	return (0);
}

int		ft_rrr(t_arrlist *list)
{
	if (list->prog == 1)
		list->prog = 2;
	if (list->vflag == 1)
		list->vflag = 2;
	ft_rra(list);
	ft_rrb(list);
	if (list->prog == 2)
	{
		ft_printf("rrr\n");
		list->prog = 1;
	}
	if (list->vflag == 2)
	{
		ft_print_stacks(list);
		list->vflag = 1;
	}
	return (0);
}

int		ft_reverse_rotate(char *str, t_arrlist *list)
{
	if ((ft_strcmp(str, "rra")) == 0)
		ft_rra(list);
	if ((ft_strcmp(str, "rrb")) == 0)
		ft_rrb(list);
	if ((ft_strcmp(str, "rrr")) == 0)
		ft_rrr(list);
	return (0);
}
