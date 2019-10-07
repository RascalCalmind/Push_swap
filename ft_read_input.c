/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_input.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 18:54:58 by lhageman       #+#    #+#                */
/*   Updated: 2019/10/07 15:36:50 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

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
			if ((str[2] == 'a' || str[2] == 'b' || str[2] == 'r') && i == 3)
				return (0);
		}
	}
	return (-1);
}

int		ft_read_input(t_arrlist *list)
{
	char	ch;
	char	*str;
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	str = ft_strnew(3);
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
			if (str[0] == '\0')
			{
				free(str);
				return (0);
			}
			ret = ft_check_swap(str, i);
			if (ret == -1)
			{
				free(str);
				return (-1);
			}
			i = ft_swap(str, list);
			ft_strclr(str);
		}
	}
	free(str);
	return (0);
}
