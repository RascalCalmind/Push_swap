/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_file.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 15:41:29 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/12 19:24:24 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"
#include <fcntl.h>

int		ft_copy_arr_to_flist(char **arr, t_fflag_list *flist)
{
	int i;

	i = 0;
	if (!arr)
		return (-1);
	flist->arr = malloc(sizeof(char **) * flist->ret + 1);
	while (i <= flist->ret)
	{
		flist->arr[i] = arr[i];
		i += 1;
	}
	if (i > 0 && flist->arr != NULL)
		return (0);
	return (-1);
}

int		ft_make_array(char *str, char **arr, t_fflag_list *flist)
{
	int i;

	i = 0;
	arr = ft_strsplit(str, ' ');
	if (!arr)
	{
		ft_dprintf(2, "Error\n");
		return (-1);
	}
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
	flist->ret = i;
	i = ft_copy_arr_to_flist(arr, flist);
	return (i);
}

int		ft_open_file(char *file, char *numbers, char **arr, t_fflag_list *flist)
{
	int ret;
	int fd;

	ret = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(2, "Error\n");
		return (-1);
	}
	ret = get_next_line(fd, &numbers);
	if (ret <= 0)
	{
		free(numbers);
		close(fd);
		ft_dprintf(2, "Error\n");
		return (-1);
	}
	ret = ft_make_array(numbers, arr, flist);
	if (ret == -1)
	{
		free(numbers);
		close(fd);
		ft_dprintf(2, "Error\n");
		return (-1);
	}
	flist->fd = fd;
	close(fd);
	return (ret);
}

int		ft_check_file(char *file)
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
	if (!numbers)
	{
		ft_dprintf(2, "Error\n");
		return (-1);
	}
	arr = NULL;
	ret = ft_open_file(file, numbers, arr, flist);
	if (ret == -1)
		return (-1);
	free(numbers);
	free(arr);
	ft_free_flist(flist);
	return (0);
}
