/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_valid_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 14:04:11 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/27 14:33:56 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int		ft_is_asciinum(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (-1);
}

int		ft_valid_input(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_is_asciinum(str[i]) == 0 || str[i] == '-')
		{
			if (str[i] == '-' && i > 0)
				return (-1);
			i++;
		}
		else
			return (-1);
	}
	if (i == 1 && str[0] == '-')
		return (-1);
	return (0);
}

int		ft_check_input(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (ft_valid_input(argv[i]) == -1)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (0);
}
