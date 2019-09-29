/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_valid_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 14:04:11 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/29 20:21:50 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int		ft_check_int(char *str)
{
	int i;
	int s;
	int	r;

	r = 0;
	i = 0;
	s = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (r > 214748364 || r < -214748364 || (r == 214748364 &&\
		((str[i] == '8' && s != -1) || (str[i + 1] >= '0' &&\
		str[i + 1] >= '9') || (str[i] > '8'))))
			return (-1);
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (0);
}

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
		if (ft_is_asciinum(str[i]) == 0 || str[i] == '-' || str[i] == '+')
		{
			if ((str[i] == '-' || str[i] == '+') && i > 0)
				return (-1);
			i++;
		}
		else
			return (-1);
	}
	if (i == 1 && (str[0] == '-' || str[0] == '+'))
		return (-1);
	if (ft_check_int(str) == -1)
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
