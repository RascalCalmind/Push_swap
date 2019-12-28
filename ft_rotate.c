/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 17:43:26 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/28 14:17:31 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int		ft_ra(t_arrlist *list)
{
	int temp;
	int j;

	temp = 0;
	j = 0;
	if (list->len_a > 1)
	{
		temp = list->arr_a[0];
		ft_switch_down(1, list->len_a, list->arr_a);
		while (list->arr_a[j])
			j++;
		list->arr_a[j] = temp;
		if (list->prog == 1)
			ft_buffer_add(list->buf, "ra\n");
		if (list->vflag == 1)
			ft_stacks_to_buf(list);
	}
	return (0);
}

int		ft_rb(t_arrlist *list)
{
	int temp;
	int j;

	temp = 0;
	j = 0;
	if (list->len_b > 1)
	{
		temp = list->arr_b[0];
		ft_switch_down(1, list->len_b, list->arr_b);
		while (list->arr_b[j])
			j++;
		list->arr_b[j] = temp;
		if (list->prog == 1)
			ft_buffer_add(list->buf, "rb\n");
		if (list->vflag == 1)
			ft_stacks_to_buf(list);
	}
	return (0);
}

int		ft_rr(t_arrlist *list)
{
	if (list->prog == 1)
		list->prog = 2;
	if (list->vflag == 1)
		list->vflag = 2;
	ft_ra(list);
	ft_rb(list);
	if (list->prog == 2)
	{
		ft_buffer_add(list->buf, "rr\n");
		list->prog = 1;
	}
	if (list->vflag == 2)
	{
		ft_stacks_to_buf(list);
		list->vflag = 1;
	}
	return (0);
}

int		ft_rotate(char *str, t_arrlist *list)
{
	if ((ft_strcmp(str, "ra")) == 0)
		ft_ra(list);
	else if ((ft_strcmp(str, "rb")) == 0)
		ft_rb(list);
	else if ((ft_strcmp(str, "rr")) == 0)
		ft_rr(list);
	else
		ft_reverse_rotate(str, list);
	return (0);
}
