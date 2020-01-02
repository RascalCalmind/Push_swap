/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 15:52:53 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/02 20:16:34 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int		ft_sa(t_arrlist *list)
{
	int temp;

	temp = 0;
	if (list->len_a > 1)
	{
		temp = list->arr_a[0];
		list->arr_a[0] = list->arr_a[1];
		list->arr_a[1] = temp;
		if (list->prog == 1)
			ft_buffer_add(list->buf, "sa\n");
		if (list->vflag == 1)
			ft_stacks_to_buf(list);
	}
	return (0);
}

int		ft_sb(t_arrlist *list)
{
	int temp;

	temp = 0;
	if (list->len_b > 1)
	{
		temp = list->arr_b[0];
		list->arr_b[0] = list->arr_b[1];
		list->arr_b[1] = temp;
		if (list->prog == 1)
			ft_buffer_add(list->buf, "sb\n");
		if (list->vflag == 1)
			ft_stacks_to_buf(list);
	}
	return (0);
}

int		ft_ss(t_arrlist *list)
{
	if (list->prog == 1)
		list->prog = 2;
	if (list->vflag == 1)
		list->vflag = 2;
	ft_sa(list);
	ft_sb(list);
	if (list->prog == 2)
	{
		ft_buffer_add(list->buf, "ss\n");
		list->prog = 1;
	}
	if (list->vflag == 2)
	{
		ft_stacks_to_buf(list);
		list->vflag = 1;
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
		ft_ss(list);
	else
		ft_push(str, list);
	return (0);
}
