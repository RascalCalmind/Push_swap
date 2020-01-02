/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_file.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 15:41:29 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/02 20:20:16 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"
#include <fcntl.h>

int			ft_make_array(char *str, char **arr, t_fflag_list *flist)
{
	int i;

	i = 0;
	arr = ft_strsplit(str, ' ');
	free(str);
	if (!arr)
		return (ft_quick_error_return());
	while (arr[i])
	{
		if (ft_valid_input(arr[i]) == -1)
		{
			free(arr);
			return (ft_quick_error_return());
		}
		i++;
	}
	flist->ret = i;
	flist->arr = arr;
	return (i);
}

static int	ft_quick_error(char *str, int fd)
{
	free(str);
	close(fd);
	return (ft_quick_error_return());
}

int			ft_open_file(char *file, char *numbers, char **arr,\
t_fflag_list *flist)
{
	int ret;
	int fd;

	ret = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_quick_error_return());
	ret = get_next_line(fd, &numbers);
	if (ret <= 0)
		return (ft_quick_error(numbers, fd));
	ret = ft_make_array(numbers, arr, flist);
	if (ret == -1)
		return (ft_quick_error(numbers, fd));
	flist->fd = fd;
	close(fd);
	return (ret);
}

int			ft_check_file(char *file)
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
		return (ft_quick_error_return());
	arr = NULL;
	ret = ft_open_file(file, numbers, arr, flist);
	if (ret == -1)
		return (-1);
	free(numbers);
	free(arr);
	ft_free_flist(flist);
	return (0);
}
