/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_int_array.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 17:14:36 by lhageman       #+#    #+#                */
/*   Updated: 2019/11/11 15:40:29 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int			ft_len_stack(int len_a, int len_b)
{
	if (len_a > len_b)
		return (len_a);
	return (len_b);
}

void		ft_print_stacks(t_arrlist *list)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	str = "-----------------------------------------------\n";
	len = ft_len_stack(list->len_a, list->len_b);
	ft_printf("%s", str);
	while (i < len)
	{
		if (i < list->len_a && i < list->len_b && list->arr_a[i] <= 9999999 &&\
			list->arr_a[i] >= -999999)
			ft_printf("|\t%i\t\t|\t%i\n", list->arr_a[i], list->arr_b[i]);
		else if (i < list->len_a && i < list->len_b)
			ft_printf("|\t%i\t|\t%i\n", list->arr_a[i], list->arr_b[i]);
		else if (i < list->len_a && i >= list->len_b && list->arr_a[i] <=
					9999999 && list->arr_a[i] >= -999999)
			ft_printf("|\t%i\t\t|\n", list->arr_a[i]);
		else if (i < list->len_a && i >= list->len_b)
			ft_printf("|\t%i\t|\n", list->arr_a[i]);
		else if (i >= list->len_a && i < list->len_b)
			ft_printf("|\t\t\t|\t%i\n", list->arr_b[i]);
		i++;
	}
	ft_printf("|\t\t\t|\n%s|  stack a\t\t|  stack b\n%s\n", str, str);
}

void		ft_print_stacks_compare(t_arrlist *start, t_arrlist *finish)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	str = "-----------------------------------------------\n";
	len = ft_len_stack(start->len_a, start->len_b);
	ft_printf("%s", str);
	while (i < len)
	{
		if (i < start->len_a && start->arr_a[i] <= 9999999 &&\
			start->arr_a[i] >= -999999)
			ft_printf("|\t%i\t\t|\t%i\n", start->arr_a[i], finish->arr_a[i]);
		else if (i < start->len_a)
			ft_printf("|\t%i\t|\t%i\n", start->arr_a[i], start->arr_a[i]);
		i++;
	}
	ft_printf("|\t\t\t|\n%s|  stack start\t\t|  stack finish\n%s\n", str, str);
}