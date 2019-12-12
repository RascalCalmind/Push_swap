/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_set_array.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 17:44:42 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/12 17:12:19 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	ft_set_int_array_list(t_arrlist *list, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		list->arr_a[i] = 0;
		list->arr_b[i] = 0;
		i++;
	}
	list->len_a = len;
	list->len_b = 0;
	list->prog = 0;
}

void	ft_free_arrlist(t_arrlist *list)
{
	if (list->arr_a)
	{
		free(list->arr_a);
		list->arr_a = NULL;
	}
	if (list->arr_b)
	{
		free(list->arr_b);
		list->arr_b = NULL;
	}
	if (list)
	{
		free(list);
		list = NULL;
	}
}

void	ft_set_flist(t_fflag_list *list)
{
	char **arr;

	arr = NULL;
	list->fd = 0;
	list->arr = arr;
	list->ret = 0;
}

void	ft_free_flist(t_fflag_list *list)
{
	free(list->arr);
	free(list);
}