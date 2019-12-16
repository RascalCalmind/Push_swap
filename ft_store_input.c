/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_store_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 16:48:59 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/16 15:17:09 by lhageman      ########   odam.nl         */
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

int		ft_calc_len(char **argv)
{
	int len;

	len = 0;
	while (argv[len])
	{
		len++;
	}
	return (len - 1);
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

int		ft_allocate_store(t_arrlist *arlst, char **argv, int len)
{
	arlst->arr_a = malloc(sizeof(int) * len + 1);
	if (!arlst->arr_a)
		return (ft_free_arrlist(arlst));
	arlst->arr_b = malloc(sizeof(int) * len + 1);
	if (!arlst->arr_b)
		return (ft_free_arrlist(arlst));
	ft_set_int_array_list(arlst, len);
	if (arlst->vflag == 1)
		len++;
	while (len > 0)
	{
		if (ft_strcmp(argv[len], "-v") == 0)
			break ;
		if (arlst->vflag == 1)
			arlst->arr_a[len - 2] = ft_store_int(argv[len]);
		else
			arlst->arr_a[len - 1] = ft_store_int(argv[len]);
		len--;
	}
	return (0);
}

int		ft_flag_check(char **argv, t_arrlist *arlst, int len)
{
	if (ft_strcmp(argv[1], "-v") == 0 || ft_strcmp(argv[1], "-vf") == 0
	|| ft_strcmp(argv[1], "-fv") == 0)
	{
		len--;
		arlst->vflag = 1;
	}
	else
		arlst->vflag = 0;
	if (ft_strcmp(argv[1], "-f") == 0 || ft_strcmp(argv[1], "-vf") == 0
	|| ft_strcmp(argv[1], "-fv") == 0)
	{
		arlst->fflag = 1;
		len--;
	}
	else
		arlst->fflag = 0;
	return (len);
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
	if (ret == -1)
		return (-1);
	if (flist->arr == NULL)
		return (-1);
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

int		ft_store_list(char **argv, t_arrlist *arlst, int len)
{
	if (ft_allocate_store(arlst, argv, len) == -1)
		return (-1);
	arlst->len_a = ft_calc_len(argv);
	if (arlst->vflag == 1)
		arlst->len_a -= 1;
	if (ft_find_doubles(arlst) == -1)
	{
		ft_dprintf(2, "Error\n");
		return (ft_free_arrlist(arlst));
	}
	if (arlst->vflag == 1)
		ft_stacks_to_buf(arlst);
		// ft_print_stacks(arlst);
	return (0);
}

int		ft_store_input(char **argv, t_arrlist *arlst)
{
	int			len;
	int			ret;

	ret = 0;
	len = ft_calc_len(argv);
	if (len < 1)
		return (-1);
	len = ft_flag_check(argv, arlst, len);
	if (arlst->fflag == 1)
		ret = ft_store_file(argv, arlst, len);
	else
		ret = ft_store_list(argv, arlst, len);
	if (ret == -1)
		return (-1);
	arlst->total_len = arlst->len_a;
	return (0);
}
