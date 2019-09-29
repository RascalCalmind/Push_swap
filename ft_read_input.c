/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_input.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 18:54:58 by lhageman       #+#    #+#                */
/*   Updated: 2019/09/28 22:52:54 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

// int     ft_calc_n_len(char *str, char delim)
// {
//     int i;
//     int len;

//     i = 0;
//     len = 1;
//     while (str[i])
//     {
//         if (str[i] == delim)
//             len++;
//         i++;
//     }
//     return (len);
// }

int		ft_check_swap(char *str, int i)
{
	if (str[0] == 's')
	{
		if ((str[1] == 'a' || str[1] == 'b' || str[1] == 's') && i == 2)
			return (0);
	}
	if (str[0] == 'p')
	{
		if ((str[1] == 'a' || str[1] == 'b') && i == 2)
			return (0);
	}
	if (str[0] == 'r')
	{
		if ((str[1] == 'a' || str[1] == 'b') && i == 2)
			return (0);
		if (str[1] == 'r')
		{
			if (i == 2)
				return (0);
			if (str[2] == 'a' && i == 3)
				return (0);
		}
	}
	return (-1);
}

int		ft_read_input(void)
{
	char	ch;
	char	str[3];
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (read(STDIN_FILENO, &ch, 1) > 0)
	{
		if (ch != '\n')
		{
			if (i > 2 || i == -1)
				return (-1);
			str[i] = ch;
			i++;
		}
		if (ch == '\n')
		{
			ret = ft_check_swap(str, i);
			if (ret == -1)
				return (-1);
			//ret = ft_swap(str); //using i instead of ret will allow me to have 25 lines and catch the error? mayybe too late
			i = 0;
		}
	}
	return (0);
}
