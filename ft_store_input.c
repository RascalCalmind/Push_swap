/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_store_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 16:48:59 by lhageman       #+#    #+#                */
/*   Updated: 2019/10/06 15:26:09 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int		ft_calc_len(char **argv)
{
	int len;

	len = 1;
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

int		ft_store_input(char **argv, t_arrlist *arlst)
{
	int			len;

	len = ft_calc_len(argv);
	if (len < 1)
		return (-1);
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		len--;
		arlst->vflag = 1;
	}
	else
		arlst->vflag = 0;
	arlst->arr_a = malloc(sizeof(int) * len + 1);
	if (!arlst->arr_a)
	{
		free(arlst);
		arlst = NULL;
		return (-1);
	}
	arlst->arr_b = malloc(sizeof(int) * len + 1);
	if (!arlst->arr_b)
	{
		free(arlst->arr_a);
		arlst->arr_a = NULL;
		return (-1);
	}
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
	arlst->len_a = ft_calc_len(argv);
	if (arlst->vflag == 1)
		arlst->len_a -= 1;
	ft_print_two_int_array(arlst->arr_a, arlst->arr_b, arlst->len_a);
	return (0);
}
