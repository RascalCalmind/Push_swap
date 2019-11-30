/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_file.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 15:41:29 by lhageman       #+#    #+#                */
/*   Updated: 2019/11/24 20:04:13 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"
#include <fcntl.h>

int		ft_make_array(char *str, char **arr)
{
	int i;

	i = 0;
	arr = ft_strsplit(str, ' ');
	if (!arr)
	{
		ft_dprintf(2, "Error\n");
		return (-1);
	}
	//ft_print_char_array(arr);
	while (arr[i])
	{
		if (ft_valid_input(arr[i]) == -1)
		{
			free(arr);
			ft_dprintf(2, "Error\n");
			return (-1);
		}
		i++;
	}
	return (i);
}

int		ft_open_file(char *file, char *numbers, char **arr)
{
	int ret;
	int fd;

	ret = 0;
	fd = open(file, O_RDONLY);
	ft_printf("fd:[%i]\n", fd);
	if (fd == -1)
	{
		ft_dprintf(2, "Error\n");
		return (-1);
	}
	ret = get_next_line(fd, &numbers);
	ft_printf("ret:[%i]\n", ret);
	if (ret <= 0)
	{
		free(numbers);
		close(fd);
		ft_dprintf(2, "Error\n");
		return (-1);
	}
	ret = ft_make_array(numbers, arr);
	if (ret == -1)
	{
		free(numbers);
		close(fd);
		ft_dprintf(2, "Error\n");
		return (-1);
	}
	return (ret);
}

int		ft_check_file(char *file)
{
	int		ret;
	char	*numbers;
	char	**arr;

	numbers = malloc(sizeof(char) * 10 + 1);
	if (!numbers)
	{
		ft_dprintf(2, "Error\n");
		return (-1);
	}
	arr = NULL;
	// if (fd == -1)
	// {
	// 	ft_dprintf(2, "Error\n");
	// 	return (-1);
	// }
	// ret = get_next_line(fd, &numbers);
	// ft_printf("ret:[%i]\n", ret);
	// if (ret <= 0)
	// {
	// 	free(numbers);
	// 	close(fd);
	// 	ft_dprintf(2, "Error\n");
	// 	return (-1);
	// }
	// ret = ft_make_array(numbers, arr);
	// if (ret == -1)
	// {
	// 	free(numbers);
	// 	close(fd);
	// 	ft_dprintf(2, "Error\n");
	// 	return (-1);
	// }
	ret = ft_open_file(file, numbers, arr);
	if (ret == -1)
		return (-1);
	free(numbers);
	free(arr);
	// close(fd);
	return (0);
}
