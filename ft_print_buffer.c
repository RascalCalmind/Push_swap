/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_buffer.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/29 15:01:40 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/02 17:05:18 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "ft_checker.h"

void		ft_buf_stacks_3(t_arrlist *list, int num, int i)
{
	char *str;
	char *number;

	str = "-----------------------------------------------\n";
	if (num == 4)
	{
		ft_buffer_add_stack(list->buf, "|\t\t\t|\t");
		number = ft_itoa(list->arr_b[i]);
		ft_buffer_add_stack(list->buf, number);
		ft_free_str(number);
	}
	if (num == 5)
	{
		ft_buffer_add_stack(list->buf, "|\t\t\t|\n");
		ft_buffer_add_stack(list->buf, str);
		ft_buffer_add_stack(list->buf, "|  stack a\t\t|  stack b\n");
		ft_buffer_add_stack(list->buf, str);
	}
	ft_buffer_add_stack(list->buf, "\n");
}

void		ft_buf_stacks_2(t_arrlist *list, int num, int i)
{
	char *number;

	if (num == 2)
	{
		ft_buffer_add_stack(list->buf, "|\t");
		number = ft_itoa(list->arr_a[i]);
		ft_buffer_add_stack(list->buf, number);
		ft_free_str(number);
		ft_buffer_add_stack(list->buf, "\t\t|");
	}
	if (num == 3)
	{
		ft_printf("|\t%i\t|\n", list->arr_a[i]);
		ft_buffer_add_stack(list->buf, "|\t");
		number = ft_itoa(list->arr_a[i]);
		ft_buffer_add_stack(list->buf, number);
		ft_free_str(number);
		ft_buffer_add_stack(list->buf, "\t|");
	}
	ft_buf_stacks_3(list, num, i);
}

void		ft_buf_stacks(t_arrlist *list, int num, int i)
{
	char *number;

	if (num == 0)
	{
		ft_buffer_add_stack(list->buf, "|\t");
		number = ft_itoa(list->arr_a[i]);
		ft_buffer_add_stack(list->buf, number);
		ft_free_str(number);
		ft_buffer_add_stack(list->buf, "\t\t|\t");
		number = ft_itoa(list->arr_b[i]);
		ft_buffer_add_stack(list->buf, number);
		ft_free_str(number);
	}
	if (num == 1)
	{
		ft_buffer_add_stack(list->buf, "|\t");
		number = ft_itoa(list->arr_a[i]);
		ft_buffer_add_stack(list->buf, number);
		ft_free_str(number);
		ft_buffer_add_stack(list->buf, "\t|\t");
		number = ft_itoa(list->arr_b[i]);
		ft_buffer_add_stack(list->buf, number);
		ft_free_str(number);
	}
	ft_buf_stacks_2(list, num, i);
}

void		ft_stacks_to_buf(t_arrlist *list)
{
	int		i;
	char	*str;
	int		len;

	i = 0;
	str = "-----------------------------------------------\n";
	len = ft_len_stack(list->len_a, list->len_b);
	ft_buffer_add_stack(list->buf, str);
	while (i < len)
	{
		if (i < list->len_a && i < list->len_b && list->arr_a[i] <= 9999999 &&\
			list->arr_a[i] >= -999999)
			ft_buf_stacks(list, 0, i);
		else if (i < list->len_a && i < list->len_b)
			ft_buf_stacks(list, 1, i);
		else if (i < list->len_a && i >= list->len_b && list->arr_a[i] <=
					9999999 && list->arr_a[i] >= -999999)
			ft_buf_stacks(list, 2, i);
		else if (i < list->len_a && i >= list->len_b)
			ft_buf_stacks(list, 3, i);
		else if (i >= list->len_a && i < list->len_b)
			ft_buf_stacks(list, 4, i);
		i++;
	}
	ft_buf_stacks(list, 5, i);
}

void		ft_buffer_add_stack(t_buffer *buf, char *str)
{
	ft_string_to_buffer(buf, str, ft_strlen(str));
}
