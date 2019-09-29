/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_store_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 16:48:59 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/29 19:48:54 by lhageman      ########   odam.nl         */
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

int		*ft_store_input(char **argv)
{
	int len;
	int	*arr;

	len = ft_calc_len(argv);
	arr = malloc(sizeof(int) * len);
	if (len < 1)
		return (NULL);
	while (len > 0)
	{
		arr[len - 1] = ft_store_int(argv[len]);
		len--;
	}
	ft_print_int_array(arr, ft_calc_len(argv));
	return (arr);
}
