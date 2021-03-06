/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_swap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:41:41 by lhageman       #+#    #+#                */
/*   Updated: 2020/01/02 17:10:33 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"
#include <stdio.h>

void	ft_finish_up(t_arrlist *arlst, t_arrlist *start_list)
{
	arlst->buf->str = NULL;
	ft_printbuffer(arlst->buf);
	if (arlst->vflag == 1)
		ft_print_stacks_compare(start_list, arlst);
	ft_printf("\nAmount of calculations: %i\n\n", arlst->buf->count);
	if (arlst->buf)
	{
		free(arlst->buf);
	}
	ft_free_arrlist(start_list);
	ft_free_arrlist(arlst);
}

int		ft_quick_free_error(t_arrlist *arlst)
{
	ft_free_arrlist(arlst);
	return (-1);
}

int		main(int argc, char **argv)
{
	int			ret;
	t_arrlist	*arlst;
	t_arrlist	*start_list;

	if (argc > 1)
	{
		ret = ft_check_input(argv);
		if (ret == -1)
			return (-1);
		arlst = malloc(sizeof(t_arrlist));
		if (!arlst)
			return (-1);
		ret = ft_store_input(argv, arlst);
		arlst->prog = 1;
		if (ret == -1)
			return (-1);
		start_list = malloc(sizeof(t_arrlist));
		if (!start_list)
			return (ft_quick_free_error(arlst));
		ft_list_copy(arlst, start_list);
		ret = ft_sort(arlst);
		ft_finish_up(arlst, start_list);
	}
	return (0);
}
