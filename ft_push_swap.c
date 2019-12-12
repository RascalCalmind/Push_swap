/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_push_swap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lhageman <lhageman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:41:41 by lhageman       #+#    #+#                */
/*   Updated: 2019/12/12 16:25:08 by lhageman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"
#include "ft_push_swap.h"
#include <stdio.h>

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
		{
			ft_free_arrlist(arlst);
		}
		ft_list_copy(arlst, start_list);
		ret = ft_sort(arlst);
		if (arlst->vflag == 1)
			ft_print_stacks_compare(start_list, arlst);
		ft_free_arrlist(start_list);
		ft_free_arrlist(arlst);
	}
	return (0);
}
