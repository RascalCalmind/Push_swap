/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_checker.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:41:33 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/02 20:06:03 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include <stdio.h>

int		ft_free_check(t_read_check *rc, int i)
{
	if (rc)
	{
		free(rc);
		rc = NULL;
	}
	return (i);
}

void	ft_free_buffers(t_buffer *buf)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
}

int		ft_free_quick(t_arrlist *list)
{
	ft_free_buffers(list->buf);
	ft_free_arrlist(list);
	return (ft_quick_error_return());
}

void	ft_finish_free(t_arrlist *list)
{
	ft_check_stack(list);
	ft_free_buffers(list->buf);
	ft_free_arrlist(list);
}

int		main(int argc, char **argv)
{
	int			ret;
	t_arrlist	*arlst;

	if (argc > 1)
	{
		ret = ft_check_input(argv);
		if (ret == -1)
			return (-1);
		arlst = malloc(sizeof(t_arrlist));
		if (!arlst)
			return (ft_free_quick(arlst));
		ret = ft_store_input(argv, arlst);
		if (ret == -1)
			return (ft_free_quick(arlst));
		if (arlst->fflag == 1 || (arlst->vflag == 0 && arlst->fflag == 0))
			ft_print_stacks(arlst);
		if (arlst->buf)
			ft_printbuffer(arlst->buf);
		ret = ft_read_input(arlst);
		if (ret == -1)
			return (ft_free_quick(arlst));
		ft_finish_free(arlst);
	}
	return (0);
}
