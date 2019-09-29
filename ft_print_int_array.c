/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_int_array.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 17:14:36 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/28 22:55:02 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void		ft_print_int_array(int *array, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("%i\n", array[i]);
		i++;
	}
	ft_printf("\n-\na\n");
}
