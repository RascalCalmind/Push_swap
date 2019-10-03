/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_reverse_rotate.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 17:57:52 by lhageman       #+#    #+#                */
/*   Updated: 2019/10/03 20:07:44 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int     ft_rra(t_arrlist *list)
{
	int temp;
	int i;
	int j;

	i = 0;
	j = 1;
	if (list->arr_a[0])
	{
		while (list->arr_a[i] && i < list->len - 1)
			i++;
		ft_printf("i in rra: %i\n", i);
		if (list->arr_a[i] == 0)
		{
			i--;
			j++;
		}
		ft_printf("i in rra: %i\n", i);
		temp = list->arr_a[i];
		ft_switch_up(list->arr_a, list->len - j);
		if (j > 1)
		{
			list->arr_a[list->len - 1] = 0;
		}
		list->arr_a[0] = temp;
	}
	return (0);
}

int		ft_rrb(t_arrlist *list)
{
	int temp;
	int i;

	i = 0;
	if (list->arr_b[0])
	{
		while (list->arr_b[i] && i < list->len - 1)
			i++;
		temp = list->arr_b[i];
		ft_switch_up(list->arr_b, list->len - 1);
		list->arr_b[0] = temp;
	}
	return (0);
}

int		ft_rrr(t_arrlist *list)
{
	ft_rra(list);
	ft_rrb(list);
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