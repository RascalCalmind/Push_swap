/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_store_file.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/29 18:21:40 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/29 18:32:51 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"

int		ft_find_doubles(t_arrlist *list)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < list->len_a)
	{
		while (j < list->len_a)
		{
			if (list->arr_a[i] == list->arr_a[j])
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int		ft_store_int(char *str)
{
	int arr_value;

	arr_value = ft_atoi(str);
	return (arr_value);
}

int		ft_allocate_fstore(t_arrlist *arlst, t_fflag_list *flist)
{
	int len;

	len = flist->ret;
	arlst->arr_a = malloc(sizeof(int) * len + 1);
	if (!arlst->arr_a)
		return (ft_free_arrlist(arlst));
	arlst->arr_b = malloc(sizeof(int) * len + 1);
	if (!arlst->arr_b)
		return (ft_free_arrlist(arlst));
	ft_set_int_array_list(arlst, len);
	while (len > 0)
	{
		arlst->arr_a[len - 1] = ft_store_int(flist->arr[len - 1]);
		len -= 1;
	}
	return (0);
}

int		ft_double_and_free(t_arrlist *arlst, t_fflag_list *flist, char *numbers)
{
	ft_allocate_fstore(arlst, flist);
	arlst->len_a = flist->ret;
	if (ft_find_doubles(arlst) == -1)
	{
		ft_free_arrlist(arlst);
		ft_dprintf(2, "Error\n");
		return (ft_free_flist(flist));
	}
	free(numbers);
	ft_free_flist(flist);
	return (0);
}

int		ft_store_file(char **argv, t_arrlist *arlst, int len)
{
	int				ret;
	char			*numbers;
	char			**arr;
	t_fflag_list	*flist;

	flist = malloc(sizeof(t_fflag_list));
	ft_set_flist(flist);
	if (flist == NULL)
		return (-1);
	numbers = malloc(sizeof(char) * 10 + 1);
	if (len > 2)
	{
		ft_dprintf(2, "Error\n");
		return (ft_free_arrlist(arlst));
	}
	arr = NULL;
	ret = ft_open_file(argv[2], numbers, arr, flist);
	if (ret == -1 || flist->arr == NULL)
		return (-1);
	ret = ft_double_and_free(arlst, flist, numbers);
	if (ret == -1)
		return (-1);
	return (0);
}
