/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 17:43:26 by lhageman       #+#    #+#                */
/*   Updated: 2019/10/03 18:53:01 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int		ft_ra(t_arrlist *list)
{
	int temp;
	int j;

	temp = 0;
	j = 0;
	if (list->arr_a[0])
	{
		temp = list->arr_a[0];
		ft_switch_down(1, list->len, list->arr_a);
		while (list->arr_a[j])
			j++;
		list->arr_a[j] = temp;
	}
	return (0);
}

int		ft_rb(t_arrlist *list)
{
	int temp;
	int j;

	temp = 0;
	j = 0;
	if (list->arr_b[0])
	{
		temp = list->arr_b[0];
		ft_switch_down(1, list->len, list->arr_b);
		while (list->arr_b[j])
			j++;
		list->arr_b[j] = temp;
	}
	return (0);
}

int		ft_rr(t_arrlist *list)
{
	ft_ra(list);
	ft_rb(list);
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