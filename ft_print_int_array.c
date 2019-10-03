/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_int_array.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 17:14:36 by lhageman       #+#    #+#                */
/*   Updated: 2019/10/03 15:25:28 by lhageman      ########   odam.nl         */
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

void		ft_print_two_int_array(int *array1, int *array2, int len)
{
	int i;
	char *str;

	i = 0;
	str = "-----------------------------------------------\n";
	while (i < len)
	{
		if (i == 0)
			ft_printf("%s", str);
		if(array1[i] && array2[i] && array1[i] <= 9999999 && array1[i] >= -999999)
			ft_printf("|\t%i\t\t|\t%i\n", array1[i], array2[i]);
		else if (array1[i] && array2[i])
			ft_printf("|\t%i\t|\t%i\n", array1[i], array2[i]);
		else if(array1[i] && !array2[i] && array1[i] <= 9999999 && array1[i] >= -999999)
			ft_printf("|\t%i\t\t|\n", array1[i]);
		else if (array1[i] && !array2[i])
			ft_printf("|\t%i\t|\n", array1[i]);
		else if (!array1[i] && array2[i])
			ft_printf("|\t\t\t|\t%i\n", array2[i]);
		i++;
	}
	ft_printf("|\t\t\t|\n%s|  stack a\t\t|  stack b\n%s", str, str);
}
