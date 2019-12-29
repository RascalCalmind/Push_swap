/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_b.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/29 18:28:01 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/29 18:35:19 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"

int	ft_swap_two_b(t_arrlist *list, int i, int j)
{
	int temp;

	temp = list->arr_b[i];
	list->arr_b[i] = list->arr_b[j];
	list->arr_b[j] = temp;
	return (0);
}

int	ft_bubble_sorted_b(t_arrlist *list)
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
